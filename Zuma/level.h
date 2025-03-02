#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include "firstpoint.h"
namespace Ui {
class level;
}

class level : public QWidget
{
    Q_OBJECT

public:
    explicit level(QWidget *parent = nullptr);
    ~level();

private slots:
    void on_pushButton_1_clicked();

private:
    Ui::level *ui;
    firstpoint *f1;
};

#endif // LEVEL_H
