#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "create_page.h"
#include "gestion_page.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Create_button_clicked()
{
    Create_Page *createPage = new Create_Page(this);
    connect(createPage, &Create_Page::informationEntered, this, &MainWindow::handleInformationEntered);
    createPage->show();
}

void MainWindow::handleInformationEntered(const QPixmap& image, const QUrl& sound, const QString& type1, const QString& type2, const QString& description, const QString& name)
{
    // Handle the received information here
    // For example, print it to console
    qDebug() << "Received Information:";
    qDebug() << "Image Path: " << image;
    qDebug() << "Sound URL: " << sound;
    qDebug() << "Type 1: " << type1;
    qDebug() << "Type 2: " << type2;
    qDebug() << "Description: " << description;
    qDebug() << "Name: " << name;

    // Now you can use these variables to create gestion_page object or do other operations
    gestion_page *gestionPage = static_cast<gestion_page*>(ui->tabWidget->currentWidget());
    gestionPage->addTab(image, sound, type1, type2, description, name);
}

void MainWindow::on_Quitter_button_clicked()
{
    QApplication::quit();
}

void MainWindow::on_Gestion_button_clicked()
{
    // Create a gestion_page object with default constructor
    gestion_page *gestionpage = new gestion_page(this);
    ui->tabWidget->addTab(gestionpage, "Gestion des pages");
    ui->tabWidget->setCurrentWidget(gestionpage);
}
