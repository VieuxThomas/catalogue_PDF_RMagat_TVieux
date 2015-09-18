#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    return a.exec();
}

#include "pdf.h"

/**
 * @author robin magat
 * @file pdf.cpp
 * @date 11/09/2015
 * @brief toutes les fonctions et constructeurs
 */

#include <QApplication>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>


/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD



=======
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFormat(QPrinter::NativeFormat);
    printer.setOutputFileName("catalogue.pdf");
    QPainter painter;
    painter.begin(&printer);
    painter.setFont(QFont("Tahoma",8));
    painter.drawText(200,200,"HELOOOO");
    painter.end();

>>>>>>> 0bba770fa360ce6be449a1f3522e2cf90fe7cd04
    return 0;
}

