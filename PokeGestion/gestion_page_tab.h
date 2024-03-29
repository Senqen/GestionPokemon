#ifndef GESTION_PAGE_TAB_H
#define GESTION_PAGE_TAB_H

#include <QWidget>
#include <QPixmap>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class gestion_page_tab; }
QT_END_NAMESPACE


class gestion_page_tab : public QWidget {
    Q_OBJECT

public:
    explicit gestion_page_tab(const QPixmap& image, const QUrl& sound, const QString& type1, const QString& type2, const QString& description, const QString& name, QWidget *parent = nullptr);
    ~gestion_page_tab();

private:
    Ui::gestion_page_tab *ui;
};


#endif // GESTION_PAGE_TAB_H
