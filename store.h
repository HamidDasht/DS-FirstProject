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
    void addCustomer(QString name);
    void addBook();
    void readFile();
    void writeFile();



    void printBooks();
private:
    void deleteBook(QString name);
    LinkedList books;
signals:
public slots:
};

#endif // STORE_H
