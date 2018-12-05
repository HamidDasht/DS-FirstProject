#ifndef STORE_H
#define STORE_H
#include <QObject>
#include <QMainWindow>
#include <linkedlist.h>
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QDataStream>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include "stack.h"
#include <queue.h>
#include <QVector>
#include "customer.h"



namespace Ui
{
    class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT
public:
     Store(QWidget *parent = 0);
     int turns;
     int latest_turn;

    void addCustomer();
    void addBook();
    void readFile();
    void writeFile();
    void stack_up(QListWidgetItem* item);
    void buy_end ();

    void printBooks();

    void printBooks(QListWidget *bookList);

private:
    void deleteBook(QString name);
    LinkedList books;
    Stack stack;
    Queue man;
    Queue women;
    QVector <Book*> book_vec;


    Ui::Store* ui;

signals:
    void turn_up();
    void books_up();


public slots:
};

#endif // STORE_H
