#include "thing.h"
#include "config.h "

thing::thing()
{

  //默认无参构造时
    type=0;
    m_thing.load(":/im/bawang1.png");

    //东西位置
    m_x=0;
    m_y=0;

   //状态
   m_free=true;

   //改变态
   m_change=1;

   //速度
   m_speed=THING_SPEED;

   //东西矩形框（碰撞检测）
   m_Rect.setWidth(m_thing.width());
   m_Rect.setHeight(m_thing.height());
   m_Rect.moveTo(m_x,m_y);
}
void thing::updatePosition()
{
    //空闲状态 不计算坐标
    if(m_free)return ;
    m_y+=m_speed;
    m_Rect.moveTo(m_x,m_y);
    //超出屏幕，重置空闲状态
    if(m_y>=GAME_HEIGHT+m_Rect.height())
        m_free=true;

}
void thing::settype(int n)
{
   switch (n)
   {
   case 0:
       type=0;
       m_thing.load(":/im/bawang1.png");
       break;
   case 1:
       type=1;
       m_thing.load(":/im/zhifa1.png");
       break;
   case 2:
       type=2;
       m_thing.load(":/im/daima1.png");
       break;
   case 3:
       type=3;m_thing.load(":/im/aoye1.png");
       break;
   default:
       break;
   }

}



