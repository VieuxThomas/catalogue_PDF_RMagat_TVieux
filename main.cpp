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
    painter.setFont(QFont("Tahoma",8));
    painter.drawText(200,200,"HELOOOO");
    painter.end();
    return 0;
}


