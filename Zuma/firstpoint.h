#ifndef FIRSTPOINT_H
#define FIRSTPOINT_H

#include <QWidget>
#include <QMessageBox>
#include "setting.h"
#include "baselevel.h"

namespace Ui {
class firstpoint;
}

class firstpoint : public baselevel
{
    Q_OBJECT

public:
    explicit firstpoint(QWidget *parent = nullptr);
    ~firstpoint();
    QPainterPath getPath() const override ;
    int getBallSpeed() const override {return 3;};
    void paintEvent(QPaintEvent*event) override;

private slots:
    void on_levelButton_clicked();
    void on_settingButton_clicked();

private:
    Ui::firstpoint *ui;
    setting *s;
};

#endif // FIRSTPOINT_H
