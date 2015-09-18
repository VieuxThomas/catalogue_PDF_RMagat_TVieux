#include "connexion.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <iostream>

using namespace std;

connexion::connexion()
{

}

void connexion::connexionALaBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    maBase=new QSqlDatabase(db);
    maBase->setHostName("172.16.63.111");
         maBase->setDatabaseName("dbtvieuxNewWorld");
         maBase->setUserName("tvieux");
         maBase->setPassword("OsjH12RRc");
         bool ok = maBase->open();
         if(!ok)
         {
             cout<<"New World BackOffice, la connexion a la base de donnee a echouer \n Veuillez verifier que le service mysql est lancer sur localhost"<<endl;
         }
         else
         {
             cout<<"connexion etablie";
         }

}

