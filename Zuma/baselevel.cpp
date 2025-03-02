#include "baselevel.h"

baselevel::baselevel(QWidget *parent)
    : QWidget{parent}
{
    //ballColors初始化颜色集合
    ballColors<<Qt::red<<Qt::green<<Qt::yellow<<Qt::blue<<Qt::magenta;
    //炮台的位置
    cannonPos=QPointF(width()/2,height()-50);
    //gameTimer初始化
    gameTimer=new QTimer(this);
    //用QTimer来控制运动的时间间隔
    connect(gameTimer,&QTimer::timeout,[this](){
        moveBalls();
        update();
    });
    gameTimer->start(16);
    generateNewBall();
}

void baselevel::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//平滑
    painter.setPen(Qt::darkGray);//轨道颜色
    painter.drawPath(getPath());//绘制轨道
    //炮台的绘制
    painter.save();
    painter.translate(cannonPos);
    painter.rotate(cannonRotation);
    painter.setBrush(Qt::gray);
    painter.drawRect(-10,-20,20,40);
    painter.restore();
    //炮台上的球
    painter.setBrush(ballColorOnCannon);
    painter.drawEllipse(cannonPos,15,15);
    //轨道上的球
    for(const auto& ball:ballsOnTrack)
    {
        painter.setBrush(ball.color);
        painter.drawEllipse(ball.position,10,10);
    }
}

void baselevel::mouseMoveEvent(QMouseEvent*event)
{
    QPointF delta=event->pos()-cannonPos;
    cannonRotation=qRadiansToDegrees(atan2(delta.y(),delta.x()))+90;
    update();
}

void baselevel::mousePressEvent(QMouseEvent*)
{
    MovingBall newball;
    newball.color=ballColorOnCannon;
    newball.position=cannonPos;
    newball.pathIndex=0;
    ballsOnTrack.append(newball);
    generateNewBall();
}

void baselevel::generateNewBall()
{
    ballColorOnCannon=ballColors[QRandomGenerator::global()->bounded(ballColors.size())];
}

void baselevel::moveBalls()
{
    if(pathpoints.isEmpty()) return;
    for(auto& ball:ballsOnTrack)
    {
        if(ball.pathIndex<pathpoints.size()-1)
        {
            ball.pathIndex+=getBallSpeed();
            ball.position=pathpoints[qMin(ball.pathIndex,pathpoints.size()-1)];
        }
    }
    checkCollisions();
}

void baselevel::checkCollisions()
{
    for(int i=0;i<ballsOnTrack.size();i++)
    {
        for(int j=i+1;j<ballsOnTrack.size();j++)
        {
            if(QLineF(ballsOnTrack[i].position,ballsOnTrack[j].position).length()<20)
            {
                int insertPos=i+1;
                ballsOnTrack.move(j,insertPos);
                removeConsecutiveBalls(insertPos);
                return;
            }
        }
    }
}

void baselevel::removeConsecutiveBalls(int index)
{
    int start=index;
    int end=index;
    QColor color=ballsOnTrack[index].color;
    while(start>0&&ballsOnTrack[start-1].color==color) start--;
    while(end<ballsOnTrack.size()&&ballsOnTrack[end+1].color==color) end--;

    if(end-start+1>=3)
    {
        ballsOnTrack.erase(ballsOnTrack.begin()+start,ballsOnTrack.begin()+end+1);
    }
}

void baselevel::updatePathPoints()
{
    pathpoints.clear();
    QPainterPath path=getPath();
    for(qreal t=0;t<=1.0;t+=0.001)
    {
        pathpoints.append(path.pointAtPercent(t));
    }
}

