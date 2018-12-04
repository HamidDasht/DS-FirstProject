#ifndef BOOKITEM_H
#define BOOKITEM_H
#include <QListWidgetItem>
#include <QString>

class BookItem : public QListWidgetItem
{
public:
    BookItem(QListWidget* view);
private:
    QString name;
    QString writer;
    int price;
    int date;
};

#endif // BOOKITEM_H
