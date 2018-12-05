#ifndef BOOKITEM_H
#define BOOKITEM_H
#include <QListWidgetItem>
#include <QString>
#include <QObject>

class BookItem : public QListWidgetItem
{
public:
    BookItem(QListWidget* view, QString name , QString writer, int date, int price);
    QString get_name();
    QString get_writer();
    int get_price();
    int get_date();

private:
    QString name;
    QString writer;
    int price;
    int date;
};

#endif // BOOKITEM_H
