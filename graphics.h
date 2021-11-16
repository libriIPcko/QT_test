#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>

namespace Ui {
class Graphics;
}

class Graphics : public QDialog
{
    Q_OBJECT

public:
    explicit Graphics(QWidget *parent = nullptr);
    ~Graphics();
private: signals:
    //void timerTest_SLOT();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Graphics *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
    QGraphicsLineItem *line;
    QTimer *timerTest;


};

#endif // GRAPHICS_H
