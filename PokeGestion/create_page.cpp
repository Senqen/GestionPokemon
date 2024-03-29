#include "create_page.h"
#include "ui_create_page.h"
#include <QMessageBox>

Create_Page::Create_Page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create_Page),
    player(new QMediaPlayer(this)),
    soundSelected(false)
{
    ui->setupUi(this);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(false);

    connect(ui->pushButton, &QPushButton::clicked, this, &Create_Page::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Create_Page::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Create_Page::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Create_Page::on_pushButton_4_clicked);
    connect(ui->pushButton_validate, &QPushButton::clicked, this, &Create_Page::on_pushButton_validate_clicked);
}

Create_Page::~Create_Page()
{
    delete ui;
    delete player;
}

void Create_Page::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Choose an Image"), QString(), tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (!filePath.isEmpty()) {
        QPixmap pixmap(filePath);
        if (!pixmap.isNull()) {
            setImage(pixmap);
            ui->pushButton->setVisible(false);
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Failed to load the image."));
        }
    }
}

void Create_Page::on_pushButton_2_clicked()
{
    emit informationEntered(selectedImage, selectedSound, selectedType1, selectedType2, description, name);
    this->hide();
}

void Create_Page::on_pushButton_validate_clicked()
{
    // Récupérer les informations saisies par l'utilisateur
    QPixmap image = ui->label->pixmap();
    QUrl sound = selectedSound;
    QString type1 = ui->comboBox_type1->currentText();
    QString type2 = ui->comboBox_type2->currentText();
    QString description = ui->plainTextEdit_description->toPlainText();
    QString name = ui->lineEdit_name->text();

    // Émettre le signal informationEntered avec les informations saisies
    emit informationEntered(image, sound, type1, type2, description, name);

    // Fermer la fenêtre Create_Page
    this->close();
}

void Create_Page::setImage(const QPixmap& pixmap)
{
    ui->label->setPixmap(pixmap);
    ui->label->setScaledContents(true);
}

void Create_Page::setSound(const QUrl& url)
{
    selectedSound = url;
}

void Create_Page::setType1(const QString& type)
{
    selectedType1 = type;
}

void Create_Page::setType2(const QString& type)
{
    selectedType2 = type;
}

void Create_Page::setDescription(const QString& desc)
{
    description = desc;
}

void Create_Page::setName(const QString& n)
{
    name = n;
}

void Create_Page::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Sound File"), "", tr("Sound Files (*.wav *.mp3)"));
    if (!fileName.isEmpty()) {
        QUrl fileUrl = QUrl::fromLocalFile(fileName);
        setSound(fileUrl);
        player->setSource(fileUrl);
        player->play();
        soundSelected = true;
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(true);
    }
}

void Create_Page::on_pushButton_4_clicked()
{
    player->play();
}
