#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateDirs();

private slots:

    void on_biaslist_clicked();

    void on_action_set_paths_triggered();

private:
    Ui::MainWindow *ui;

    QString bindir,caldir,photdir,fourierdir;
};

#endif // MAINWINDOW_H
