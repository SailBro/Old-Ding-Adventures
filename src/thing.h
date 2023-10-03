#ifndef THING_H
#define THING_H
#include<QPixmap>

class thing
{
public:
    thing();

    //类型
    int type;
    //类型设定
    void settype(int n);
    //更新坐标
    void updatePosition();

    //东西资源对象
    QPixmap m_thing;

    //位置
    int m_x;
    int m_y;

    //东西的矩形边框（碰撞检测）
    QRect m_Rect;

    //状态
    bool m_free;

    //速度
    int m_speed;

    //更新时能否改变
    bool m_change;

};

#endif // THING_H
