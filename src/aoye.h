#ifndef THING_H
#define THING_H
#include<QPixmap>

class aoye
{
public:
    aoye();
    //更新坐标
    void updatePosition();

    //东西资源对象
    QPixmap m_aoye;

    //位置
    int m_x;
    int m_y;

    //东西的矩形边框（碰撞检测）
    QRect m_Rect;

    //状态
    bool m_free;

    //速度
    int m_speed;


};

#endif // THING_H
