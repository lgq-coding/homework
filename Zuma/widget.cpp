#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //标题修改
    this->setWindowTitle("Zuma");
    //开始页面的背景图设置
    QPixmap p("D:\\qtcode\\Zuma\\image1.jpg");
    ui->imagelabel1->setPixmap(p);
    //标签、按键的样式设置（圆角，颜色，透明度）
    ui->label->setStyleSheet("color:gold");
    ui->startButton->setStyleSheet("border-radius: 15px; background-color:rgba(197,149,103,0.4)");
    ui->settingButton->setStyleSheet("border-radius: 10px; background-color:rgba(197,149,103,0.4)");
    ui->exitButton->setStyleSheet("border-radius: 10px; background-color:rgba(197,149,103,0.4)");
    //设置页面与选关界面初始化
    s=new setting;
    l=new level;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_exitButton_clicked()//按exit键后关闭当前页面
{
    QMessageBox::StandardButton result=QMessageBox::question(this,"提示","确定要离开吗？");//防误触操作
    if(result==QMessageBox::Yes) this->close();
}

void Widget::on_settingButton_clicked()//按setting键后进入设置界面
{
    s->show();
}

void Widget::on_startButton_clicked()//按start键后跳转到选关界面
{
    l->show();
}




