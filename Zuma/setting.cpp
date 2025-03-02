#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::setting)
{
    ui->setupUi(this);
    //标题修改
    this->setWindowTitle("Setting");
    //设置页面的背景图设置
    QPixmap p("D:\\qtcode\\Zuma\\image2.jpg");
    ui->imagelabel2->setPixmap(p);
}

setting::~setting()
{
    delete ui;
}
