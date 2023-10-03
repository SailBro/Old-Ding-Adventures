#ifndef DT_H
#define DT_H

#include <QMainWindow>
#include<QTimer>
#include"map.h"
#include<ding.h>
#include"thing.h"
#include<config.h>


QT_BEGIN_NAMESPACE
namespace Ui { class DT; }
QT_END_NAMESPACE

class DT : public QMainWindow
{
    Q_OBJECT

public:

    DT(QWidget *parent= nullptr);
    ~DT();

    //
    void showbutton();

    //初始化场景
    void initscene();

    //启动游戏
    void playGame();

    //更新坐标
    void updatePosition();

    //绘制到屏幕
    void paintEvent(QPaintEvent*);

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent*);

    //thing出场
    void thingtoscene();

    //碰撞检测
    void detect();

    //thing数组
    thing ts[20];

    //thing出场间隔
    int m_recorder;

    //地图对象
    map m_map;

    //老头对象
    DING m_ding;

    //定时器
    QTimer m_Timer;

   //
    int ifrunbutton;
};
#endif // DT_H
