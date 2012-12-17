#ifndef DIRECTORYDIALOG_H
#define DIRECTORYDIALOG_H

#include <QDialog>

namespace Ui {
class DirectoryDialog;
}

class DirectoryDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DirectoryDialog(QWidget *parent = 0);
    ~DirectoryDialog();

    QString getBinDir();
    void setBinDir(QString dir);
    QString getCalDir();
    void setCalDir(QString dir);
    QString getPhotDir();
    void setPhotDir(QString dir);
    QString getFourierDir();
    void setFourierDir(QString dir);

private slots:
    void on_binbrowse_clicked();

    void on_calbrowse_clicked();

    void on_photbrowse_clicked();

    void on_fourierbrowse_clicked();

    void on_binline_textChanged(const QString &arg1);

    void on_calline_textChanged(const QString &arg1);

    void on_photline_textChanged(const QString &arg1);

    void on_fourierline_textChanged(const QString &arg1);

private:
    void updateOkButton();

    Ui::DirectoryDialog *ui;
};

#endif // DIRECTORYDIALOG_H
