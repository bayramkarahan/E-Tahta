#include "cornergrabberline.h"

CornerGrabberLine::CornerGrabberLine(QGraphicsItem *parent,  int corner) :
    QGraphicsItem(parent),
    mouseDownX(0),
    mouseDownY(0),
    _outterborderColor(Qt::black),
    _outterborderPen(),
    _width(6),
    _height(6),
    _corner(corner),
    _mouseButtonState(kMouseReleased)
{
    setParentItem(parent);

    _outterborderPen.setWidth(2);
    _outterborderPen.setColor(_outterborderColor);

   this->setAcceptHoverEvents(true);
}

void CornerGrabberLine::setMouseState(int s)
{
    _mouseButtonState = s;
}

int CornerGrabberLine::getMouseState()
{
    return _mouseButtonState;
}

int CornerGrabberLine::getCorner()
{
    return _corner;
}


// we have to implement the mouse events to keep the linker happy,
// but just set accepted to false since are not actually handling them

void CornerGrabberLine::mouseMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->setAccepted(false);
}

void CornerGrabberLine::mousePressEvent(QGraphicsSceneDragDropEvent *event)
{
    event->setAccepted(false);
}

void CornerGrabberLine::mouseReleaseEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(true);
}

void CornerGrabberLine::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(false);
}

void CornerGrabberLine::mouseMoveEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(false);
}


// change the color on hover events to indicate to the use the object has
// been captured by the mouse

void CornerGrabberLine::hoverLeaveEvent ( QGraphicsSceneHoverEvent * )
{
    _outterborderColor = Qt::black;
    this->update(0,0,_width,_height);
}

void CornerGrabberLine::hoverEnterEvent ( QGraphicsSceneHoverEvent * )
{
    _outterborderColor = Qt::red;
    this->update(0,0,_width,_height);
}

QRectF CornerGrabberLine::boundingRect() const
{
    return QRectF(0,0,_width,_height);
}

QPointF CornerGrabberLine::getCenterPoint()
{
    return QPointF(pos().x() + _width/2,pos().y() + _height/2);

//    if ( _corner == 0 )
//        return QPointF(pos().x() + _width/2,pos().y() + _height/2);
//    else  if ( _corner == 1 )
//        return QPointF(pos().x() - _width/2,pos().y() + _height/2);
//    else  if ( _corner == 2 )
//        return QPointF(pos().x() - _width/2,pos().y() - _height/2);
//    else  if ( _corner == 3 )
//        return QPointF(pos().x() + _width/2,pos().y() - _height/2);

}

void CornerGrabberLine::paint (QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    // fill the box with solid color, use sharp corners

    _outterborderPen.setCapStyle(Qt::SquareCap);
    _outterborderPen.setStyle(Qt::SolidLine);
    painter->setPen(_outterborderPen);

    QPointF topLeft (0, 0);
    QPointF bottomRight ( _width, _height);

    QRectF rect (topLeft, bottomRight);

    QBrush brush (Qt::SolidPattern);
    brush.setColor (_outterborderColor);
    painter->fillRect(rect,brush);

}
