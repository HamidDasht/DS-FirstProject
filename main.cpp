#include "mainwindow.h"
#include <QApplication>
#include <linkedlist.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Book s("Ghalee","fdfdfs", 1397,11000);
    Book b("AdamVaHavva","fdfdsasd", 1394, 123123);
    Book c("Zoroo", "31231sda", 1396, 232138774);
    LinkedList LL;
    LL.insertBook(s);
    LL.insertBook(b);
    LL.insertBook(c);
    LL.insertBook(Book("AdamVaHavva", "fdfdsasd", 1396, 123123));
    LL.insertBook(Book("AdamVaHavva", "fdfdsasd", 1393, 123123));
    LL.insertBook(Book("dfdfdffd", "fdfdsasd", 1394, 123123));
    LL.printList();

    Book zoroo = LL.deleteBook("Zoroo");


    qDebug() << zoroo.name << "   " << zoroo.date;
    zoroo = LL.deleteBook("fdfdf");
    qDebug() << zoroo.name << "   " << zoroo.date;
    zoroo = LL.deleteBook("AdamVaHavva");
    qDebug() << zoroo.name << "   " << zoroo.date;

    LL.printList();

    return a.exec();
}
