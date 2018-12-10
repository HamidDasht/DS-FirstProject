#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LastTurn->display(1);

    ui->table->setContextMenuPolicy(Qt::CustomContextMenu);

    QObject::connect(&this->store, &Store::turn_up, this, &MainWindow::turns_up);
    QObject::connect(&this->store, &Store::books_up, this, &MainWindow::book_up);
    QObject::connect(&this->store,&Store::bookAdded,this,&MainWindow::printBooks);
    QObject::connect(&this->store,&Store::man_added,this,&MainWindow::add_man);
    QObject::connect(&this->store,&Store::women_added,this,&MainWindow::add_women);
    QObject::connect(&this->store,&Store::delete_men,this,&MainWindow::men_delete);
    QObject::connect(&this->store,&Store::delete_women,this,&MainWindow::women_delete);
    QObject::connect(ui->table,&QPushButton::clicked, this, &MainWindow::work_table);

    ui->BookList->setItemDelegate(new ListDelegate(ui->BookList));
    ui->men_queue->setItemDelegate(new ListDelegate(ui->men_queue));
    ui->women_queue->setItemDelegate(new ListDelegate(ui->women_queue));

    store.readFile();
    printBooks();
}

void MainWindow::printBooks()
{
    store.printBooks(ui->BookList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::turns_up()
{
 
    int n=++store.turns;
    //qDebug()<<store.turns;
    ui->Turns->display(n);
}

void MainWindow::book_up()
{
     move(QApplication::activeWindow()->x(), QApplication::activeWindow()->y());
     show();
    printBooks();
}

void MainWindow::add_man()
{
    ui->men_queue->addItem(new QListWidgetItem(store.man.get_top_name()));
}

void MainWindow::add_women()
{
    ui->women_queue->addItem(new QListWidgetItem(store.women.get_top_name()));
}

void MainWindow::work_table()
{
    QMenu* createChatMenu = new QMenu(this);
    //createChatMenu->setStyleSheet("color: black;"
                                 // "background-color: rgba(196,231,236);");
    createChatMenu->setGeometry(ui->table->x()+this->x()+10,ui->table->y()+this->y()+100,100,60);
    createChatMenu->addAction("Add Book",&this->store,&Store::addBook);
    createChatMenu->addAction("Add Customer",&this->store,&Store::addCustomer);
    createChatMenu->addAction("Sell Book",&this->store,&Store::sell_book);

    qDebug() << "work table called";
    createChatMenu->exec();
}

void MainWindow::men_delete()
{
    QVector <QString> str;
    QVector <int> cost;
    delete ui->men_queue->takeItem(0);
   // Customer customer = store.get_men().pop();
    Customer customer = store.man.pop();
    qDebug()<<"size "<<customer.books->size();

    while (customer.get_books()->size())
    {
        Book book=customer.get_books()->pop();
        str.push_back(book.name);
        cost.push_back(book.price);
    }

    QMessageBox* msgBox = new QMessageBox();
    QString matn="turn: "+QString::number(store.latest_turn)+"\n";
    int sum=0;

    while (str.size())
    {
        matn+="\n+ ";
        matn+=str.back();
        matn+="    ";
        //matn+=cost.back();
        QString s=QString::number(cost.back());
        sum+=cost.back();
        matn+=s;
        matn+="\n";
        qDebug()<<matn;
        str.pop_back();
        cost.pop_back();
    }

    msgBox->setText(matn);
    msgBox->setInformativeText("\nsum: "+QString::number(sum));

    msgBox->exec();

    store.gender=false;
    store.latest_turn++;
    ui->LastTurn->display(store.latest_turn);
}

void MainWindow::women_delete()
{
    QVector <QString> str;
    QVector <int> cost;
    delete ui->women_queue->takeItem(0);
    Customer custom=store.women.pop();

    while (custom.get_books()->size())
    {
        Book book=custom.get_books()->pop();
        str.push_back(book.name);
        cost.push_back(book.price);
    }

    QMessageBox* msgBox = new QMessageBox();
    QString matn="turn: "+QString::number(store.latest_turn)+"\n";

    int sum=0;

    while (str.size())
    {
        //matn+="turn : "+QString::number(store.latest_turn);
        matn+="\n+ ";
        matn+=str.back();
        matn+="    ";
        QString s=QString::number(cost.back());
        sum+=cost.back();
        matn+=s;
        matn+="\n";
        qDebug()<<matn;
        str.pop_back();
        cost.pop_back();
    }

    msgBox->setText(matn);
    msgBox->setInformativeText("\nsum : "+QString::number(sum));

    msgBox->exec();

    store.gender=true;
    store.latest_turn++;
     ui->LastTurn->display(store.latest_turn);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    store.writeFile();
}
