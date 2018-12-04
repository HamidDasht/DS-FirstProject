#include "customer.h"

Customer::Customer(QString name, int turn, Stack *books)
{
    this->name=name;
    this->turn=turn;
    this->books=books;
}
