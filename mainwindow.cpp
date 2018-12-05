#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->AddBook,&QPushButton::clicked, &this->store, &Store::addBook);
    QObject::connect(ui->AddCustomer, &QPushButton::clicked, &this->store, &Store::addCustomer);
    QObject::connect(&this->store, &Store::turn_up, this, &MainWindow::turns_up);
    QObject::connect(&this->store, &Store::books_up, this, &MainWindow::book_up);


    QObject::connect(&this->store,&Store::bookAdded,this,&MainWindow::printBooks);

    ui->BookList->setItemDelegate(new ListDelegate(ui->BookList));
    store.readFile();
    printBooks();
}

void MainWindow::printBooks()
{
    store.printBooks(ui->BookList);
}

MainWindow::~MainWindow()
{
    store.writeFile();
    delete ui;
}

void MainWindow::turns_up()
{
 
    int n=++store.turns;
    qDebug()<<store.turns;
    ui->Turns->display(n);
}

void MainWindow::book_up()
{
    printBooks();


}

void MainWindow::closeEvent(QCloseEvent* event)
{
    store.writeFile();
}
