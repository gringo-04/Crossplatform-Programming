#ifndef MAINWINDOW_H

#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMessageBox>
#include <QLabel>

namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow

{
    Q_OBJECT
    public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    private slots:
    void Push();
    void Pop();
    void Find();
    private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
