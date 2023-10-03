#include "aoye.h"
#include "config.h "
aoye::aoye()
{
  //东西资源加载
    m_aoye.load(":/im/aoye1.png");
    //东西位置
    m_x=0;
    m_y=0;

   //状态
   m_free=true;

   //速度
   m_speed=THING_SPEED;

   //东西矩形框（碰撞检测）
   m_Rect.setWidth(m_aoye.width());
   m_Rect.setHeight(m_aoye.height());
   m_Rect.moveTo(m_x,m_y);
}
void aoye::updatePosition()
{
    //空闲状态 不计算坐标
    if(m_free)return ;
    m_y+=m_speed;
    m_Rect.moveTo(m_x,m_y);
    //超出屏幕，重置空闲状态
    if(m_y>=GAME_HEIGHT+m_Rect.height())
        m_free=true;

}

