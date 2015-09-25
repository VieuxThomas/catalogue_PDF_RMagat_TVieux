#include "connexion.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <iostream>
#include <QTextStream>

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
             cout<<"connexion etablie"<<endl;

             QSqlQuery maxR;
             maxR.prepare("select max(noUtil)+1 from utilisateur");
             maxR.exec();
             maxR.first();
             int max=maxR.value(0).toInt();

             for (int compteur=0;compteur<max;compteur++)
             {

             QSqlQuery requeteUtilisateur;
             requeteUtilisateur.prepare("select noUtil,nom,codePostal from utilisateur where noUtil="+QString::number(compteur)+"");
             requeteUtilisateur.exec();
             requeteUtilisateur.first();
             QString noUtil=requeteUtilisateur.value(1).toString();
             QString CP=requeteUtilisateur.value(2).toString();

             QTextStream out(stdout);
             out <<"Nom : "<< QString(noUtil)<<endl;
             out <<"Prenom : "<< QString(CP)<<endl;

             QSqlQuery nbFav;
             nbFav.prepare("select count(*) from QAO where noUtil="+QString::number(compteur)+"");
             nbFav.exec();
             nbFav.first();
             int nbFavo=nbFav.value(0).toInt();



             for (int compteur1=1;compteur1<nbFavo+1;compteur1++)
             {

                 QSqlQuery QAO;
                 QAO.prepare("select noPDV from QAO where noUtil="+QString::number(compteur)+" limit "+QString::number(compteur1)+"");
                 QAO.exec();
                 QAO.last();

                 int nb=QAO.value(0).toInt();


                 QSqlQuery nomMag;
                 nomMag.prepare("select libelle from pointDeVente where no="+QString::number(nb)+"");
                 nomMag.exec();
                 nomMag.first();
                 QString nomMagasin=nomMag.value(0).toString();

                 out<<"Magasin n°"<<compteur1<<" : "<<QString(nomMagasin)<<endl;

             }
             out<<endl;
             out<<endl;




            }



         }

}

