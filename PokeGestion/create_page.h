#ifndef CREATE_PAGE_H
#define CREATE_PAGE_H

#include <QDialog>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox> // Include QMessageBox header

namespace Ui {
class Create_Page;
}

class Create_Page : public QDialog
{
    Q_OBJECT

public:
    explicit Create_Page(QWidget *parent = nullptr);
    ~Create_Page();

signals:
    void informationEntered(const QPixmap& image, const QUrl& sound, const QString& type1, const QString& type2, const QString& description, const QString& name);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_validate_clicked();

private:
    Ui::Create_Page *ui;
    QMediaPlayer *player;
    bool soundSelected;
    QPixmap selectedImage;
    QUrl selectedSound;
    QString selectedType1;
    QString selectedType2;
    QString description;
    QString name;

    void setImage(const QPixmap& pixmap);
    void setSound(const QUrl& url);
    void setType1(const QString& type);
    void setType2(const QString& type);
    void setDescription(const QString& desc);
    void setName(const QString& n);
};

#endif // CREATE_PAGE_H
