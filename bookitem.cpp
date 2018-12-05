#include "bookitem.h"
#include <QDebug>

BookItem::BookItem(QListWidget* view) : QListWidgetItem (view)
{
    setSizeHint(QSize(100,30));
    setBackgroundColor(Qt::darkGray);
}
