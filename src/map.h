#ifndef MAP_H
#define MAP_H
#include<QPixmap>

class map
{
public:
    map();

    //地图滚动坐标计算
    void mapPosition();

    //地图图片对象
    QPixmap map1;
    QPixmap map2;

    //地图Y轴坐标
    int y1;
    int y2;

    //地图滚动幅度
    int map_speed;

};

#endif // MAP_H
