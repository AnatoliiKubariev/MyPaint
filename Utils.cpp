#include "Utils.h"

QRectF CalculateRectangle(const QPoint& point1, const QPoint& point2)
{
    QPointF top_left;
    QPointF bottom_right;

    if(point1.x() < point2.x() && point1.y() < point2.y())
    {
        top_left = point1;
        bottom_right = point2;
    }
    else if(point1.x() > point2.x() && point1.y() > point2.y())
    {
        top_left = point2;
        bottom_right = point1;
    }
    else if(point1.x() > point2.x() && point1.y() < point2.y())
    {
        top_left = QPointF(point2.x(), point1.y());
        bottom_right = QPointF(point1.x(), point2.y());
    }
    else if(point1.x() < point2.x() && point1.y() > point2.y())
    {
        top_left = QPointF(point1.x(), point2.y());
        bottom_right = QPointF(point2.x(), point1.y());
    }

    return QRectF(top_left, bottom_right);
}