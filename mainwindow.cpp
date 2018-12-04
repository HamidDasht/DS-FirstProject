#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->AddBook,&QPushButton::clicked, &this->store, &Store::addBook);
    store.readFile();
    printBooks();
    QObject::connect(ui->BookList,&QListWidget::itemClicked,&BookItem::remove);
}

void MainWindow::printBooks()
{
    store.printBooks(ui->BookList);
}

MainWindow::~MainWindow()
{
    delete ui;
}
