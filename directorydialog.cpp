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
    return ui->binaryline->text();
}

void DirectoryDialog::setBinDir(QString dir)
{
    ui->binaryline->setText(dir);
}

void DirectoryDialog::on_binbutton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Binary Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly
                                                    );

    if (!dir.isEmpty()) {
        ui->binaryline->setText(dir);
    }
}
