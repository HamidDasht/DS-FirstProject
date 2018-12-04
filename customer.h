#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include "stack.h"


class Customer
{

    QString name;
    int turn;
    Stack* books;

public:
    Customer(QString name, int turn,Stack* books);
private:

};

#endif // CUSTOMER_H
