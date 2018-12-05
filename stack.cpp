#include "stack.h"

Stack::Stack()
{
    top=nullptr;
    stack_size=0;
}

void Stack::push(Book* book)
{
    if (!stack_size)
    {
        top=new stackNode(book);
        top->book=book;
        top->next=nullptr;
    }

    else
    {
        stackNode* temp=top;
        top=new stackNode(book);
        top->next=temp;
        top->book=book;
    }

    stack_size++;
}

Book Stack::pop()
{
    Book temp=*(top->book);

    if (stack_size==1)
    {
        delete top;
        top=nullptr;
    }

    else
    {
        stackNode* tmp=top;
        top=top->next;
        delete tmp;
    }

    stack_size--;

    return temp;
}

int Stack::size()
{
    return stack_size;
}
