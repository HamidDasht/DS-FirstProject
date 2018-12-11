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
#include <listdelegate.h>
#include <QMenu>
#include <QTimer>
#include <QEventLoop>



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
     bool gender;

    void addCustomer();
    void addBook();
    void readFile();
    void writeFile();
    void stack_up(QListWidgetItem* item);
    void buy_end ();
    void printBooks();
    void printBooks(QListWidget *bookList);
    void sell_book();

    Queue get_men();
    Queue get_women();
    Queue man;
    Queue women;

private:
    void deleteBook(QString name);
    LinkedList books;
  //  Queue man;
  //  Queue women;
    QVector <Book*> book_vec;


    Ui::Store* ui;

signals:
    void turn_up();
    void books_up();
    void bookAdded();
    void man_added();
    void women_added();
    void delete_men();
    void delete_women();


public slots:
};

#endif // STORE_H
