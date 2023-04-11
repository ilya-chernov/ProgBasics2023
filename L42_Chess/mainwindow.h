#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QSize>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString mas[8] = {
      "A", "B", "C", "D", "E", "F", "G", "H"
    };
    QPoint startArea = QPoint(40, 40);
    QSize blockSize = QSize(80, 80);
};
#endif // MAINWINDOW_H
