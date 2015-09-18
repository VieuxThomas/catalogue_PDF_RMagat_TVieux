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
    maBase->setHostName("localhost");
         maBase->setDatabaseName("NewWorld");
         maBase->setUserName("tvieux");
         maBase->setPassword("ini01");
         bool ok = maBase->open();
         if(!ok)
         {
             cout<<"New World BackOffice, la connexion a la base de donnee a echouer \n Veuillez verifier que le service mysql est lancer sur localhost";
         }
         else
         {
             cout<<"connexion etablie";
         }

}

