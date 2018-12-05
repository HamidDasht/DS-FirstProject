#include "customer.h"

 
Customer::Customer(QString name, int turn, Stack *books, int gender)

{
    this->name=name;
    this->turn=turn;
    this->books=books;
}
