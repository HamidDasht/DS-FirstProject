#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book
{
public:
    Book(QString name, QString writer, int date, unsigned int price);
    Book(const Book& book);
    QString name;
    QString writer;
    unsigned int price;
    void printBookInfo();
    int date;
};

#endif // BOOK_H
