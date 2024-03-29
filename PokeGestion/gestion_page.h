#ifndef GESTION_PAGE_H
#define GESTION_PAGE_H

#include <QMainWindow>
#include <QTabWidget>
#include <QPixmap>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class gestion_page; }
QT_END_NAMESPACE

class gestion_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_page(QWidget *parent = nullptr);
    ~gestion_page();

    void addTab(const QPixmap& image, const QUrl& sound, const QString& type1, const QString& type2, const QString& description, const QString& name);

private:
    Ui::gestion_page *ui;
};

#endif // GESTION_PAGE_H
