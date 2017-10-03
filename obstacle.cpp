#include "obstacle.h"

Obstacle::Obstacle()
{

}

Obstacle::Obstacle(QRect top, QRect bottom, QPixmap px, int type)
{
    this->type = type;
    this->top = QRectF(top);
    this->bottom = QRectF(bottom);
    this->px = px;
    approved = false;
}

QRectF Obstacle::getTop()
{
    return top;
}

QRectF Obstacle::getBottom()
{
    return bottom;
}

void Obstacle::moveBy(double x, double y)
{
    top.moveTo(top.x()+x,top.y()+y);
    bottom.moveTo(bottom.x()+x,bottom.y()+y);
}