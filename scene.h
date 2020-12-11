/*****************************************************************************
 *   Copyright (C) 2020 by Bayram KARAHAN                                    *
 *   <bayramk@gmail.com>                                                     *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 3 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          *
 *****************************************************************************/
#ifndef SCENE_H
#define SCENE_H
#include <QMainWindow>
#include <QGraphicsScene>

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QAction>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include<diagramitem.h>
#include<verectangle.h>

#include<QVector>
#include<QHoverEvent>
#include <QGraphicsSceneEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
class QPalette;
class QPoint;
class QMouseEvent;
class QGraphicsSceneHoverEventPrivate;


class Scene : public QGraphicsScene
{

public:
    enum Mode {NoMode, SelectObject, DrawLine,DrawPen,DrawPenFosfor,DrawRectangle,DrawEllipse,
               ScreenMode,TransparanMode,WhiteBoardMode,BlackBoardMode,MoveMode,
              CloseBoardMode,EraseMode,ClearMode,SaveBoardMode,OpenBoardMode,
              IleriAlMode,GeriAlMode,CopyMode};
    enum ModeTrue {DrawPenTrue,DrawPenFosforTrue,DrawLineTrue,CopyModeTrue,DrawRectangleTrue,EraseModeTrue,SelectObjectTrue,NoModeTrue};
    Scene(QObject* parent = 0);
     QList<QGraphicsItem*> historyBack;
     QStringList historyBackAction;
     QList<QGraphicsItem*> historyNext;
     QStringList historyNextAction;

    void setMode(Mode mode, DiagramItem::DiagramType sekil);
    //void setPen(QColor _myPencolor, int _alpha, int _myPenSize);
    void setPenSize(int _myPenSize);
    void setSekilPenSize(int _mySekilPenSize);
    void setSekilPenColor(QColor _mySekilPenColor);
    void setSekilPenStyle(Qt::PenStyle _mySekilPenStyle);
    void setPenColor(QColor _myPenColor);
    void setPenAlpha(int _myPenAlpha);
    void setPenStyle(Qt::PenStyle _myPenStyle);
    void setEraseSize(int _myEraseSize);
    void setPopMenuStatus(bool _myPopMenuStatus);
    void setMousePressStatus(bool _myMousePress);

    void setSekilTanimlamaStatus(bool _mySekilTanimlamaStatus);

    void setSekilZeminColor(QColor _mySekilZeminColor);
    void setSekilKalemColor(QColor _mySekilKalemColor);

    void setParent(QMainWindow* _mwindow);
    void sekilTanimlama();
    void setImage(QPixmap _myImage);
   // QMainWindow* mwindow;
    // QColor myBrushColor;
    QPixmap myImage;
    QVector<QPointF> points;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event);
    void removeAllItem();
    void removeOddItem();

signals:
   // void previousPositionChanged();
   // void currentActionChanged(int);
    void signalSelectItem(QGraphicsItem *item);
    void signalNewSelectItem(QGraphicsItem *item);

public slots:
    void slotMove(QGraphicsItem *signalOwner, qreal dx, qreal dy);

private:
    QColor myPenColor;
    int myPenAlpha;
    int myPenSize;
    int mySekilPenSize;
    QColor mySekilZeminColor;
    QColor mySekilKalemColor;
    bool myPopMenuStatus;
    bool mySekilTanimlamaStatus;
    Qt::PenStyle myPenStyle;
    Qt::PenStyle mySekilPenStyle;
    int myEraseSize;
        Mode sceneMode;
        ModeTrue sceneModeTrue;
    Scene::Mode tempSceneMode;

    bool dragMove;
    bool myMousePress;

    DiagramItem::DiagramType _sekil;
    DiagramItem::DiagramType tempSekilType;
    QPointF origPoint;
    QPointF nokta;
    QPointF startPos;
    QPointF endPos;
    int sx,sy,ex,ey;
   // SelectableLine * sampleLine;
    //QGraphicsLineItem* itemToLineDraw;
    VERectangle* itemToRectDraw;
   // QGraphicsItem *currentItem;
    bool drawing;
    bool sceneMoveState;
    void makeItemsControllable(bool areControllable);
    QRect mainScreenSize;
    QRect currentGeometry;
    QList<QGraphicsItem*> graphicsListNext;
    QList<QGraphicsItem*> graphicsListTempNext;

    QList<QGraphicsItem*> graphicsList;
    QList<QGraphicsItem*> graphicsListTemp;
    QList<QGraphicsItem*> graphicsListpoints;

QGraphicsLineItem* itemToLineDraw;
QMainWindow* mw;
};

#endif // SCENE_H
