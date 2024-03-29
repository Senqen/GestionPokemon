#include "gestion_page.h"
#include "ui_gestion_page.h"
#include "gestion_page_tab.h"

gestion_page::gestion_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_page)
{
    ui->setupUi(this);
}

gestion_page::~gestion_page()
{
    delete ui;
}

void gestion_page::addTab(const QPixmap& image, const QUrl& sound, const QString& type1, const QString& type2, const QString& description, const QString& name)
{
    gestion_page_tab *tab = new gestion_page_tab(image, sound, type1, type2, description, name, this);
    ui->tabWidget->addTab(tab, name);
}
