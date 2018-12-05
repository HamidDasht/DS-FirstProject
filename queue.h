#ifndef QUEUE_H
#define QUEUE_H

#include "book.h"
#include "customer.h"

struct element
{
    element* next;
    Customer* customer;
};

class Queue
{
    element* rear;
    element* front;
    int queue_size;

public:
    Queue();
    void push(Customer* customer);
    Customer pop();
    int size();

};

#endif // QUEUE_H
