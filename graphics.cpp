#include "graphics.h"
#include "ui_graphics.h"


float radius = 0.001;
bool increment = true;

Graphics::Graphics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphics)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedHeight(500);
    ui->graphicsView->setFixedWidth(700);
    ui->graphicsView->setMaximumHeight(500);
    ui->graphicsView->setMaximumWidth(700);

    timerTest = new QTimer(this);
    timerTest->setInterval(300);
    connect(timerTest,&QTimer::timeout,this,&Graphics::timer_Event);
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

    int x = 100;
    int y = 100;
    double rad = 1;
    scene->addEllipse(x-rad, y-rad, rad*2.0, rad*2.0,
                QPen(), QBrush(Qt::SolidPattern));


}


void Graphics::timer_Event(){

}


void Graphics::on_lineEdit_textEdited(const QString &arg1)
{
    scene->clear();
    int MaxPoints = ui->lineEdit->text().toInt();
    QRandomGenerator rand;
    //rand.bounded(150);
    for(int n=1;n<=MaxPoints;n++){
        //int x = rand.generate();
        int x = QRandomGenerator::global()->bounded(ui->graphicsView->width());
        int y = QRandomGenerator::global()->bounded(ui->graphicsView->height());
        double rad = 1;
        scene->addEllipse(x-rad, y-rad, rad*2.0, rad*2.0,
                    QPen(), QBrush(Qt::SolidPattern));

        QString data = QObject::tr(" X -> ")
                       +QString::number(x)
                       +QObject::tr(" Y -> ")
                       +QString::number(y);
                       //+QObject::tr("\n");
        ui->textBrowser->append(data);
    }

}

