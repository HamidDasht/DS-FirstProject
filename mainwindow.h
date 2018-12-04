#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <store.h>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void printBooks();
    ~MainWindow();

private:
    Store store;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
