#include "EditImpl.h"

#include <QMessageBox>
//
EditImpl::EditImpl(FCxml * x,int n, QWidget * parent, Qt::WFlags f) : QDialog(parent, f)
{
	setupUi(this);
	this->setModal(true);
	
	//connect(buttonBox,SIGNAL(accepted()),this,SLOT(acc()));
	//connect(buttonBox,SIGNAL(rejected()),this,SLOT(rej()));
	
	//titre->setText(QString("%1").arg(n));
	
	this->num = n;
	this->xmlDoc = x;
	
	loadItem();
}

void EditImpl::loadItem()
{
	QStringList r;
	
	r = xmlDoc->lireX(num);
	if(r.size()==2)
	{
		titre->setText(r.at(0));
		texte->setPlainText(r.at(1)); // FIXME, verfifier qu'y en a bien 2 sinon crash	
	}
	else
		titre->setText("Error in the structur of the XML file !");
}

void EditImpl::on_buttonBox_accepted()
{
	//qDebug("auto_connect_ok");
	xmlDoc->writeX(num,titre->text(),texte->toPlainText());
}

void EditImpl::on_buttonBox_rejected()
{
	
}
