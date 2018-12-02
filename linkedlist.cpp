#include "linkedlist.h"

LinkedList::LinkedList()
{
    // Create head node
    tail = new node(Book("","",-1,0));
    tail->next = tail;
    size = 0;
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
            int date = i->book.date;
            size--;
            delete i;
            return Book(name,"", date, 0);
        }

        j = j->next;
        i = i->next;
    }

    // Not Found.
    return Book("","", -1,0);
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
