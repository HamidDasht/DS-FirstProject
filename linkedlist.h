#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <QDebug>
#include <book.h>
#include <QDataStream>


struct node
{
    node(Book book, node* next = nullptr) : book(book)
    {
        this->next = next;
    }
    Book book;
    node* next;
};


class LinkedList
{
public:
    LinkedList();
    void insertBook(Book book);
    Book deleteBook(QString name);
    friend QDataStream& operator<<(QDataStream& stream, const LinkedList* list);
    friend QDataStream& operator>>(QDataStream& stream, LinkedList* list);

    int length()
    {
        return size;
    }

    void printList();
    ~LinkedList();
protected:
    int size;
    node* tail;
};

#endif // LINKEDLIST_H
