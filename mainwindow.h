#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <store.h>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <listdelegate.h>


namespace Ui {
class MainWindow;
class books;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void printBooks();
    ~MainWindow();

private:
    void closeEvent(QCloseEvent* event);
    Store store;
    Ui::MainWindow *ui;

    public slots:
        void turns_up();
};

#endif // MAINWINDOW_H
