#include "ding.h"
#include"config.h"
#include<QPainter>
#include<dt.h>

DING::DING()
{
   //初始化加载图片资源
    d.load(":/im/h.png");
    //初始化老头坐标
    m_x=(GAME_WIDTH-d.width())/2;
    m_y=GAME_HEIGHT-d.height();

    //初始化矩形边框
    m_Rect.setWidth(d.width());
    m_Rect.setHeight(d.height());
    m_Rect.moveTo(m_x,m_y);

    //初始化老头头发数量
    num=3;
}
void DING::setPosition(int x, int y)
{

    m_x=x;
    m_y=y;
    m_Rect.moveTo(m_x,m_y);

}
void DING::ding_add()
{
    num++;
    state=1;//该+
}
void DING::ding_minus()
{
    num--;
    state=2;//该-
}




