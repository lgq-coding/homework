#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QWidget>//使用信号与槽

// #include <QGraphicsScene>
// #include <QPixmap>
#include <QPainterPath>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include <QTimer>
#include <QList>
#include <cmath>
#include <QRandomGenerator>
class baselevel : public QWidget
{
    Q_OBJECT
public:
    explicit baselevel(QWidget *parent = nullptr);
    virtual QPainterPath getPath() const=0;//轨道路径
    virtual int getBallSpeed() const {return 2;};//球速
    //各事件虚函数重写
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    struct MovingBall//球
    {
        QPointF position;
        QColor color;
        int pathIndex;
    };
    QList<MovingBall> ballsOnTrack;//轨道上的球的集合
    QList<QColor> ballColors;//球的颜色
    QPointF cannonPos;//炮台位置
    QColor ballColorOnCannon;//炮台上的球的颜色
    double cannonRotation;//炮台的旋转角度

    void generateNewBall();//产生新球
    void checkCollisions();//是否发生碰撞的检测
    void removeConsecutiveBalls(int index);//清除连续的球（3个及以上）

    QTimer*gameTimer;
    QList<QPointF> pathpoints;

    void updatePathPoints();
    void moveBalls();

signals:
};

#endif // BASELEVEL_H
