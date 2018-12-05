#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include "stack.h"


class Customer
{

    QString name;
    int turn;
    Stack* books;
    int gender;

public:
    Customer(QString name, int turn, Stack* books, int gender);
private:

};

#endif // CUSTOMER_H
