#include "queue.h"

Queue::Queue()
{
    front=nullptr;
    rear=nullptr;
    queue_size=0;
}

void Queue::push(Customer* customer)
{
       if (!queue_size)
       {
           front=new element();
           front->next=nullptr;
           front->customer=customer;
           rear=front;
       }

       else
       {
           element* temp=rear;
           rear=new element();
           temp->next=rear;
           rear->next=nullptr;
           rear->customer=customer;

       }

       queue_size++;
}

Customer Queue::pop()
{
    Customer temp=*(front->customer);
    element* tmp=front;
    front=front->next;
    delete tmp;

    return temp;
}

int Queue::size()
{
    return queue_size;
}

