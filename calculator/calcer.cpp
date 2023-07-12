#include "calcer.h"
#include "./ui_calcer.h"

calcer::calcer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calcer)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setText("0");
    connect(ui->pushn0,&QPushButton::clicked,this,&calcer::pushn0);
    connect(ui->pushn1,&QPushButton::clicked,this,&calcer::pushn1);
    connect(ui->pushn2,&QPushButton::clicked,this,&calcer::pushn2);
    connect(ui->pushn3,&QPushButton::clicked,this,&calcer::pushn3);
    connect(ui->pushn4,&QPushButton::clicked,this,&calcer::pushn4);
    connect(ui->pushn5,&QPushButton::clicked,this,&calcer::pushn5);
    connect(ui->pushn6,&QPushButton::clicked,this,&calcer::pushn6);
    connect(ui->pushn7,&QPushButton::clicked,this,&calcer::pushn7);
    connect(ui->pushn8,&QPushButton::clicked,this,&calcer::pushn8);
    connect(ui->pushn9,&QPushButton::clicked,this,&calcer::pushn9);
    connect(ui->pushjia,&QPushButton::clicked,this,&calcer::pushjia);
    connect(ui->pushjian,&QPushButton::clicked,this,&calcer::pushjian);
    connect(ui->pushcheng,&QPushButton::clicked,this,&calcer::pushcheng);
    connect(ui->pushchu,&QPushButton::clicked,this,&calcer::pushchu);
    connect(ui->pushdy,&QPushButton::clicked,this,&calcer::pushdy);
    connect(ui->pushl,&QPushButton::clicked,this,&calcer::pushl);
    connect(ui->pushr,&QPushButton::clicked,this,&calcer::pushr);
}
void calcer::pushn0(){
    return;
}
void calcer::pushn1(){
    return;
}
void calcer::pushn2(){
    return;
}
void calcer::pushn3(){
    return;
}
void calcer::pushn4(){
    return;
}
void calcer::pushn5(){
    return;
}
void calcer::pushn6(){
    return;
}
void calcer::pushn7(){
    return;
}
void calcer::pushn8(){
    return;
}
void calcer::pushn9(){
    return;
}
void calcer::pushjia(){
    return;
}
void calcer::pushjian(){
    return;
}
void calcer::pushcheng(){
    return;
}
void calcer::pushchu(){
    return;
}
void calcer::pushdy(){
    return;
}
void calcer::pushl(){
    return;
}
void calcer::pushr(){
    return;
}
calcer::~calcer()
{
    delete ui;
}

