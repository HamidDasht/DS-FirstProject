#ifndef STACK_H
#define STACK_H

#include <book.h>

struct stackNode
{
    stackNode(Book* book, stackNode* next = nullptr) : book(book)
    {
        this->next = next;
    }
    Book* book;
    stackNode* next;
};

class Stack
{
    stackNode* top;
    int stack_size;


public:
    Stack();
    void push (Book*);
    Book pop ();
    int size();
};


#endif // STACK_H
