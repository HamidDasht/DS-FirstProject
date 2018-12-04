#ifndef STORE_H
#define STORE_H
#include <QObject>
#include <QMainWindow>
#include <linkedlist.h>
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QDataStream>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include "stack.h"


namespace Ui
{
    class Store;
}

class Store : public QMainWindow
{
    Q_OBJECT
public:
<<<<<<< HEAD
     Store(QWidget *parent = 0);
=======
    Store();
>>>>>>> 54ebbcebfe293f282a9826a983abc38c5a7741d6
    void addCustomer();
    void addBook();
    void readFile();
    void writeFile();
    //void printBooks();
    LinkedList books;

    void printBooks(QListWidget *bookList);
private:
    void deleteBook(QString name);
<<<<<<< HEAD
    LinkedList books;
    int turns;
    int latest_turn;
    Ui::Store* ui;

=======
>>>>>>> 54ebbcebfe293f282a9826a983abc38c5a7741d6
signals:
    void turn_up();

public slots:
};

#endif // STORE_H
