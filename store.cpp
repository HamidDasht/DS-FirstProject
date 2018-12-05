#include "store.h"
#include "ui_Store.h"

Store::Store(QWidget *parent): QMainWindow(parent),ui(new Ui::Store)
{
    turns=0;
    latest_turn=0;

}

void Store::addCustomer()
{
    QDialog dialog;
    QFormLayout form(&dialog);
    QLineEdit customer;
    form.addRow(new QLabel("customer name :"), &customer);
    QCheckBox* checkBox=new QCheckBox("male",&dialog);
    QCheckBox* checkBox2=new QCheckBox("famale",&dialog);
    form.addWidget(checkBox);
    form.addWidget(checkBox2);




    QDialogButtonBox* button = new QDialogButtonBox(QDialogButtonBox::Ok);
    QObject::connect(button,SIGNAL(accepted()),&dialog,SLOT(accept()));
    QObject::connect(button,SIGNAL(rejected()),&dialog,SLOT(reject()));
    form.addRow(button);

    bool flag=true;
    QString name;

    int response;


    while (1)
    {
        flag=true;

         response = dialog.exec();

        if( response == QDialog::Accepted)
        {
            name=customer.text();
            if (name=="")
                flag=false;
            if (checkBox->isChecked()&& checkBox2->isChecked())
                    flag=false;
            if (!checkBox->isChecked() && !checkBox2->isChecked())
                    flag=false;

        }

        if (flag==true)
            break;
    }

    if (response==QDialog::Accepted)
    {



     int turn=this->latest_turn;
     setGeometry(100,100,400,400);
     ui->setupUi(this);
     show();
     QObject::connect(ui->end_of_bying, &QPushButton::clicked, this, &Store::buy_end);
     QObject::connect(ui->listWidget, &QListWidget::itemClicked, this, &Store::stack_up);

     QListWidget * lists=ui->listWidget;

     printBooks(lists);
     emit turn_up();

        Stack* stk= new Stack();

        while (book_vec.size()!=0)
        {
            stk->push(book_vec[0]);
            book_vec.pop_front();
        }

          if (checkBox->isChecked())
          {
               Customer custom(name, turn, stk, 1);
               man.push(&custom);
          }

          else if (checkBox2->isChecked())
          {

               Customer custom (name, turn, stk, 0);
               women.push(&custom);
          }
    int turn=this->latest_turn;

    show();

    emit turn_up();


        //Customer custom (name, turn, stk);

    }
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

    if (flag==false)
    {
        int prc=book_price.toInt();
        int date=date_publish.toInt();

        Book book(book_name, publlisher_name, date, prc);
        this->books.insertBook(book);
        this->books.printList();
    }

    emit bookAdded();

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

void Store::stack_up(QListWidgetItem *item)
{
    BookItem * book= static_cast <BookItem*> (item);
    Book* temp= new Book(book->get_name(), book->get_writer(), book->get_date(), book->get_price());
    book_vec.push_back(temp);
    delete item;
}

void Store::buy_end()
{

    for (int i=0; i<book_vec.size(); i++)
    {
        books.deleteBook(book_vec[i]->name);
    }

    emit books_up();
    close();

}

void Store::printBooks(QListWidget* bookList)
{
    books.showList(bookList);
}
