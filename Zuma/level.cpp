#include "level.h"
#include "ui_level.h"

level::level(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::level)
{
    ui->setupUi(this);
    //标题修改
    this->setWindowTitle("Level");
    //选关页面的背景图设置
    QPixmap p("D:\\qtcode\\Zuma\\image3.jpg");
    ui->imagelabel3->setPixmap(p);
    //第一关初始化
    f1=new firstpoint;
}

level::~level()
{
    delete ui;
}

void level::on_pushButton_1_clicked()
{
    this->hide();
    f1->show();
}
