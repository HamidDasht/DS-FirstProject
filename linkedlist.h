#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <QDebug>
#include <book.h>

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
