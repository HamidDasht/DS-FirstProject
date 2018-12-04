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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::turns_up()
{

}
