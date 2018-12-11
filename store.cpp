#include "store.h"
#include "ui_Store.h"

Store::Store(QWidget *parent): QMainWindow(parent),ui(new Ui::Store)
{
    turns=0;
    latest_turn=1;
    gender=true;
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
     QObject::connect(ui->end_of_bying, &QPushButton::clicked, this, &Store::buy_end);
     QObject::connect(ui->listWidget, &QListWidget::itemClicked, this, &Store::stack_up);

     QListWidget * lists=ui->listWidget;
     ui->listWidget->setItemDelegate(new ListDelegate(ui->listWidget));
     printBooks(ui->listWidget);

     QObject::connect(ui->PopBook, &QPushButton::clicked, this, &Store::popBook);
        Stack* stack=new Stack();
        QEventLoop a;
        QObject::connect(ui->end_of_bying, &QPushButton::clicked, &a, &QEventLoop::quit);


          if (checkBox->isChecked())
          {
               qDebug()<<"add cus"<<stack->size();
               Customer* custom=new Customer(name, turn, stack, 1);
               man.push(custom);
               emit man_added();
          }

          else if (checkBox2->isChecked())
          {
               Customer* custom =new Customer(name, turn, stack, 0);
               women.push(custom);
               emit women_added();
          }

         move(QApplication::activeWindow()->x(), QApplication::activeWindow()->y());
         show();
         emit turn_up();
         a.exec();

         while (book_vec.size()!=0)
         {
             stack->push(book_vec[0]);
             if (response == QDialog::Rejected)
                 books.insertBook(Book(book_vec[0]->name,book_vec[0]->writer,book_vec[0]->date,book_vec[0]->price));
             book_vec.pop_front();
         }
         //QObject::disconnect(ui->end_of_bying, &QPushButton::clicked, this, &Store::buy_end);
         //QObject::disconnect(ui->listWidget, &QListWidget::itemClicked, this, &Store::stack_up);

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

    int response;
    while (1)
    {
        flag=true;

        response = dialog.exec();
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

    if (flag==true && response == QDialog::Accepted)
    {
        int prc=book_price.toInt();
        int date=date_publish.toInt();

        Book book(book_name, publlisher_name, date, prc);
        this->books.insertBook(book);
        this->books.printList();
    }

    emit bookAdded();

    if (response == QDialog::Accepted)
        addBook();

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
    books.deleteBook(temp->name);
    ui->CustomerStack->insertItem(0,temp->name);

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

void Store::sell_book()
{
    if (!man.size() && !women.size())
    {
        return;
    }

    if(gender && man.size()==0)
    {
        gender=false;
        emit delete_women();
        return;
    }

    if(gender==0 && women.size()==0)
    {
        gender=true;
        emit delete_men();
        return ;
    }

    if (gender)
    {
        emit delete_men();
    }

    else
        emit delete_women();
}


Queue Store::get_men()
{
    return man;
}

Queue Store::get_women()
{
    return women;
}

void Store::popBook()
{
    if (book_vec.size() == 0)
        return;

    Book* temp = book_vec.back();
    book_vec.pop_back();
    qDebug() << temp->name;
    QList<QListWidgetItem*> a = ui->CustomerStack->findItems(temp->name, Qt::MatchExactly);
    //qDebug() << a.size();
    //ui->CustomerStack->removeItemWidget(a.first());
    if (a.size() > 0)
    {
        books.insertBook(Book(temp->name,temp->writer,temp->date,temp->price));
        printBooks(ui->listWidget);
        delete a.at(0);
    }
  //  ui->listWidget->addItem(new BookItem)
}

