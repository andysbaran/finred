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
    bindir = settings.value("dirs/binary").toString();
}

void MainWindow::on_biaslist_clicked()
{

}

void MainWindow::on_actionBinary_directory_triggered()
{
}

void MainWindow::on_actionCalibration_directory_triggered()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Calibration Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    );

    if (!dir.isEmpty()) {
        caldir = dir; // save global variable
    }

    qDebug() << "user chose calib dir" << caldir;
}

void MainWindow::on_actionPhotometry_directory_triggered()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Photometry Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    );

    if (!dir.isEmpty()) {
        photdir = dir; // save global variable
    }

    qDebug() << "user chose calib dir" << photdir;

}

void MainWindow::on_action_set_paths_triggered()
{
    DirectoryDialog myDialog(this);
    myDialog.setBinDir(bindir);

    if (myDialog.exec()) { // user pushed "OK"
        bindir = myDialog.getBinDir();

        qDebug() << "set bindir to" << bindir;
    }

    qDebug() << "dirs:" << bindir << caldir << photdir;
}
