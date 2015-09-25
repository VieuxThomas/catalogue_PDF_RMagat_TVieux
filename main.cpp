#include <QApplication>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include "pdf.h"
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPrinter printer(QPrinter::HighResolution);
    connexion maConnexion;
    maConnexion.connexionALaBase();
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFormat(QPrinter::NativeFormat);
    printer.setOutputFileName("catalogue.pdf");
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


    //Liste des produits du catalogue


    //impression
    painter.end();
    return 0;
}


