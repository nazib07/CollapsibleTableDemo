#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <form.h>


MainWindow::MainWindow(QWidget *parent) :
                                          QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Form *w = new Form();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->setWindowModality(Qt::ApplicationModal);
    w->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

