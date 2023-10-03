#ifndef DING_H
#define DING_H
#include<QPixmap>
#include<QRect>

class DING
{
public:
    DING();

    //设置老头位置
    void setPosition(int x,int y);

    //老头资源对象
    QPixmap d;

    //老头坐标
    int m_x;
    int m_y;

    //老头矩形边框
    QRect m_Rect;

    //老头头发数量
    float num;

    //头发数量变化
    void ding_add();
    void ding_minus();
    //头发增/减
    int state;//(0,1,2)对应（不变，增，减）

};

#endif // DING_H
