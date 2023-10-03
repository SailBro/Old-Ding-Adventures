#include "map.h"
#include"config.h"

map::map()
{
    //初始化地图对象
    map1.load(":/im/b.jpg");
    map2.load(":/im/b.jpg");

    //初始化y轴坐标
    y1=-GAME_HEIGHT;
    y2=0;

    //地图滚动速度
    map_speed=MAP_SPEED;

}
void map::mapPosition()
{
    //处理第一张滚动位置
    y1+=map_speed;
    if(y1>=0)
    {
        y1=-GAME_HEIGHT;
    }
    //处理第二张
    y2+=map_speed;
    if(y2>=GAME_HEIGHT)
    {
        y1=0;
    }
}




