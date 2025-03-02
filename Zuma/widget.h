#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "setting.h"
#include "level.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_exitButton_clicked();

    void on_startButton_clicked();

    void on_settingButton_clicked();

private:
    Ui::Widget *ui;
    setting *s;
    level *l;
};
#endif // WIDGET_H
