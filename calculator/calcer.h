#ifndef CALCER_H
#define CALCER_H

#include <QMainWindow>
#include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class calcer; }
QT_END_NAMESPACE

class calcer : public QMainWindow
{
    Q_OBJECT

public:
    calcer(QWidget *parent = nullptr);
    ~calcer();
    bool ss;
protected:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void pushn0();
    void pushn1();
    void pushn2();
    void pushn3();
    void pushn4();
    void pushn5();
    void pushn6();
    void pushn7();
    void pushn8();
    void pushn9();
    void pushjia();
    void pushjian();
    void pushcheng();
    void pushchu();
    void pushdy();
    void pushl();
    void pushr();
    //double calc();
private:
    Ui::calcer *ui;
};
#endif // CALCER_H
