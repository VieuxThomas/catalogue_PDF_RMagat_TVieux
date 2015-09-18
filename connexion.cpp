#include "connexion.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <iostream>

using namespace std;
void connection::connection()
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    maBase=new QSqlDatabase(db);
    maBase->setHostName("localhost");
         maBase->setDatabaseName("NewWorld");
         maBase->setUserName("tvieux");
         maBase->setPassword("ini01");
         bool ok = maBase->open();
         if(!ok)
         {
             QMessageBox::warning(this,"New World BackOffice","la connexion a la base de donnée a echouer \n Veuillez verifier que le service mysql est lancer sur localhost",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
         }
         else
         {
             QMessageBox::warning(this,"connexion établie",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
         }

}

