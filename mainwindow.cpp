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
    // reload the directories from the settings we saved

    QSettings settings("andysbaran", "finred");
    bindir = settings.value("dirs/binary").toString();
    caldir = settings.value("dirs/calibration").toString();
    photdir = settings.value("dirs/photometry").toString();
    fourierdir = settings.value("dirs/fourier").toString();
}

void MainWindow::on_biaslist_clicked()
{
    QDir::setCurrent(caldir);
    system("ls bias*.fits >bias.cat");
}

void MainWindow::on_action_set_paths_triggered()
{
    // build a dialog and set all the directories we know about
    DirectoryDialog myDialog(this);
    myDialog.setBinDir(bindir);
    myDialog.setCalDir(caldir);
    myDialog.setPhotDir(photdir);
    myDialog.setFourierDir(fourierdir);

    if (myDialog.exec()) { // user pushed "OK"
        // retrieve the dialog's directories
        bindir = myDialog.getBinDir();
        caldir = myDialog.getCalDir();
        photdir = myDialog.getPhotDir();
        fourierdir = myDialog.getFourierDir();

        // save the dialogs directories in the settings object
        QSettings settings("andysbaran", "finred");
        settings.setValue("dirs/binary", bindir);
        settings.setValue("dirs/calibration", caldir);
        settings.setValue("dirs/photometry", photdir);
        settings.setValue("dirs/fourier", fourierdir);
    }

    qDebug() << "dirs:" << bindir << caldir << photdir << fourierdir;
}
