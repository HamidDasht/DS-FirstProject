#ifndef STORE_H
#define STORE_H
#include <QObject>
#include <QMainWindow>
#include <linkedlist.h>
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QDataStream>

class Store : public QObject
{
public:
    Store();
    void addCustomer();
    void addBook();
    void readFile();
    void writeFile();
    //void printBooks();
    LinkedList books;

    void printBooks(QListWidget *bookList);
private:
    void deleteBook(QString name);
signals:
public slots:
};

#endif // STORE_H
