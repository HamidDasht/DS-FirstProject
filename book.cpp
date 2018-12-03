#include <book.h>

Book::Book(QString name, QString writer, int date, int price)
{
    this->name = name;
    this->writer = writer;
    this->date = date;
    this->price = price;
}

Book::Book(const Book &book)
{
    name = book.name;
    writer =book.writer;
    date = book.date;
    price = book.price;
}

void Book::printBookInfo()
{

}
