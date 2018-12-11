#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <QDebug>
#include <book.h>
#include <QDataStream>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLayout>
#include <bookitem.h>

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
    LinkedList(const LinkedList& copy);
    void insertBook(Book book);
    Book deleteBook(QString name);
    friend QDataStream& operator<<(QDataStream& stream, const LinkedList* list);
    friend QDataStream& operator>>(QDataStream& stream, LinkedList* list);

    void showList(QListWidget* bookList);
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
