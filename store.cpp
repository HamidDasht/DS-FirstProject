#include "store.h"

Store::Store() : QObject()
{

}

void Store::addCustomer()
{

}

void Store::addBook()
{
    qDebug() << "dsdasdasdsad";

}

void Store::readFile()
{
    QDir::setCurrent("C:/book-store/");
    QFile file("books.dat");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "File not found!\n";
        return;
    }

    QDataStream in(&file);

    in >> &books;
    file.close();
    qDebug() << "File read\n";
}

void Store::writeFile()
{
    QDir dir("C:/book-store");
    dir.removeRecursively();

    QDir::setCurrent("C:/");
    if(!QDir("book-store").exists())
        QDir().mkdir("book-store");


    QDir::setCurrent("C:/book-store/");
    QFile file("books.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    out << &books;
    qDebug() << "File written";
    file.close();
}

void Store::printBooks(QListWidget* bookList)
{
    books.showList(bookList);
}
