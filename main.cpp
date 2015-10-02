#include <QApplication>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QTextCodec>
#include "pdf.h"
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("172.16.63.111");
         db.setDatabaseName("dbtvieuxNewWorld");
         db.setUserName("tvieux");
         db.setPassword("OsjH12RRc");
         bool ok = db.open();

    QSqlQuery reqClient("select noUtil, nom, prenom, email, codePostal from utilisateur");
    while(reqClient.next())
    {
        //Recupération des données necessaires
        QString numClient = reqClient.value(0).toString();
        QString nomClient = reqClient.value(1).toString();
        QString prenomClient = reqClient.value(2).toString();
        QString emailClient = reqClient.value(3).toString();
        QString cpClient = reqClient.value(4).toString();

        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

        QPrinter printer(QPrinter::HighResolution);
        printer.setFullPage(QPrinter::A4);
        printer.setOutputFormat(QPrinter::NativeFormat);
        printer.setOutputFileName("catalogue"+numClient+".pdf");
        QPainter painter;
        painter.begin(&printer);

        //le titre
        QColor couleurTitre(115, 8, 0);
        painter.setPen(couleurTitre);
        QFont fontTitrePdf("Tahoma",30);
        fontTitrePdf.setBold(true);
        painter.setFont(fontTitrePdf);
        QString titrePdf = "Catalogue New World";
        painter.drawText(300,850,titrePdf);

        //le sous-titre
        QFont maPolice("Tahoma",15);
        maPolice.setBold(false);
        painter.setFont(maPolice);
        QString resum = "Votre catalogue de produits.";
        painter.drawText(300,1200,resum);

        //le logo
        QPixmap logo("logo.jpg");
        painter.drawPixmap(7600,10,1500,1500,logo);

        //affichage des infos client
        QColor colorInfoClient(0,0,0);
        painter.setPen(colorInfoClient);
        QString clientTitre = "Informations Client :";
        painter.drawText(300,1700,clientTitre);

        QFont infoClient("Tahoma",11);
        painter.setFont(infoClient);
        QString nom = "Nom : "+nomClient+" "+prenomClient;
        painter.drawText(300,2000,nom);
        QString codeCP = "Code postal : "+cpClient;
        painter.drawText(300,2200,codeCP);
        QString email = "Adresse email : "+emailClient;
        painter.drawText(300,2400,email);

        QSqlQuery reqFavMag("select no,libelle,activite from pointDeVente where no="+numClient);
        while(reqFavMag.next())
        {
            QString numMag = reqFavMag.value(0).toString();
            QString libMag = reqFavMag.value(1).toString();
            QString actMag = reqFavMag.value(2).toString();

            QString magFav = "Magasin(s) favori(s) : "+libMag;
            painter.drawText(300,2700,magFav);
            QString magAct = "Activité : "+actMag;
            painter.drawText(300,2900,magAct);
        }

        //impression
        painter.end();
    } //fin du pour chaque client
    return 0;
}


