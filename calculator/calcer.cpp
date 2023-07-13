#include "calcer.h"
#include "./ui_calcer.h"
#include "calcero.h"
calcer::calcer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calcer)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit2->setReadOnly(true);
    ui->textEdit->setText("0");
    ui->textEdit2->setText("0");
    ss=0;
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
    connect(ui->pushb,&QPushButton::clicked,this,&calcer::pushb);
    connect(ui->pushc,&QPushButton::clicked,this,&calcer::pushc);
}
void calcer::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Alt:
            ui->textEdit->setText(ui->textEdit2->toPlainText());
            ui->textEdit2->setText("0");
            break;
    }
}
void calcer::pushb(){
    QString s=ui->textEdit->toPlainText();
    QChar c=*(s.end()-1);
    s.erase(s.end()-1);
    if(c=='(')ss=0;
    if(c==')')ss=1;
    ui->textEdit->setText(s);
    return;
}
void calcer::pushc(){
    ui->textEdit->setText("0");
    ui->textEdit2->setText("0");
    ss=0;
    return;
}
void calcer::pushn0(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='0';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn1(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='1';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn2(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='2';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn3(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='3';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn4(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='4';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn5(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='5';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn6(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='6';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn7(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='7';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn8(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='8';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushn9(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    s+='9';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushjia(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    if(s.isEmpty())return;
    QChar a=s[s.length()-1];
    if(a.isDigit())
        s+='+';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushjian(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    /*QChar a=s[s.length()-1];
    if(a.isDigit())*/
    s+='-';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushcheng(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    QChar a=s[s.length()-1];
    if(a.isDigit())
        s+='*';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushchu(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    QChar a=s[s.length()-1];
    if(a.isDigit())
        s+='/';
    ui->textEdit->setText(s);
    return;
}
bool calcer::check(std::string *s){
    using namespace std;
    string a=*s;
    bool ret=1;
    int cnt=0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='-'){
            if(i==0)a.insert(1,1,'0');
            else if(a[i-1]=='(')a.insert(i,1,'0');
        }
        if(a[i]=='('||a[i]==')')cnt++;
        if(i==a.length()-1)
            if(!isdigit(a[i]))ret=0;
    }
    if(cnt%2==1)ret=0;
    *s=a;
    cout<<a<<endl;
    return ret;
}
void calcer::pushdy(){
    calcs a;
    std::string s=ui->textEdit->toPlainText().toStdString();
    bool ret=1;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            if(i==0)s.insert(0,1,'0');
            else if(s[i-1]=='(')s.insert(i,1,'0');
        }
    }
    std::cout<<s<<std::endl;
    a.mid2last(s);
    s=a.calc();
    ui->textEdit->setText(ui->textEdit->toPlainText()+'=');
    QString k=QString::fromStdString(s);
    ui->textEdit2->setText(k);
    return;
}
void calcer::pushl(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    if(!ss){
        s+='(';
        ss=1;
    }
    ui->textEdit->setText(s);
    return;
}
void calcer::pushr(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    if(ss){
        s+=')';
        ss=0;
    }
    ui->textEdit->setText(s);
    return;
}
calcer::~calcer()
{
    delete ui;
}

