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

QString Queue::get_top_name()
{
    return rear->customer->name;
}

Customer Queue::pop()
{
    Customer* temp=front->customer;
    element* tmp=front;
    front=front->next;
    queue_size--;
    delete tmp;

    return Customer(temp->name, temp->turn, temp->books, temp->gender);
}

int Queue::size()
{
    return queue_size;
}
