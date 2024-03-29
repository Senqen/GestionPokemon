#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "create_page.h"
#include "gestion_page.h"
#include "gestion_page_tab.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    informationProcessed(false)
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
    if (informationProcessed) {
        // Ignorer le signal si les informations ont déjà été traitées
        return;
    }

    qDebug() << "Received Information:";
    qDebug() << "Image Path: " << image;
    qDebug() << "Sound URL: " << sound;
    qDebug() << "Type 1: " << type1;
    qDebug() << "Type 2: " << type2;
    qDebug() << "Description: " << description;
    qDebug() << "Name: " << name;

    gestion_page_tab *gestionPageTab = new gestion_page_tab(image, sound, type1, type2, description, name);
    ui->tabWidget->addTab(gestionPageTab, name);

    // Définir le drapeau sur true pour indiquer que les informations ont été traitées
    informationProcessed = true;
}

void MainWindow::on_Quitter_button_clicked()
{
    QApplication::quit();
}

void MainWindow::on_Gestion_button_clicked()
{
    gestion_page *gestionpage = new gestion_page(this);
    ui->tabWidget->addTab(gestionpage, "Gestion des pages");
    ui->tabWidget->setCurrentWidget(gestionpage);
}
