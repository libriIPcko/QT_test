#include "graphics.h"
#include "ui_graphics.h"




Graphics::Graphics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphics)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

Graphics::~Graphics()
{
    delete ui;
}

void Graphics::on_pushButton_clicked()
{    
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);

    //rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);
    // addEllipse(x,y,w,h,pen,brush)
    //ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);
    //text = scene->addText("Hello World", QFont("Arial", 20) );
    //line = scene->addLine(0,0,ui->graphicsView->width(),ui->graphicsView->height(),QPen(Qt::black));
    //line = scene->addLine(20,30,Graphics::width(),Graphics::height(),QPen(Qt::black));
    //Create Axis
    int num_Axis = 5;
    for(int n=0;n<5;n++){
        QPen axisPen(Qt::gray);
        axisPen.setWidth(1);
        axisPen.setDashOffset(1);
        axisPen.setStyle(Qt::DotLine);
        //Horizontal
        scene->addLine(0,(n*ui->graphicsView->height()/num_Axis),ui->graphicsView->width(),(n*ui->graphicsView->height()/num_Axis),axisPen);
        //Vertical
        scene->addLine((n*ui->graphicsView->width()/num_Axis),0,(n*ui->graphicsView->width()/num_Axis),ui->graphicsView->height(),axisPen);
    }
    //dot generator
    //put dot
    float radius = 0.000000000000000001;
    float radius2 = 0.0000001;
    float radius_1 = 0.0001;
    QPen pointPen(Qt::black);
    pointPen.setWidth(0);
    QBrush pointBrush(Qt::transparent);

    scene->addEllipse(20-radius,20-radius,20+radius,20+radius,pointPen,pointBrush);
    scene->addEllipse(40-radius2,40-radius2,40+radius2,40+radius2,pointPen,pointBrush);
    scene->addEllipse(80-radius_1,80-radius_1,80+radius_1,80+radius_1,pointPen,pointBrush);
    //scene->addItem(QGraphicsEllipseItem::setRect(20,20,21,21));


}

