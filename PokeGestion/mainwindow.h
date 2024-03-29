#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Create_button_clicked();
    void on_Quitter_button_clicked();
    void on_Gestion_button_clicked();
    void handleInformationEntered(const QPixmap& image, const QUrl& sound, const QString& type1, const QString& type2, const QString& description, const QString& name);

private:
    Ui::MainWindow *ui;
    QTabWidget *tabWidget;
    bool informationProcessed;
};
#endif // MAINWINDOW_H
