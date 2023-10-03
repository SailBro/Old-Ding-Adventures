#include "dt.h"
#include<QWidget>
#include "ui_dt.h"
#include"config.h"
#include<QIcon>
#include<QPainter>
#include<QTimer>
#include<QMouseEvent>
#include<ctime>
#include<QPushButton>

DT::DT(QWidget *parent)
    : QMainWindow(parent)
{
    ifrunbutton=1;
    m_ding.state=0;

    //调用初始化场景
        initscene();

    showbutton();
}

DT::~DT()
{

}
void DT::showbutton()
{
   //创建按钮
        QPushButton *but=new QPushButton("start",this);

    //调整位置
    but->move(250,700);

    //按钮上文字大小
    but->setStyleSheet("QPushButton{font:20px;}");

    //按钮尺寸
    but->resize(200,200);

    //建立信息和槽 ，点击释放按钮之后，将该按钮隐藏
    QObject::connect(but,&QPushButton::clicked,[=](){
        but->hide();
        playGame();
    });

}
void DT::initscene()
{
    //固定尺寸
     setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //标题
     setWindowTitle(GAME_TITLE);
     //图标
     setWindowIcon(QIcon(":/im/a.png"));

     //定时器初始化
     m_Timer.setInterval(GAME_RATE);

     //出场间隔初始化
     m_recorder=0;

     //随机数种子
     srand((unsigned int)time(NULL));

}
void DT::playGame()
{

    //启动定时器
    m_Timer.start();
    //槽监视信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        //东西出场
        thingtoscene();
        //更新游戏中元素坐标
        updatePosition();
        //绘制
         m_ding.num-=0.01;
        update();
        //碰撞检测
        detect();
    });

}
void DT::updatePosition()
{

    //更新地图坐标
   // m_map.mapPosition();
    //东西出场
    for(int i=0;i<20;i++)
    {
        if(ts[i].m_free==false)
        {
            //计算坐标
            ts[i].updatePosition();
        }
    }

}
void DT::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.y1,m_map.map1);
    painter.drawPixmap(0,m_map.y2,m_map.map2);

   //绘制丁老头
    painter.drawPixmap(m_ding.m_x,m_ding.m_y,m_ding.d);

    //绘制thing
    for(int i=0;i<20;i++)
    {
        if(ts[i].m_free==false)
        {
           painter.drawPixmap(ts[i].m_x,ts[i].m_y,ts[i].m_thing);
        }
    }

    //显示num
    painter.drawRect(20,20,200,50);//画矩形框框
    QFont font("Courier",30);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.setBrush(Qt::red);
        painter.drawText(20,50,"hair num:");
        painter.drawText(165,50,QString::number((int)m_ding.num));

    //给老头画头发
    if(m_ding.state==1)
    {
         painter.setPen(Qt::black);//设置画笔颜色
         int i=rand()%10;
         int j=rand()%10;
         painter.drawLine(m_ding.m_x-i,m_ding.m_y-j,m_ding.m_x,m_ding.m_y);

    }
    else if(m_ding.state==2)
    {
         painter.setPen(Qt::black);//设置画笔颜色
    }

}
void DT::mouseMoveEvent(QMouseEvent *event)
{
   int x= event->x()-m_ding.m_Rect.width()*0.5;
   int y= event->y()-m_ding.m_Rect.height()*0.5;

   //边界检测
   if(x<=0)x=0;
   if(x>=GAME_WIDTH-m_ding.m_Rect.width())
       x=GAME_WIDTH-m_ding.m_Rect.width();
   if(y<=0)y=0;
   if(y>=GAME_HEIGHT-m_ding.m_Rect.height())
   y=GAME_HEIGHT-m_ding.m_Rect.height();


    m_ding.setPosition(x,y);
}
void DT::thingtoscene()
{

    //出场时先设置type
    for(int i=0;i<20;i++)
        if(ts[i].m_change==1)
        {
            int n=rand()%(4);
            ts[i].settype(n);
            ts[i].m_change=0;//下次更新时不能变
        }

    m_recorder++;
    //未达到出场间隔
    if(m_recorder<50)
        return;
    m_recorder=0;
    for(int i=0;i<20;i++)
    {
        //空闲则出场
        if(ts[i].m_free)
        {
            ts[i].m_free=false;

            //坐标
            ts[i].m_x=rand()%(GAME_WIDTH-ts[i].m_Rect.width());
            ts[i].m_y=-ts[i].m_Rect.height();
            break;//只一个出场
        }
    }
}
void DT::detect()
{
    //遍历所有非空闲thing
    for(int i=0;i<20;i++)
    {
        if(ts[i].m_free)
        {
            continue;
            //空闲则执行下一次循环
            ts[i].m_change=1;
        }

        //相交，thing设置为空闲
        if(ts[i].m_Rect.intersects(m_ding.m_Rect))
        {
            ts[i].m_free=true;
            if(ts[i].type==0||ts[i].type==1)
                m_ding.ding_add();
            else
                 m_ding.ding_minus();

        }
    }

}




