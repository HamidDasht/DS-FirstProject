#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include "stack.h"


class Customer
{
public:
    QString name;
    int turn;
    Stack* books;
    bool gender;
    Customer(QString name, int turn, Stack* books, bool gender);
    Customer(const Customer&);
    QString get_name();
    Stack* get_books ();
private:

};


#endif // CUSTOMER_H
