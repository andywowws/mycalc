#include "calcer.h"
#include "./ui_calcer.h"
#include "calcero.h"
calcer::calcer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calcer)
{
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(392,581);
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit2->setReadOnly(true);
    ui->textEdit->setText("0");
    ui->textEdit2->setText("0");
    ss=0;
    connect(ui->pushe,&QPushButton::clicked,this,&calcer::pushe);
    connect(ui->pushpi,&QPushButton::clicked,this,&calcer::pushpi);
    connect(ui->pushx2,&QPushButton::clicked,this,&calcer::pushx2);
    connect(ui->pushxn,&QPushButton::clicked,this,&calcer::pushxn);
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
    connect(ui->pushnd,&QPushButton::clicked,this,&calcer::pushnd);
}
void calcer::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Alt:
            if(ui->textEdit2->toPlainText()!="E"){
                ui->textEdit->setText(ui->textEdit2->toPlainText());
                ui->textEdit2->setText("0");
            }
            break;
    }
    if(event->modifiers() == Qt::ControlModifier) { // 如果按下了CTRL键
        if(event->key() == Qt::Key_V){
            QClipboard *clip=QApplication::clipboard();
            QString sa=clip->text();
            std::string s=sa.toStdString();
            bool w=1;
            int k1=0,k2=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='(')k1++;
                if(s[i]==')'){
                    if(k1==0){w=0;break;}
                    k2++;
                }
                if(!(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='('||s[i]==')'||s[i]=='.'||isdigit(s[i]))){w=0;break;}
            }
            calcs an;
            if(k1!=k2&&w)s=an.rmbrt(s);
            if(!w)QMessageBox::warning(this, "错误","无效输入");
            if(w)ui->textEdit->setText(QString::fromStdString(s));
        }
    }
}
void calcer::pushxn(){
    QString s=ui->textEdit->toPlainText();
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
    QChar a=s[s.length()-1];
    if(a=='.')s.erase(s.end()-1);
    a=s[s.length()-1];
    if(a.isDigit()||a==')')
        s+='^';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushe(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    if(!s.isEmpty()){
        QChar a=s.back();
        bool x=0;
        if(a=='='){s.erase(s.end()-1);x=1;}
        a=s.back();
        if(!(a.isDigit()||a=='.'))s+="2.7182818284590452353602874713527";
        else if(x)s+='=';
    }else s="2.7182818284590452353602874713527";
    ui->textEdit->setText(s);
    return;
}
void calcer::pushpi(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")s="";
    if(!s.isEmpty()){
        QChar a=s.back();
        bool x=0;
        if(a=='='){s.erase(s.end()-1);x=1;}
        a=s.back();
        if(!(a.isDigit()||a=='.'))s+="3.1415926535897932384626433832795";
        else if(x)s+='=';
    }else s="3.1415926535897932384626433832795";
    ui->textEdit->setText(s);
    return;
}
void calcer::pushx2(){
    QString s=ui->textEdit->toPlainText();
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
    QChar a=s[s.length()-1];
    if(a=='.')s.erase(s.end()-1);
    a=s[s.length()-1];
    if(a.isDigit()||a==')')
        s+="^2";
    ui->textEdit->setText(s);
    return;
}
void calcer::pushb(){
    QString s=ui->textEdit->toPlainText();
    if(s=="0")return;
    QChar c=*(s.end()-1);
    s.erase(s.end()-1);
    if(c=='(')ss=0;
    if(c==')')ss=1;
    if(s.isEmpty())s="0";
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
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
    QChar a=s[s.length()-1];
    if(a=='.')s.erase(s.end()-1);
    a=s[s.length()-1];
    if(a.isDigit())
        s+='+';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushjian(){
    QString s=ui->textEdit->toPlainText();
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
    if(s=="0"){ui->textEdit->setText("-");return;}
    else{
        QChar a=s[s.length()-1];
        if(a=='.')s.erase(s.end()-1);
    }
    /*QChar a=s[s.length()-1];
    if(a.isDigit())*/
    QChar a=s[s.length()-1];
    if(a.isDigit()||a=='(')s+='-';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushcheng(){
    QString s=ui->textEdit->toPlainText();
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
    QChar a=s[s.length()-1];
    if(a=='.')s.erase(s.end()-1);
    a=s[s.length()-1];
    if(a.isDigit())
        s+='*';
    ui->textEdit->setText(s);
    return;
}
void calcer::pushchu(){
    QString s=ui->textEdit->toPlainText();
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
    if(s=="0"){s+='/';}
    else{
        QChar a=s[s.length()-1];
        if(a=='.')s.erase(s.end()-1);
            a=s[s.length()-1];
        if(a.isDigit())
            s+='/';
    }
    ui->textEdit->setText(s);
    return;
}
void calcer::pushnd(){
    QString s=ui->textEdit->toPlainText();
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
    QChar a=*(s.end()-1);
    bool able=1;
    for(int i=s.length()-1;i>=0;i--){
        if(!(s[i].isDigit()||s[i]=='.'))break;
        if(s[i]=='.'){able=0;break;}
    }
    if(a.isDigit()&&able)s+='.';
    ui->textEdit->setText(s);
}
void calcer::pushdy(){
    calcs a;
    std::string s=ui->textEdit->toPlainText().toStdString();
    if(s[s.length()-1]=='=')s.pop_back();
    if(s[s.length()-1]=='.')s.erase(s.end()-1);
    if(!isdigit(s.back())&&s.back()!='('){
        if(s.back()=='^')s+='1';
        else if(s.back()!=')')s+='0';
    }
    int cnt=0,cnt2=0;
    bool stt=1;
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i])&&s[i]!='.')stt=0;
        if(stt&&s[i]=='.'){
            cnt2++;
            if(cnt2>1){s.erase(i,1);cnt2--;}
        }
        /*if(s[i]=='-'){
            if(i==0)s.insert(0,1,'0');
            else if(s[i-1]=='(')s.insert(i,1,'0');
        }*/
        if(s[i]=='('||s[i]==')')cnt++;
    }
    if(cnt%2!=0)s+=')';
    std::cout<<s<<std::endl;
    a.mid2last(s);
    QString y=QString::fromStdString(s);
    y+='=';
    s=a.calc();
    ui->textEdit->setText(y);
    QString k=QString::fromStdString(s);
    ui->textEdit2->setText(k);
    return;
}
void calcer::pushl(){
    QString s=ui->textEdit->toPlainText();
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
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
    if(s[s.length()-1]=='=')s.erase(s.end()-1);
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

