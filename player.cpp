#include "player.h"

Player::Player(QRectF rect)
{
    this->rect = rect;
    velD = 0;
    benis = 10000;
    coins = 0;
    reload(1);
    an = 0;
    dir = 0; //unten
    tilt = 45;
    tdir = 0;
    tstep = 1;
    circle = false;
    an=true;
    fin=false;
}

QPixmap Player::getPx()
{
    QPixmap ret;
    switch(an) {
        case 0:
            ret = g0;
        break;
        case 1:
            ret = g1;
        break;
        case 2:
            ret = g2;
        break;
    }
    return ret;
}

void Player::setPos(double x, double y)
{
    double diffX = collRect.x()-rect.x();
    double diffY = collRect.y()-rect.y();
    rect.moveTo(x,y);
    collRect.moveTo(x+diffX,y+diffY);
}

void Player::setVelD(double velD)
{
    this->velD = velD;
}

void Player::setBenis(unsigned long long benis)
{
    this->benis = benis;
}

void Player::setCollRect(int offX, int offY, int offW, int offH)
{
    collRect = QRect(rect.x()+offX,rect.y()+offY,rect.width()+offW,rect.height()+offH);
}

void Player::reload(int id)
{
    g0 = QPixmap(":/images/player/an"+QString::number(id)+"_1.png");
    g1 = QPixmap(":/images/player/an"+QString::number(id)+"_2.png");
    g2 = QPixmap(":/images/player/an"+QString::number(id)+"_3.png");
}

unsigned long long Player::getBenis()
{
    return benis;
}

double Player::getVelD()
{
    return velD;
}

QRectF Player::getRect()
{
    return rect;
}

QRectF Player::getCollRect()
{
    return collRect;
}

QPolygonF Player::getPoly()
{
    QPolygonF poly(rect);
    return poly;
}
