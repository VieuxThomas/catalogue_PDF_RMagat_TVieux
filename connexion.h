#ifndef CONNEXION_H
#define CONNEXION_H

#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QSqlRelationalDelegate>
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class connexion
{
private:
    QSqlDatabase * maBase;
    Ui::MainWindow *ui;
public:
    connexion();
    void connexionALaBase();

};

#endif // CONNEXION_H
