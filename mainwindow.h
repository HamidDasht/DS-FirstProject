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
#include <QVector>
#include <QMessageBox>


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
        void book_up();
        void add_man();
        void add_women();
        void work_table();
        void men_delete();
        void women_delete();
};

#endif // MAINWINDOW_H
