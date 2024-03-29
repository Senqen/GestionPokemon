#include "gestion_page_tab.h"
#include "ui_gestion_page_tab.h"

gestion_page_tab::gestion_page_tab(const QPixmap &image, const QUrl &sound, const QString &type1, const QString &type2, const QString &description, const QString &name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_page_tab)
{
    ui->setupUi(this);
    // set the received information
    ui->label_image->setPixmap(image);
    ui->label_type1->setText(type1);
    ui->label_type2->setText(type2);
    ui->textEdit_description->setPlainText(description);
    ui->label_name->setText(name);
    //son
}



gestion_page_tab::~gestion_page_tab()
{
    delete ui;
}

