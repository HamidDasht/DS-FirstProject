#include "linkedlist.h"

LinkedList::LinkedList()
{
    // Create head node
    tail = new node(Book("","",-1,0));
    tail->next = tail;
    size = 0;
}

LinkedList::LinkedList(const LinkedList& copy)
{
    this->size = copy.size;
    this->tail = new node(Book("","",-1,0));
    node* temp;
    for (node * i = copy.tail->next->next; i != copy.tail->next; i = i->next)
    {
        temp = tail;
        tail = new node(i->book);
        temp->next = tail;
    }
}

Book LinkedList::deleteBook(QString name)
{
    node* i = tail->next->next;
    node* j = tail->next;

    while (i != tail->next)
    {
        if (i->book.name == name)
        {
            // If last book is getting removed.
            if (i == tail)
                tail = j;

            j->next = i->next;
            i->next = nullptr;
            QString name = i->book.name;
            int price = i->book.price;
            size--;
            delete i;
            // Book is sold. Only it's price and name are important
            return Book(name,"", 0, price);
        }

        j = j->next;
        i = i->next;
    }

    // Not Found.
    return Book("","", -1,0);
}

void LinkedList::showList(QListWidget *bookList)
{
    bookList->clear();
    BookItem* bookEntry;
    node* i = tail->next->next;
    while (i != tail->next)
    {
        bookEntry = new BookItem(bookList,i->book.name, i->book.writer,i->book.date, i->book.price);
        bookList->addItem(bookEntry);
        bookEntry->setData(Qt::DisplayRole, QString(" \"%1\" Written By %2").arg(i->book.name).arg(i->book.writer));
        bookEntry->setData(Qt::UserRole +1, QString(" Publish Date: %1").arg(i->book.date));
        bookEntry->setData(Qt::DisplayPropertyRole,QString(" Price: %1").arg(i->book.price));
        i = i->next;
    }
}

QDataStream &operator>>(QDataStream &stream, LinkedList *list)
{
    QByteArray size;
    stream >> size;


    QByteArray date;
    QByteArray price;
    QString name;
    QString writer;
    qDebug() << size << "     In Size\n";
    int temp = size.toInt();
    for (int i = temp; i > 0; i--)
    {
        stream >> name;
        stream >> writer;
        stream >> date;
        stream >> price;
     //   qDebug() << name << "\n";
        list->insertBook(Book(name,writer,date.toInt(),price.toInt()));
    }
    return stream;
}

QDataStream &operator<<(QDataStream &stream, const LinkedList *list)
{
    QByteArray size;
    size.setNum(list->size);
    stream << size ;
    QByteArray date;
    QByteArray price;
    for (node* i = list->tail->next->next; i != list->tail->next; i = i->next)
    {
        stream << i->book.name;
        stream << i->book.writer;
        date.setNum(i->book.date);
        stream << date ;
        price.setNum(i->book.price);
        stream << price;

    }
    return stream;
}

void LinkedList::printList()
{

    node* i = tail->next->next;
    while (i != tail->next)
    {
        qDebug() <<i->book.name << "   Publication Date: " << i->book.date <<"\n";
        i = i->next;
    }
}

void LinkedList::insertBook(Book book)
{
    node* i,* j;
    i = tail->next->next;
    j = tail->next;

    while (i->book.name.toUpper() < book.name.toUpper() && i != tail->next)
    {
        i = i->next;
        j = j->next;
    }
    while (i->book.name.toUpper() == book.name.toUpper() &&  i->book.date > book.date && i != tail->next)
    {
        i = i->next;
        j = j->next;
    }
    node * newBook = new node(book, nullptr);
    if (i == tail->next)
        tail = newBook;

    j->next = newBook;
    newBook->next = i;
    size++;
    return;
}

LinkedList::~LinkedList()
{

}
