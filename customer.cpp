#include "customer.h"

 
Customer::Customer(QString name, int turn, Stack *books, bool gender)

{
    this->name=name;
    this->turn=turn;
    this->books=books;
    this->gender = gender;
}

Customer::Customer(const Customer & customer)
{
    this->name = customer.name;
    this->books = customer.books;
    this->gender = customer.gender;
    this->turn = customer.turn;
}

QString Customer::get_name()
{
    return name;
}

Stack *Customer::get_books()
{
    return books;
}
