#include "store.h"
#include "ui_Store.h"

Store::Store(QWidget *parent): QMainWindow(parent),ui(new Ui::Store)
{
}

void Store::addCustomer()
{
    QDialog dialog;
    QFormLayout form(&dialog);
    QLineEdit customer;
    form.addRow(new QLabel("customer name :"), &customer);

    QDialogButtonBox* button = new QDialogButtonBox(QDialogButtonBox::Ok);
    QObject::connect(button,SIGNAL(accepted()),&dialog,SLOT(accept()));
    QObject::connect(button,SIGNAL(rejected()),&dialog,SLOT(reject()));
    form.addRow(button);

    bool flag=true;
    QString name;

    while (1)
    {
        flag=true;

        int response = dialog.exec();
        if( response == QDialog::Accepted)
        {
            name=customer.text();
            if (name=="")
                flag=false;
        }

        if (flag==true)
            break;
    }

    int turn=this->latest_turn;

    show();



    emit turn_up();

}

void Store::addCustomer()
{

}

void Store::addBook()
{
    QDialog dialog;
    QFormLayout form(&dialog);
    QLineEdit bookname;
    QLineEdit publisher;
    QLineEdit price;
    QLineEdit publlish_date;

    form.addRow(new QLabel("book name: "), &bookname);
    form.addRow(new QLabel("publisher :"), &publisher);
    form.addRow(new QLabel("price :"), &price);
    form.addRow(new QLabel("publish date :"), &publlish_date);

    QDialogButtonBox* button = new QDialogButtonBox(QDialogButtonBox::Ok);
    QObject::connect(button,SIGNAL(accepted()),&dialog,SLOT(accept()));
    QObject::connect(button,SIGNAL(rejected()),&dialog,SLOT(reject()));
    form.addRow(button);

    bool flag=true;

    QString book_name;
    QString publlisher_name;
    QString book_price;
    QString date_publish;

    while (1)
    {
        flag=true;

        int response = dialog.exec();
        if( response == QDialog::Accepted)
        {
             book_name=bookname.text();
             publlisher_name=publisher.text();
             book_price=price.text();
             date_publish=publlish_date.text();

             if (book_name=="")
                flag=false;
             else if (publlisher_name=="")
                 flag=false;
             else if (book_price=="")
                   flag=false;
             else if (date_publish=="")
                 flag=false;
        }

        if (flag==true)
            break;
    }

    int prc=book_price.toInt();
    int date=date_publish.toInt();

    Book book(book_name, publlisher_name, date, prc);
    this->books.insertBook(book);
    this->books.printList();



}

void Store::readFile()
{
    QDir::setCurrent("C:/book-store/");
    QFile file("books.dat");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "File not found!\n";
        return;
    }

    QDataStream in(&file);

    in >> &books;
    file.close();
    qDebug() << "File read\n";
}

void Store::writeFile()
{
    QDir dir("C:/book-store");
    dir.removeRecursively();

    QDir::setCurrent("C:/");
    if(!QDir("book-store").exists())
        QDir().mkdir("book-store");


    QDir::setCurrent("C:/book-store/");
    QFile file("books.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    out << &books;
    qDebug() << "File written";
    file.close();
}

void Store::printBooks(QListWidget* bookList)
{
    books.showList(bookList);
}
