#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QSettings>
#include "directorydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateDirs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDirs()
{
    QSettings settings("andysbaran", "finred");
 //   bindir = settings.value("dirs/binary").toString();
 //   caldir = settings.value("dirs/calibration").toString();
 //   photdir = settings.value("dirs/photometry").toString();
 //   fourierdir = settings.value("dirs/fourier").toString();
}

void MainWindow::on_biaslist_clicked()
{

}

void MainWindow::on_action_set_paths_triggered()
{
    DirectoryDialog myDialog(this);
    myDialog.setBinDir(bindir);
    myDialog.setCalDir(caldir);
    myDialog.setPhotDir(photdir);
    myDialog.setFourierDir(fourierdir);

    if (myDialog.exec()) { // user pushed "OK"
        bindir = myDialog.getBinDir();
        caldir = myDialog.getCalDir();
        photdir = myDialog.getPhotDir();
        fourierdir = myDialog.getFourierDir();

        qDebug() << "set bindir to" << bindir;
        qDebug() << "set caldir to" << caldir;
        qDebug() << "set photdir to" << photdir;
        qDebug() << "set fourierdir to" << fourierdir;
    }

    qDebug() << "dirs:" << bindir << caldir << photdir << fourierdir;
}
