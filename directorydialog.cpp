#include "directorydialog.h"
#include "ui_directorydialog.h"
#include <QFileDialog>
#include <QDebug>
#include "dirvalidator.h"
#include <QCompleter>
#include <QDirModel>

DirectoryDialog::DirectoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DirectoryDialog)
{
    ui->setupUi(this);

    // hook up our custom directory validator
    // to show if the user types bad paths
    DirValidator *binvalidator = new DirValidator(this);
    ui->binline->setValidator(binvalidator);
    DirValidator *calvalidator = new DirValidator(this);
    ui->calline->setValidator(calvalidator);
    DirValidator *photvalidator = new DirValidator(this);
    ui->photline->setValidator(photvalidator);
    DirValidator *fouriervalidator = new DirValidator(this);
    ui->fourierline->setValidator(fouriervalidator);

    // connect the validation signal to the color slot
    connect(binvalidator, SIGNAL(validationState(QValidator::State)),
            ui->binline, SLOT(setValidationState(QValidator::State)));
    connect(calvalidator, SIGNAL(validationState(QValidator::State)),
            ui->calline, SLOT(setValidationState(QValidator::State)));
    connect(photvalidator, SIGNAL(validationState(QValidator::State)),
            ui->photline, SLOT(setValidationState(QValidator::State)));
    connect(fouriervalidator, SIGNAL(validationState(QValidator::State)),
            ui->fourierline, SLOT(setValidationState(QValidator::State)));

    // hook up a completer for the filesystem
    // see http://doc.qt.digia.com/qt/qcompleter.html#details
    QCompleter *completer = new QCompleter(this);
    completer->setModel(new QDirModel(completer));
    ui->binline->setCompleter(completer);
    ui->calline->setCompleter(completer);
    ui->photline->setCompleter(completer);
    ui->fourierline->setCompleter(completer);

    updateOkButton();
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


void DirectoryDialog::updateOkButton()
{
    // either disable or enable the OK button
    // disable if we have bad paths
    // otherwise enable it

    bool enabled = true;

    if (!ui->binline->isAcceptable()) {
        enabled = false;
    }
    if (!ui->calline->isAcceptable()) {
        enabled = false;
    }
    if (!ui->photline->isAcceptable()) {
        enabled = false;
    }
    if (!ui->fourierline->isAcceptable()) {
        enabled = false;
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(enabled);
}

void DirectoryDialog::on_binline_textChanged(const QString &arg1)
{
    updateOkButton();
}


void DirectoryDialog::on_calline_textChanged(const QString &arg1)
{
    updateOkButton();
}

void DirectoryDialog::on_photline_textChanged(const QString &arg1)
{
    updateOkButton();
}

void DirectoryDialog::on_fourierline_textChanged(const QString &arg1)
{
    updateOkButton();
}
