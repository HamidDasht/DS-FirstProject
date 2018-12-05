#include "bookitem.h"
#include <QDebug>
BookItem::BookItem(QListWidget* view, QString name , QString writer, int date, int price) : QListWidgetItem (view)

{
    setSizeHint(QSize(100,30));
    setBackgroundColor(Qt::darkGray);
    //QObject::connect(&this, )
    this->name=name;
    this->writer=writer;
    this->date=date;
    this->price=price;
}

QString BookItem::get_name()
{
    return name;
}

QString BookItem::get_writer()
{
    return writer;
}

int BookItem::get_price()
{
    return price;
}

int BookItem::get_date()
{
    return date;
}
