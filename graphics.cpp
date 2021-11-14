#include "graphics.h"
#include "ui_graphics.h"

QGraphicsScene *scene;


Graphics::Graphics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphics)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

Graphics::~Graphics()
{
    delete ui;
}

void Graphics::on_pushButton_clicked()
{
    scene->addText("Hello World");
    //abrakadabra Bobov update
    //Tuto si intenzivne programujem
    //TisickyRiadkov narocneho kodu,
    //zabazpecujem intezivnu robotu
    //okamzite si to zmen!
	//blablabla
}

