#include "directorydialog.h"
#include "ui_directorydialog.h"
#include <QFileDialog>
#include <QDebug>

DirectoryDialog::DirectoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DirectoryDialog)
{
    ui->setupUi(this);
}

DirectoryDialog::~DirectoryDialog()
{
    delete ui;
}

QString DirectoryDialog::getBinDir()
{
    return ui->binline->text();
}

QString DirectoryDialog::getCalDir()
{
    return ui->calline->text();
}

QString DirectoryDialog::getPhotDir()
{
    return ui->photline->text();
}

QString DirectoryDialog::getFourierDir()
{
    return ui->fourierline->text();
}

void DirectoryDialog::setBinDir(QString dir)
{
    ui->binline->setText(dir);
}

void DirectoryDialog::setCalDir(QString dir)
{
    ui->calline->setText(dir);
}

void DirectoryDialog::setPhotDir(QString dir)
{
    ui->photline->setText(dir);
}

void DirectoryDialog::setFourierDir(QString dir)
{
    ui->fourierline->setText(dir);
}

void DirectoryDialog::on_binbrowse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Binary Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    );

    if (!dir.isEmpty()) {
        ui->binline->setText(dir);
    }
}

void DirectoryDialog::on_calbrowse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Calibration Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    );

    if (!dir.isEmpty()) {
        ui->calline->setText(dir);
    }

}

void DirectoryDialog::on_photbrowse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Photometry Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    );

    if (!dir.isEmpty()) {
        ui->photline->setText(dir);
    }

}

void DirectoryDialog::on_fourierbrowse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Fourier Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    );

    if (!dir.isEmpty()) {
        ui->fourierline->setText(dir);
    }


}
