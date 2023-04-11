#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QRectF>
#include <QSize>
#include <QString>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event)
{


    QPainter painter(this);
    QRect rect(startArea, blockSize);

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                painter.setFont(QFont("Times", 16, QFont::Bold));
                painter.drawText(QPoint(70 + rect.width() * i, 30), QString(mas[i]));
                painter.drawText(QPoint(10, 90 + rect.height() * j), QString().asprintf("%d", 8 - j));
                QRect rect1 = rect.translated(rect.width() * i, rect.height() * j);
                painter.fillRect(rect1, (i + j) % 2 ==0 ? Qt::black : Qt::white);
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton) {
        int a = (event->y() - startArea.y()) / 80;
        int b = (event->x() - startArea.x()) / 80;
        qDebug("A: %d", a);
        // qDebug() << QString(mas[b]);
        qDebug("A: %d", b);
        QMessageBox::information(this, QString("Информация"), QString().asprintf("%c%d", "ABCDEFGH"[b], 8-a));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

