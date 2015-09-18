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
    painter.drawText(300,900,nomPdf);
    painter.end();

    QPainter painter2;
    painter2.begin(&printer);
    painter2.setFont(QFont("Tahoma",15));
    QString resum = "Votre catalogue de produits.";
    painter2.drawText(300,1200,resum);
    painter2.end();
    return 0;
}


