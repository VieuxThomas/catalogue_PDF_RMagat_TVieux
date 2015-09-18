#include <QApplication>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
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
    painter.setFont(QFont("Tahoma",30));
    QString nomPdf = "Catalogue New World";
    painter.drawText(300,100,nomPdf);
    painter.setFont(QFont("Tahoma",15));
    QString resum = "Votre catalogue de produits.";
    painter.drawText(300,400,resum);
    //impression
    painter.end();
    return 0;
}


