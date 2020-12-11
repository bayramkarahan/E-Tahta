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
#include "scene.h"
#include <QApplication>
#include <QMessageBox>
#include <QPoint>
#include <QDesktopWidget>
#include <QDebug>
#include<QFileDialog>
#include<QtPrintSupport/qprinter.h>
#include<QtPrintSupport/qprintdialog.h>
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QtMath>
#include<QGraphicsPixmapItem>
#include<gridlines.h>
#include<filecrud.h>
#include <QCursor>
#include <QTransform>
#include<QScreen>
#include<QHoverEvent>
#include<depo.h>

Scene::Scene(QObject* parent): QGraphicsScene(parent)
{
    sceneMode = NoMode;
    sceneModeTrue=NoModeTrue;
    itemToLineDraw = 0;
    itemToRectDraw = 0;
    //sampleLine=0;
    dragMove=false;
    drawing=false;
    myMousePress=true;
    //currentItem=nullptr;
    myPopMenuStatus=false;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    //qDebug()<<"scene press"<<depo::as;
   //int MainWindow::as{15};
   /// qDebug()<<"mousePress myMousePress:"<<myMousePress;

    if(myMousePress){
    switch(sceneMode)
     {
     case DrawRectangle:{
         sceneModeTrue=DrawRectangleTrue;
         origPoint = event->scenePos();
         drawing=true;break;
     }
     case DrawLine:{sceneModeTrue=DrawLineTrue;
         origPoint = event->scenePos();
         drawing=true;
         break;
     }
     case DrawPen:{sceneModeTrue=DrawPenTrue; sceneMoveState=false;
          drawing=true;dragMove=false;
          QGraphicsView::DragMode vMode =QGraphicsView::NoDrag;
          makeItemsControllable(false);
        //  vMode = QGraphicsView::RubberBandDrag;
         QGraphicsView* mView = views().at(0);
          if(mView)
           mView->setDragMode(vMode);
         origPoint = event->scenePos();
         points.clear();
        /*
         QGraphicsLineItem*  itemToPenDraw = new QGraphicsLineItem();
         this->addItem(itemToPenDraw);
         itemToPenDraw->setPen(QPen(myPenColor,myPenSize, myPenStyle, Qt::RoundCap ,Qt::RoundJoin));
         itemToPenDraw->setLine(origPoint.x(),origPoint.y() ,origPoint.x()+1,origPoint.y()+1);
         graphicsList.append(itemToPenDraw);
         graphicsListTemp.append(itemToPenDraw);
         graphicsListpoints.append(itemToPenDraw);
        */
         endPos=event->scenePos();
         points<<origPoint;
         //qDebug()<<"Fare Başlama Pozisyonu: "<<event->scenePos();
         startPos=event->scenePos();
         endPos=startPos;
         sx=startPos.x();
         sy=startPos.y();
         ex=startPos.x();
         ey=startPos.y();
       //  qDebug()<<"scene click";
         break;}
     case DrawPenFosfor:{
         sceneModeTrue=DrawPenFosforTrue; origPoint = event->scenePos();
         drawing=true;
         points.clear();

         points<<origPoint;
         break;
     }
     case CopyMode:{sceneModeTrue=CopyModeTrue;
         // qDebug()<<"crop başladı";
          origPoint = event->scenePos();
           QGraphicsView::DragMode vMode =QGraphicsView::NoDrag;
          vMode = QGraphicsView::RubberBandDrag;


          QGraphicsView* mView = views().at(0);
          if(mView)
           mView->setDragMode(vMode);
          break;}
     case EraseMode:{sceneModeTrue=EraseModeTrue;
         //qDebug()<<"silme tıklandı";
        drawing=true;
        makeItemsControllable(true);
       int boyut;
        boyut=myEraseSize*3;
        QRect rect(QPoint(event->scenePos().toPoint().x()-boyut,event->scenePos().toPoint().y()-boyut),QPoint(event->scenePos().toPoint().x()+boyut,event->scenePos().toPoint().y()+boyut) );
        QPainterPath pp;
        pp.addRect(rect);
        setSelectionArea(pp);
        // clearSelection();
        removeOddItem();
        update();
        break;}
     case SelectObject:{sceneModeTrue=SelectObjectTrue;
         // qDebug() <<"nesleler seçilmeye çalışılıyor";
          QTransform deviceTransform;
          QGraphicsItem *selectItem = itemAt(event->scenePos().x(),event->scenePos().y(), deviceTransform);
                   foreach(QGraphicsItem* item, items()){
                     VERectangle * selection = dynamic_cast<VERectangle *>(item);
                        if(selection!=nullptr&&selectItem==selection){
                            selection->fareState(true);
                           // qDebug() <<"seçme modunda rentangle seçildi";
                        }
                        if(selection!=nullptr&&selectItem!=selection){
                             selection->fareState(false);
                           // qDebug() <<"seçme modunda rentangle seçilmedi";
                        }
                   }
         break;}
     }
    QGraphicsScene::mousePressEvent(event);
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    //qDebug()<<"scene move";
  ///  qDebug()<<"mouseMove myMousePress:"<<myMousePress;
     if(myMousePress){
   switch(sceneModeTrue)
   {
   case DrawRectangleTrue:{
       if(!itemToRectDraw){
           itemToRectDraw = new VERectangle(this);
           itemToRectDraw->sekilTur(_sekil);
           itemToRectDraw->setPen(QPen(mySekilKalemColor, mySekilPenSize, mySekilPenStyle));
           itemToRectDraw->setBrush(mySekilZeminColor);
           itemToRectDraw->setImage(myImage);
           itemToRectDraw->setPos(origPoint);
           this->addItem(itemToRectDraw);
           graphicsList.append(itemToRectDraw);
           graphicsListTemp.append(itemToRectDraw);
   }
   itemToRectDraw->setRect(0,0,event->scenePos().x() - origPoint.x(),event->scenePos().y() - origPoint.y());
   itemToRectDraw->fareState(false);
       break;}
   case DrawLineTrue:{
       int r=mySekilPenSize;
       if(!itemToLineDraw){
           QPen pen(QPen(mySekilKalemColor, mySekilPenSize, mySekilPenStyle, Qt::RoundCap ,Qt::RoundJoin));

         //  qDebug()<<"çiziyorumm";
           itemToLineDraw = new QGraphicsLineItem();
           itemToLineDraw->setPen(pen);
           itemToLineDraw->setPos(origPoint);
           this->addItem(itemToLineDraw);
               }
       endPos=event->scenePos();

       if(origPoint.x()>endPos.x()&&origPoint.y()<endPos.y()){
           qDebug()<<"sol-alt";
           itemToLineDraw->setLine(-r*0.3,r*0.3,
           (event->scenePos().x() - origPoint.x())+r*0.4,
           (event->scenePos().y() - origPoint.y())-r*0.4);
          }
       if(origPoint.x()>endPos.x()&&origPoint.y()>endPos.y()){
           qDebug()<<"sol-ust";
           itemToLineDraw->setLine(-r*0.3,-r*0.3,
           (event->scenePos().x() - origPoint.x())+r*0.4,
           (event->scenePos().y() - origPoint.y())+r*0.4);
        }
       if(origPoint.x()<endPos.x()&&origPoint.y()<endPos.y()){
           qDebug()<<"sag-alt";
           itemToLineDraw->setLine(r*0.3,r*0.3,
           (event->scenePos().x() - origPoint.x())-r*0.4,
           (event->scenePos().y() - origPoint.y())-r*0.4);

       }
       if(origPoint.x()<endPos.x()&&origPoint.y()>endPos.y()){
           qDebug()<<"sag-ust";
           itemToLineDraw->setLine(r*0.3,-r*0.3,
           (event->scenePos().x() - origPoint.x())-r*0.4,
           (event->scenePos().y() - origPoint.y())+r*0.4);

       }


       break;
   }
   case DrawPenTrue:{

        //qDebug()<<"scene move";
       QSize screenSize = qApp->screens()[0]->size();
        int tolerans=screenSize.width()/10;
       //if(qFabs(origPoint.x()-event->scenePos().x())<tolerans&&qFabs(origPoint.y()-event->scenePos().y())<tolerans)
       //{
           sceneMoveState=true;
       QGraphicsLineItem*  itemToPenDraw = new QGraphicsLineItem();
       this->addItem(itemToPenDraw);
       itemToPenDraw->setPen(QPen(myPenColor,myPenSize, myPenStyle, Qt::RoundCap ,Qt::RoundJoin));
       itemToPenDraw->setLine(origPoint.x(),origPoint.y(),event->scenePos().x(),event->scenePos().y() );
       origPoint = event->scenePos();
       //graphicsList.append(itemToPenDraw);
       graphicsListTemp.append(itemToPenDraw);
       endPos=event->scenePos();
       graphicsListpoints.append(itemToPenDraw);
       points<<event->scenePos();
       itemToPenDraw=nullptr;
      // qDebug()<<points.count();
       if(sx>endPos.x()) sx=endPos.x();
       if(sy>endPos.y()) sy=endPos.y();
       if(ex<endPos.x()) ex=endPos.x();
       if(ey<endPos.y()) ey=endPos.y();
      //  }

      // qDebug()<<"nesne sayısı"<<graphicsList.count();
       break;}
   case DrawPenFosforTrue:{
       QGraphicsLineItem*  itemToPenDraw = new QGraphicsLineItem();
       this->addItem(itemToPenDraw);
       itemToPenDraw->setPen(QPen(myPenColor,myPenSize, myPenStyle, Qt::RoundCap ,Qt::RoundJoin));
       itemToPenDraw->setLine(origPoint.x(),origPoint.y(),event->scenePos().x(),event->scenePos().y() );

       graphicsList.append(itemToPenDraw);
       graphicsListTemp.append(itemToPenDraw);
       origPoint = event->scenePos();
       graphicsListpoints.append(itemToPenDraw);
       points<<event->scenePos();
       itemToPenDraw=nullptr;

       break;}
  // case CopyModeTrue:{ break;}
   case EraseModeTrue:{
      // qDebug()<<"move siliniyor";
       int boyut;

              boyut=myEraseSize*3;
              QRect rect(QPoint(event->scenePos().toPoint().x()-boyut,event->scenePos().toPoint().y()-boyut),QPoint(event->scenePos().toPoint().x()+boyut,event->scenePos().toPoint().y()+boyut) );
              QPainterPath pp;
              pp.addRect(rect);
              setSelectionArea(pp);
              removeOddItem();

       break;}
   //case SelectObjectTrue:{ break;}
   }
update();

    QGraphicsScene::mouseMoveEvent(event);
     }

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
  ///  qDebug()<<"mouseRelease myMousePress:"<<myMousePress;
 if(myMousePress){
    switch (sceneModeTrue)
    {
    case DrawRectangleTrue:{
        itemToRectDraw = 0;
        //
         drawing = false;

        if(_sekil==DiagramItem::DiagramType::Resim)
    {
            this->setMode(tempSceneMode, tempSekilType);

          // mwindow->sekilButtonClick();
    }
        else
    {
        //  this->setMode(Scene::Mode::SelectObject, DiagramItem::DiagramType::NoType);

    }
        //this->setMode(Scene::Mode::SelectObject, DiagramItem::DiagramType::NoType);

           dragMove=true;
         //mwindow->sekilButtonClick();
        break;}
    case DrawLineTrue:{
        drawing = false;
        /***************************************/
        int r=mySekilPenSize;
        QPen pen(QPen(mySekilKalemColor, mySekilPenSize, mySekilPenStyle, Qt::RoundCap ,Qt::RoundJoin));
        QPixmap pixmap(qFabs(endPos.x() - origPoint.x()+r+r),qFabs(endPos.y() - origPoint.y())+r+r);
        // QPixmap pixmap(itemToDraw->boundingRect().size().toSize());
        pixmap.fill(QColor(127,127,127,0));
        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.setPen(pen);
        int x=0,y=0;
        float rf1=0,rf2=0;
        if(origPoint.x()>endPos.x()&&origPoint.y()<endPos.y()){
            qDebug()<<"sol-alt";x=endPos.x();y=origPoint.y();
            painter.setWindow(QRect(x+r*0.5,y-r*0.5,qFabs(endPos.x() - origPoint.x()),qFabs(endPos.y() - origPoint.y())));
            painter.drawLine(QPoint(origPoint.x(),origPoint.y()),QPoint(endPos.x()+r,endPos.y()-r));
            rf1=-r*0.3;rf2=r*0.3;
        }
        if(origPoint.x()>endPos.x()&&origPoint.y()>endPos.y()){
            qDebug()<<"sol-ust";x=endPos.x();y=endPos.y();
            painter.setWindow(QRect(x+r*0.5,y+r*0.5,qFabs(endPos.x() - origPoint.x()),qFabs(endPos.y() - origPoint.y())));
            painter.drawLine(QPoint(origPoint.x(),origPoint.y()),QPoint(endPos.x()+r,endPos.y()+r));
            rf1=-r*0.3;rf2=r*0.3;
        }
        if(origPoint.x()<endPos.x()&&origPoint.y()<endPos.y()){
            qDebug()<<"sag-alt";x=origPoint.x();y=origPoint.y();
            painter.setWindow(QRect(x-r*0.5,y-r*0.5,qFabs(endPos.x() - origPoint.x()),qFabs(endPos.y() - origPoint.y())));
            painter.drawLine(QPoint(origPoint.x(),origPoint.y()),QPoint(endPos.x()-r,endPos.y()-r));
            rf1=-r*0.3;rf2=r*0.3;
        }
        if(origPoint.x()<endPos.x()&&origPoint.y()>endPos.y()){
            qDebug()<<"sag-ust";x=origPoint.x();y=endPos.y();
            painter.setWindow(QRect(x-r*0.5,y+r*0.5,qFabs(endPos.x() - origPoint.x()),qFabs(endPos.y() - origPoint.y())));
            painter.drawLine(QPoint(origPoint.x(),origPoint.y()),QPoint(endPos.x()-r,endPos.y()+r));
            rf1=-r*0.3;rf2=r*0.3;
        }

          //addPixmap(pixmap);
        /***********************************************************/

        if(!itemToRectDraw){
            itemToRectDraw = new VERectangle(this);
            itemToRectDraw->sekilTur(DiagramItem::DiagramType::Resim);
            itemToRectDraw->setPen(pen);
            itemToRectDraw->setImage(pixmap);
            itemToRectDraw->setPos(x+rf1,y+rf1);
            //itemToRectDraw->setPos(origPoint);
            /*****************************************************************/
            this->addItem(itemToRectDraw);
        }

        itemToRectDraw->setRect(0,0,qFabs(origPoint.x()-endPos.x())+rf2,qFabs(origPoint.y()-endPos.y())+rf2);
        itemToRectDraw->fareState(false);
        removeItem(itemToLineDraw);
        graphicsList.append(itemToRectDraw);
        graphicsListTemp.append(itemToRectDraw);

        // }
        itemToRectDraw = 0;
        dragMove=true;
        sceneMoveState=false;
        itemToLineDraw = 0;
        dragMove=true;

        break;
    }
    case DrawPenTrue:{
           // qDebug()<<"scene realese"<< sceneMoveState<<points.count();
            drawing = false;
            QPixmap *pixmap4;
        if(mySekilTanimlamaStatus) {sekilTanimlama();
            //removeOddItem();


            break;}
        /******************************************************/


        QPen pen(myPenColor,myPenSize, myPenStyle, Qt::RoundCap ,Qt::RoundJoin);
        QPainterPath path;
        path.moveTo(points.at(0));
//qDebug()<<"tek tıklama "<<points.size();
        if(points.size()<3)
        {
           // qDebug()<<"scene realese----------------------------"<< sceneMoveState<<points.count();

            sx=sx-1;
            sy=sy-1;
            ex=ex+1;
            ey=ey+1;
            QPointF temppoint=points.at(0);
                        points.clear();
            points<<QPointF(temppoint.x()-1,temppoint.y()-1)<<temppoint<<
                    QPointF(temppoint.x()+1,temppoint.y()+1);
            path.lineTo(points.at(0));
            path.lineTo(points.at(1));
            path.lineTo(points.at(2));
            // QPointF(temppoint.x(),temppoint.y())<</qDebug()<<"tek tıklama ";
        }


        if(points.size()>2)
        {

        int i=1;
        int k=3;
      int  kx=qFabs(sx-ex)/points.count();
      int  ky=qFabs(sy-ey)/points.count();
      //  qDebug()<<"path"<<points.count()<<"g:"<<kx<<"y:"<<ky;       // qDebug()<<qFabs(sx-ex);
//qDebug()<<"point sayısı: "<<points.size();
      if(sceneMoveState) //eğer move olayı olmussa
        {

          while (i +3< points.size()) {
              if (kx<1||ky<1)
                  path.lineTo(points.at(i+k));
              else path.cubicTo(points.at(i), points.at(i+1), points.at(i+2));

              //path.cubicTo(points.at(i)+startPos, points.at(i+3)+startPos, points.at(i+6)+startPos);

              /// path.cubicTo(points.at(i), points.at(i+1), points.at(i+2));
           //  qDebug()<<i<<i+1<<i+2;
              i +=k;
          }
       //   if ((points.size()-i)==0){qDebug()<<points.size()<<i<<"0 eksik";path.cubicTo(points.at(i-1), points.at(i), points.at(i+1));}
          if ((points.size()-i)==1){/*qDebug()<<points.size()<<i<<"1 eksik";*/path.cubicTo(points.at(i-1), points.at(i), points.at(i));}
          if ((points.size()-i)==2){/*qDebug()<<points.size()<<i<<"2 eksik";*/path.cubicTo(points.at(i), points.at(i+1), points.at(i+1));}
          if ((points.size()-i)==3){/*qDebug()<<points.size()<<i<<"3 eksik";*/path.cubicTo(points.at(i+1), points.at(i+2), points.at(i+2));}
         // if ((points.size()-i)>3){qDebug()<<points.size()<<i<<"dikkattttttt eksik";}
         // qDebug()<<"path"<<path;
         // qDebug()<<"point"<<points;

            }

          while(!graphicsListpoints.isEmpty())
          {
          removeItem(graphicsListpoints.last());
          delete graphicsListpoints.last();
          graphicsListpoints.removeLast();
 //qDebug()<<"deneme";
          }update();

        }
        else
        {
            graphicsListpoints.clear();
        }
       // addPath(path,pen);
        //path.clear();

/******************************************/
        QPixmap pixmap(qFabs(sx-ex)+myPenSize*2, qFabs(sy-ey)+myPenSize*2);
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.setWindow(QRect(sx-myPenSize, sy-myPenSize,qFabs(sx-ex)+myPenSize*2, qFabs(sy-ey)+myPenSize*2));
        painter.setPen(pen);
        painter.strokePath(path,pen);

        /****************************************************************/
         if(!itemToRectDraw){
             itemToRectDraw = new VERectangle(this);
             itemToRectDraw->sekilTur(DiagramItem::DiagramType::Resim);
             itemToRectDraw->setPen(pen);
             itemToRectDraw->setImage(pixmap);
             itemToRectDraw->setPos(sx-myPenSize,sy-myPenSize);
             this->addItem(itemToRectDraw);
             graphicsList.append(itemToRectDraw);
             graphicsListTemp.append(itemToRectDraw);
             historyBack.append(itemToRectDraw);
             historyBackAction.append("added");

            // addPath(path,pen);
            // addPixmap(pixmap);
     }
         itemToRectDraw->setRect(0,0,qFabs(sx-ex)+2*myPenSize,qFabs(sy-ey)+2*myPenSize);
   //  itemToRectDraw->setRect(0,0,qFabs(startPos.x()),qFabs(event->scenePos().y() - origPoint.y()));
     itemToRectDraw->fareState(false);
       // }
     itemToRectDraw = 0;

        dragMove=true;
     sceneMoveState=false;

     /******************************************************/
        //itemToLineDraw = 0;
       // itemToPenDraw=0;
         //  qDebug()<<"Fare Bitiş Pozisyonu: "<<event->scenePos();
       //    if(mySekilTanimlamaStatus) sekilTanimlama();
        break;
    }
    case DrawPenFosforTrue:{
        drawing = false;
        /******************************************************/
        QPainterPath path;
        path.moveTo(points.at(0));
        int i=1;
          while (i +4 < points.size()) {
              path.cubicTo(points.at(i), points.at(i+2), points.at(i+4));
             // path.cubicTo(points.at(i)+startPos, points.at(i+3)+startPos, points.at(i+6)+startPos);

              i += 4;
          }
         QPen pen(myPenColor,myPenSize, myPenStyle, Qt::RoundCap ,Qt::RoundJoin);
         addPath(path,pen);
         /****************************************************************/

          while(!graphicsListpoints.isEmpty())
          {
          removeItem(graphicsListpoints.last());
          delete graphicsListpoints.last();
          graphicsListpoints.removeLast();

          }update();
        //itemToLineDraw = 0;
        break;}
    case CopyModeTrue:{

        if(!itemToRectDraw){

            QRect selection;
            selection.setRect(origPoint.x(),origPoint.y(),event->scenePos().x()-origPoint.x() , event->scenePos().y()-origPoint.y() );
            itemToRectDraw = new VERectangle(this);
            itemToRectDraw->sekilTur(DiagramItem::DiagramType::Copy);
            itemToRectDraw->setPen(QPen(mySekilKalemColor, mySekilPenSize, mySekilPenStyle));
            itemToRectDraw->setBrush(mySekilZeminColor);
            //painter->drawPixmap(0,0,desk.scaled(rect.width(),rect.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation).copy(selection));
            //itemToRectDraw->setImage()QPixmap::fromImage(imgmm.copy(selection));
            QPixmap temp=myImage.copy(selection);


            itemToRectDraw->setPos(origPoint);
            itemToRectDraw->setImage(temp);

            itemToRectDraw->setRect(0,0,event->scenePos().x() - origPoint.x(),event->scenePos().y() - origPoint.y());
            this->addItem(itemToRectDraw);
             itemToRectDraw->fareState(true);
            graphicsList.append(itemToRectDraw);
            graphicsListTemp.append(itemToRectDraw);
            //myImage;
            itemToRectDraw = 0;
            drawing = false;
            this->setMode(Scene::Mode::SelectObject, DiagramItem::DiagramType::NoType);
            dragMove=true;
            //this->removeItem(text);
            //this->removeItem(text1);
           // makeItemsControllable(false);
            /**********************************/
            FileCrud *fc=new FileCrud();
            fc->dosya="E-Tahta.copy.ini";
            if(fc->fileexists()) fc->fileremove();
            fc->fileWrite("copy=1");

            /********************************/
        }
      //  qDebug()<<"copy bitti";

        break;}
    case EraseModeTrue:{
        //mw->setCursor(Qt::ArrowCursor);
         drawing = false;
         makeItemsControllable(false);

        break;
    }
    //case SelectObjectTrue:{break;}
    }
    depo::historyBackCount=historyBack.count();
    depo::historyNextCount=historyNext.count();
    origPoint = event->scenePos();
    this->update();
    sceneModeTrue=NoModeTrue;
 //_sekil=DiagramItem::DiagramType::NoType;
 QGraphicsScene::mouseReleaseEvent(event);

 }
}

void Scene::sekilTanimlama()
{
     qDebug()<<"deneme";
    bool nsx=false,nex=false;
    bool ds=false,de=false;
int mj=0;
int alan=0;
// qDebug()<<"Alan: "<<sx<<sy<<ex<<ey<<"xu:"<<qFabs(sx-ex)<<"yu:"<<qFabs(sy-ey);
if(qFabs(sx-ex)>qFabs(sy-ey)) mj=qFabs(sx-ex); else mj=qFabs(sy-ey);

for(int i=sy;i<=ey;i+=5)
{
    nsx=false;nex=false;
    ds=false;
    de=false;
    for(int j=sx;j<=ex;j+=5)
    {

      //  QGraphicsItem *item = itemAt(i,j, QTransform);4
        QGraphicsItem *item = itemAt(j,i, QTransform());
        QGraphicsItem *item1 = itemAt(j+5,i, QTransform());


        if((item)&&(nsx==false)&&(nex==false)) {nsx=true;ds=true;}
        if ((item1)&&(nex==false)&&(nsx==true)&&(ds==true)) {nex=true;}

      if((nsx==true)&&(item==0)&&(nex==false))
       {
          alan=alan+25;
           item=0;
 /*QGraphicsLineItem*  itemToPenDraw = new QGraphicsLineItem();
 this->addItem(itemToPenDraw);
 itemToPenDraw->setPen(QPen(QColor(0,0,50,20),myPenSize, myPenStyle, Qt::RoundCap ,Qt::RoundJoin));
 itemToPenDraw->setLine(j,i,j+1,i);
*/
    }
   }
}
alan=alan+qFabs(sy-ey)*5;
/************ALANI SİLME*********************/
 makeItemsControllable(true);//
QRect rect(QPoint(sx-35,sy-35),QPoint(ex+35,ey+35));
QPainterPath pp;
pp.addRect(rect);
setSelectionArea(pp);
//removeOddItem();
//clearSelection();
/**********************************/
//qDebug()<<"mj eksen"<<mj;
//qDebug()<<"alan "<<alan;
float k=(3.1416*mj*mj)/(4*alan);
qDebug()<<"K:"<<k;
_sekil=DiagramItem::DiagramType::NoType;
 if(k>0&&k<1.4) _sekil=DiagramItem::DiagramType::Dortgen;
 else if(k>1.5&&k<2) _sekil=DiagramItem::DiagramType::Cember;
else if(k>2&&k<2.9) _sekil=DiagramItem::DiagramType::Ucgen;
else if(k>2.9&&k<6) _sekil=DiagramItem::DiagramType::Dortgen;
else if(k>6) _sekil=DiagramItem::DiagramType::Cember;

 //origPoint = event->scenePos();
/**********************************************/
 if(_sekil!=DiagramItem::DiagramType::NoType)
 {
     itemToRectDraw = new VERectangle(this);
     itemToRectDraw->sekilTur(_sekil);
     itemToRectDraw->setPen(QPen(QColor(0,0,0,255), 4, Qt::SolidLine));
     itemToRectDraw->setBrush(mySekilZeminColor);
     itemToRectDraw->setPos(sx,sy);

     this->addItem(itemToRectDraw);

     itemToRectDraw->setRect(0,0,qFabs(sx-ex),qFabs(sy-ey));
     itemToRectDraw->fareState(true);
 }
/*************************************************/


}
void Scene::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete)
        foreach(QGraphicsItem* item, selectedItems()){
            removeItem(item);
            delete item;
        }
    else
        QGraphicsScene::keyPressEvent(event);
}

void Scene::removeOddItem(){
        /* foreach(QGraphicsItem* item, selectedItems()){
            removeItem(item);
            delete item;
        }*/
    foreach(QGraphicsItem* item, selectedItems()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(selection)
        {

            //*************************************/
           /* if(!graphicsListHistoryBack.isEmpty())
            {
           graphicsListHistoryBack.removeAll(selection);

            }
            graphicsListHistoryNext.append(selection);
*/
            historyBack.append(selection);
            historyBackAction.append("deleted");
            removeItem(selection);
           // delete selection;
            update();
            //  qDebug()<<"Renctange  Modify Silindi.";
            /*****************************************/
        }


    }
    /***************************************************************/
    foreach(QGraphicsItem* item, selectedItems()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(!selection)
        {

            //*************************************/
            if(!graphicsList.isEmpty())
            {
           graphicsList.removeAll(item);

            }
        //    qDebug()<<item<<"Line Silindi.";
            removeItem(item);
            delete item;
            update();

            /*****************************************/
        }


    }

}

void Scene::slotMove(QGraphicsItem *signalOwner, qreal dx, qreal dy)
{
    /*foreach (QGraphicsItem *item, selectedItems()) {
        if(item != signalOwner) item->moveBy(dx,dy);
    }*/
}

void Scene::removeAllItem(){
    //clear();
    QList<QGraphicsItem*> list=items();
   // list.rbegin();
    std::reverse(std::begin(list),std::end(list));
    foreach(QGraphicsItem* item, list){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(selection)
        {
           // qDebug()<<"benim nesne";
            //*************************************/
            if(!graphicsList.isEmpty())
            {
           graphicsList.removeAll(selection);

            }
         //   graphicsListNext.insert(0,selection);
            //historyBack.insert(0,selection);
           // historyBackAction.insert(0,"deleted");
            historyBack.append(selection);
            historyBackAction.append("deleted");
            //qDebug()<<" nesne silindi";
            removeItem(selection);
           // delete selection;
            update();
            /*****************************************/
        }
    }
    foreach(QGraphicsItem* item, items()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(!selection)
        {
            removeItem(item);
            delete item;
            update();
          //  qDebug()<<"diger nesne";

        }
    }




}

void Scene::setParent(QMainWindow* _mwindow)
{
    mw=_mwindow;
}

void Scene::setMode(Mode mode,DiagramItem::DiagramType sekil){

    tempSekilType=_sekil;
    _sekil=sekil;
    tempSceneMode=sceneMode;
    sceneMode = mode;
     QGraphicsView::DragMode vMode =QGraphicsView::NoDrag;
    if(mode == DrawLine){
        makeItemsControllable(false);
        vMode = QGraphicsView::NoDrag;
    }
    if(mode == DrawRectangle){
        makeItemsControllable(false);
        vMode = QGraphicsView::NoDrag;
    }
    if(mode == DrawEllipse){
        makeItemsControllable(false);
        vMode = QGraphicsView::NoDrag;
     }
    else if(mode == DrawPen){
         makeItemsControllable(false);
        vMode = QGraphicsView::NoDrag;
    }

   else if(mode == GeriAlMode){
    //qDebug()<<"Geri Al";
      //  qDebug()<<"Geri Al"<<"historycount"<<Scene::graphicsListHistoryBack.count();

        if(!historyBack.isEmpty())
        {
            // qDebug()<<graphicsList.last();
            if(historyBackAction.last()=="added"&&!historyBack.isEmpty())
            {
                historyNext.append(historyBack.last());
                historyNextAction.append(historyBackAction.last());

                removeItem(historyBack.last());

                historyBack.removeLast();
                historyBackAction.removeLast();
               // qDebug()<<"added calıştı";
            }
        }
        if(!historyBack.isEmpty())
        {
            if (historyBackAction.last()=="deleted")
            {
              //  historyNext.append(historyBack.last());
              //  historyNextAction.append(historyBackAction.last());

                addItem(historyBack.last());
                historyBack.removeLast();
                historyBackAction.removeLast();
                //qDebug()<<"deleted calıştı";

            }

            //graphicsListNext.append(graphicsList.last());
            //  delete graphicsList.last();

            update();
        }
        depo::historyBackCount=historyBack.count();
        depo::historyNextCount=historyNext.count();

    }
    else if(mode == IleriAlMode){
        //qDebug()<<"ileri Al";
        if(!historyNext.isEmpty())
        {
            VERectangle * selection = dynamic_cast<VERectangle *>(historyNext.last());
            this->addItem(selection);
            historyBack.append(selection);
            historyBackAction.append(historyNextAction.last());
           //graphicsListTemp.append(graphicsListNext.last());
            historyNext.removeLast();
            historyNextAction.removeLast();
            update();
        }
        depo::historyBackCount=historyBack.count();
        depo::historyNextCount=historyNext.count();

        }
    else if(mode == ScreenMode){

    }
    else if(mode == TransparanMode){
         }
    else if(mode == BlackBoardMode){

    }
    else if(mode == EraseMode){

        drawing=false;
        dragMove=true;
        makeItemsControllable(false);
       /* vMode = QGraphicsView::RubberBandDrag;
        */
    }
    else if(mode == ClearMode){

        removeAllItem();
    }
    else if(mode == SelectObject){
        drawing=false;
        dragMove=true;
        makeItemsControllable(true);
        vMode = QGraphicsView::RubberBandDrag;

}
           QGraphicsView* mView = views().at(0);
           if(mView)
            mView->setDragMode(vMode);
}

void Scene::setImage(QPixmap _myImage){
    myImage=_myImage;
}

void Scene::setSekilTanimlamaStatus(bool _mySekilTanimlamaStatus)
{
    mySekilTanimlamaStatus=_mySekilTanimlamaStatus;
}

void Scene::setPopMenuStatus(bool _myPopMenuStatus)
{
myPopMenuStatus=_myPopMenuStatus;//qDebug()<<"sPopMenuStatus: "<<myPopMenuStatus;
}
void Scene::setMousePressStatus(bool _myMousePress)
{
    myMousePress=_myMousePress;
}

void Scene::setPenSize(int _myPenSize){
    myPenSize=_myPenSize;//qDebug()<<"sKalem Size: "<<myPenSize;
}
void Scene::setEraseSize(int _myEraseSize){
    myEraseSize=_myEraseSize;//qDebug()<<"sSilgi Size: "<<myEraseSize;
}
void Scene::setPenColor(QColor _myPenColor){
    myPenColor=_myPenColor;//qDebug()<<"sKalem Color: "<<myPenColor;
}
void Scene::setPenAlpha(int _myPenAlpha){
    myPenAlpha=_myPenAlpha;//qDebug()<<"sKalem Alpha: "<<myPenAlpha;
}
void Scene::setPenStyle(Qt::PenStyle _myPenStyle){
    myPenStyle=_myPenStyle;//qDebug()<<"sKalem Style: "<<myPenStyle;
}
void Scene::setSekilPenStyle(Qt::PenStyle _mySekilPenStyle)
{
     mySekilPenStyle=_mySekilPenStyle;//qDebug()<<"sSekilKalem Style: "<<mySekilPenStyle;
}
void Scene::setSekilPenSize(int _mySekilPenSize){
    mySekilPenSize=_mySekilPenSize;//qDebug()<<"sSekilKalem Size: "<<mySekilPenSize;
}
void Scene::setSekilKalemColor(QColor _mySekilKalemColor){
    mySekilKalemColor=_mySekilKalemColor;//qDebug()<<"sŞekil Kalem Color: "<<mySekilKalemColor;
}
void Scene::setSekilZeminColor(QColor _mySekilZeminColor){
    mySekilZeminColor=_mySekilZeminColor;//qDebug()<<"sŞekil Kalem Color: "<<mySekilZeminColor;
}
void Scene::makeItemsControllable(bool areControllable){
    foreach(QGraphicsItem* item, items()){
        VERectangle * selection = dynamic_cast<VERectangle *>(item);

        if(selection)
        {
            item->setFlag(QGraphicsItem::ItemIsSelectable,areControllable);
            item->setFlag(QGraphicsItem::ItemIsMovable,areControllable);
            if(!areControllable)selection->fareState(areControllable);
        }
        else
        {
            item->setFlag(QGraphicsItem::ItemIsSelectable,areControllable);
            item->setFlag(QGraphicsItem::ItemIsMovable,areControllable);
        }

    }
}
