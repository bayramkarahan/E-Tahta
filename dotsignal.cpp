#include "dotsignal.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
DotSignal::DotSignal(QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::black));
   setRect(-4,-4,4,4);
    // setRect(0,0,20,20);
    setDotFlags(0);
}

DotSignal::DotSignal(QPointF pos, QGraphicsItem *parentItem, QObject *parent) :
    QObject(parent)
{
    setParentItem(parentItem);
    setAcceptHoverEvents(true);
    setBrush(QBrush(Qt::black));
    //setRect(0,0,20,20);
    setRect(-4,-4,4,4);
    setPos(pos);
    setPreviousPosition(pos);
    setDotFlags(0);
}

DotSignal::~DotSignal()
{

}

QPointF DotSignal::previousPosition() const
{
    return m_previousPosition;
}

void DotSignal::setPreviousPosition(const QPointF previousPosition)
{
    if (m_previousPosition == previousPosition)
        return;

    m_previousPosition = previousPosition;
    emit previousPositionChanged();
}

void DotSignal::setDotFlags(unsigned int flags)
{
    m_flags = flags;
}

void DotSignal::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        auto dx = event->scenePos().x() - m_previousPosition.x();
        auto dy = event->scenePos().y() - m_previousPosition.y();
        moveBy(dx,dy);
        setPreviousPosition(event->scenePos());
        emit signalMove(this, dx, dy);
    } else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void DotSignal::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_flags & Movable){
        setPreviousPosition(event->scenePos());
    } else {
        QGraphicsItem::mousePressEvent(event);
       //  qDebug() <<"köşeye tıklandı ";
    }
}

void DotSignal::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalMouseRelease();
    QGraphicsItem::mouseReleaseEvent(event);
}

void DotSignal::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    setBrush(QBrush(Qt::red));

}

void DotSignal::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    qDebug() <<"köşe "<<m_flags;
     setBrush(QBrush(Qt::black));

   // QGraphicsItem::hoverEnterEvent(event);

}

void DotSignal::paint (QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    // fill the box with solid color, use sharp corners

    _outterborderPen.setCapStyle(Qt::SquareCap);
    _outterborderPen.setStyle(Qt::SolidLine);
    painter->setPen(_outterborderPen);

    QPointF topLeft (0, 0);
    QPointF bottomRight ( 10, 10);//dikkat bura ayarlanacak

    QRectF rect (topLeft, bottomRight);
   // QPixmap p1(":/icons/erase.png");
    //QPixmap p2(":/icons/arrow-up-down.png");
    //QPixmap p3(":/icons/rotate-right.png");

if(_outterborderColor!=Qt::red&&m_flags==5) {
    _outterborderColor=QColor(0,255,0);
 //   painter->drawPixmap(-5,-5,p3.scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

if(_outterborderColor!=Qt::red&&m_flags==2)
{
   // _outterborderColor=QColor(255,255,0);
   // painter->drawPixmap(-5,-5,ptt.scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

if(_outterborderColor!=Qt::red&&m_flags==6)
{
    _outterborderColor=QColor(0,0,255);
  //  painter->drawPixmap(-5,-5,p1.scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
if(_outterborderColor!=Qt::red&&m_flags==4)
{
    _outterborderColor=QColor(0,0,0);
   // painter->drawPixmap(-5,-5,p2.scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
if(_outterborderColor!=Qt::red&&m_flags==7) {
    _outterborderColor=QColor(0,0,0);
   // painter->drawPixmap(-5,-5,p2.scaled(20,20,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

    QBrush brush (Qt::SolidPattern);
    brush.setColor (_outterborderColor);
    painter->fillRect(rect,brush);


}

