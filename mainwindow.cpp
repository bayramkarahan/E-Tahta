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
//#include "mainwindow.h"
#include <QPalette>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include <QtWidgets>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QGraphicsPolygonItem>
#include<QMessageBox>
#include<QFile>
#include<function.h>
#include<buttonclick.h>
#include<popmenu.h>
#include<kalemlayout.h>
//#include<popler-qt5-.h>

class QWidget;
class QPixmap;

MainWindow::MainWindow()
{
    screenClickDrm=false;
    initPen();
    createButton();
    //this->setMinimumSize(0,0);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::X11BypassWindowManagerHint);

    setAttribute(Qt::WA_StaticContents);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowIcon(QIcon(":icons/screenpen.png"));
      /*****************************************/

    saat = new QTimer(this);
    connect(saat, SIGNAL(timeout()), this, SLOT(saatslot()));

    timerCopy = new QTimer(this);
    connect(timerCopy, SIGNAL(timeout()), this, SLOT(timerCopySlot()));


    timerGizle = new QTimer(this);
    connect(timerGizle, SIGNAL(timeout()), this, SLOT(timerGizleSlot()));
           // timerGizle->start(5000);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(zamanlama()));
    timer->start(1000);




    /*****************Scene******************************/
    scene = new Scene();
    _scene=scene;
    scene->setParent(this);
    scene->setSekilZeminColor(QColor(0,0,0,0));
    //sceneSayfa.append(scene);
    sceneSayfaNumber=0;
    sceneSayfaActiveNumber=0;
    sceneSayfa.append(_scene);

    /***********************************************/
    view = new QGraphicsView(scene);
   // view->setRenderHints(QPainter::Antialiasing);
    //QGraphicsView view(&scene);
     view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    view->setAttribute(Qt::WA_TranslucentBackground);
    view->viewport()->setAutoFillBackground(false);
    QSize screenSize = qApp->screens()[0]->size();

    view->setSceneRect(0,0,screenSize.width(),screenSize.height());
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);






//qDebug() <<"zamanlama";
    setUnifiedTitleAndToolBarOnMac(true);
/*********************************/
    buyukKutu = new QWidget(this);
    buyukKutu->setObjectName("buyukKutu");
    buyukKutu->setStyleSheet("QWidget#buyukKutu{"
                          "border: 1px solid rgb(62, 140, 183);"
                          "border-radius: 5px;"
                          "background-color:rgb(240,240,240,250);"
                          "}");

//setStyleSheet("QLabel{color: rgb(62, 140, 183);}");

    palette = new QPalette();
    palette->setColor(QPalette::Background, QColor(240,240,240,250));
    buyukKutu->setPalette(*palette);
    buyukKutu->setAutoFillBackground(true);
    setWindowTitle("E-Tahta 5.0");
/***********************************/
    kokLayot=new QVBoxLayout();
    kokLayot->setContentsMargins(0,0,0,0);
    buyukKutu->setLayout(kokLayot);
    kalemLayout();


    buyukKutu->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight));
   //   kalemButtonClick();
    scene->setMode(Scene::Mode::NoMode, DiagramItem::DiagramType::NoType);
    currentScreenMode=Scene::Mode::NoMode;
    iconButton();
    buttonColorClear();
    timerGizleSlot();
    ekranButtonClick();
    //scene->setSekilZeminColor(mySekilZeminColor);
   /* QGraphicsTextItem *text = new QGraphicsTextItem("E-Tahta");
    scene->addItem(text);
    text->setPos(0, 0);
    QGraphicsTextItem *text1 = new QGraphicsTextItem("E-Tahta");
    scene->addItem(text1);
   text1->setPos(this->width()-150, this->height()-40);
*/
  /*  sayac=new QLabel(this);
   // kalemKalinlik();
    sayac->hide();
    sure=new QSpinBox(this);

    sure->hide();
    bar=new QProgressBar(this);
    bar->hide();
    */
   // zeminSeffafButtonClick();
    /*if(myZeminType==0)//zeminSeffafButtonClick();
       if(myZeminType==1) zeminSiyahButtonClick();
       if(myZeminType==2) zeminBeyazButtonClick();
       if(myZeminType==3) zeminBeyazButtonClick();*/

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if(screenDesktop)
    {

        QSize screenSize = qApp->screens()[0]->size();

        setGeometry(0,
                    0,
                    screenSize.width(),
                    screenSize.height());
  //  qDebug()<<"degişti";
       update();
    }
}

void MainWindow::moveEvent(QMoveEvent *event)
{
    if(screenDesktop)
    {
        QSize screenSize = qApp->screens()[0]->size();


        setGeometry(0,
                    0,
                    screenSize.width(),
                    screenSize.height());
        update();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
 //   qDebug()<<"main move";



}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   // qDebug()<<"main press";
    if ((event->buttons() & Qt::LeftButton)&& tasi==true) {
        //qDebug()<<"move main press";
        buyukKutu->setGeometry(QRect(event->pos().x(),kutuTop,kutuWidth,kutuHeight));
        kutuLeft=event->pos().x();
       /// kutuTop=50;
        tasi=false;
        kalemButtonClick();
    }
    if(screenClickDrm)
    {
      ///  qDebug()<<"main press sunu";
        ekranButtonClick();
        system("sleep 0.2&&xdotool click 1");

        ekranButtonClick();
       /// screenClickButtonClick();


}
}


