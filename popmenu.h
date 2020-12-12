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

#ifndef POPMENU_H
#define POPMENU_H
#include <QPdfWriter>
#include <QPainter>
#include<poppler/qt5/poppler-qt5.h>
#include <QThread>
#include<QWidget>

QMenu *MainWindow::ayarMenu()
{   QMenu *menu = new QMenu(this);
    int e=(en*0.8)/4*9;
      int b=(boy*0.6)/4*5;

   infoButton->setFixedSize(e,b);
   infoButton->setIconSize(QSize(e,b));
   tasiButton->setFixedSize(e, b);
   tasiButton->setIconSize(QSize(e,b));
   klavyeButton->setFixedSize(e, b);
   klavyeButton->setIconSize(QSize(e,b));
   kalemKapatButton->setFixedSize(e, b);
   kalemKapatButton->setIconSize(QSize(e,b));
   connect(tasiButton, &QPushButton::clicked, [=]() {     menu->close();   });
   connect(klavyeButton, &QPushButton::clicked, [=]() {     menu->close();   });

   QPushButton *saveProfileButton= new QPushButton;
   saveProfileButton->setFixedSize(e, b);
   saveProfileButton->setIconSize(QSize(e,b));
   saveProfileButton->setFlat(true);
   saveProfileButton->setIcon(QIcon(":icons/saveprofile.png"));

   connect(saveProfileButton, &QPushButton::clicked, [=]() {
       FileCrud *fc=new FileCrud();
       fc->dosya="E-Tahta.config.ini";

       if(fc->fileexists()) fc->fileremove();
       fc->fileWrite("myPenAlpha="+QString::number(myPenAlpha));
       fc->fileWrite("myPenColor="+myPenColor.name());
       fc->fileWrite("myPenSize="+QString::number(myPenSize));
       fc->fileWrite("myGridSize="+QString::number(myGridSize));
       fc->fileWrite("myEraseSize="+QString::number(myEraseSize));
       fc->fileWrite("myPenStyle="+QString::number(myPenStyle));
       fc->fileWrite("mySekilPenStyle="+QString::number(mySekilPenStyle));
       fc->fileWrite("mySekilZeminColor="+mySekilZeminColor.name());
       fc->fileWrite("mySekilKalemColor="+mySekilKalemColor.name());
       fc->fileWrite("myGridColor="+myGridColor.name());
       fc->fileWrite("myZeminColor="+myZeminColor.name());
       fc->fileWrite("mySekilPenSize="+QString::number(mySekilPenSize));
       fc->fileWrite("myZeminType="+QString::number(myZeminType));
       fc->fileWrite("gridYatay="+QString::number(scene->sceneGridYatay));
       fc->fileWrite("gridDikey="+QString::number(scene->sceneGridDikey));
       fc->fileWrite("clock="+QString::number(clock));
       fc->fileWrite("kutuLeft="+QString::number(kutuLeft));
       fc->fileWrite("kutuTop="+QString::number(kutuTop));
       fc->fileWrite("copyState="+QString::number(copyState));

});
   QPushButton *loadDefaultProfileButton= new QPushButton;
   loadDefaultProfileButton->setFixedSize(e, b);
   loadDefaultProfileButton->setIconSize(QSize(e,b));
   loadDefaultProfileButton->setFlat(true);
   loadDefaultProfileButton->setIcon(QIcon(":icons/loadprofile.png"));

   connect(loadDefaultProfileButton, &QPushButton::clicked, [=]() {

       myPenAlpha=255;
       myPenColor=QColor(0,0,0,255);
       myPenSize=4;
       myGridSize=4;
       myEraseSize=4;
       myPenStyle=Qt::SolidLine;
       mySekilPenStyle=Qt::SolidLine;
       mySekilZeminColor=QColor(0,0,0,0);
       mySekilKalemColor=QColor(0,0,0,255);
       myGridColor=QColor(128,128,128,128);
       mySekilPenSize=4;
       myZeminColor=QColor(0,0,0,0);
       scene->sceneGridYatay=false;
       scene->sceneGridDikey=false;
       gizleGoster=true;
       screenDesktop=true;
       myZeminType=0;
       clock=true;
       kutuLeft=this->width()-kutuWidth-this->width()/100;
       kutuTop=(this->height() /2-kutuHeight/2);
       copyState=false;

});
   QPushButton *saatButton= new QPushButton;
   saatButton->setFixedSize(e, b);
   saatButton->setIconSize(QSize(e,b));
   saatButton->setFlat(true);
   saatButton->setIcon(QIcon(":icons/sayac.png"));

   connect(saatButton, &QPushButton::clicked, [=]() {

     // delete sayac;
      // sayac=new QLCDNumber(this);
      //  sayac->setFrameShape(QFrame::NoFrame);
       //sayac->setSegmentStyle(QLCDNumber::Filled);
      /* Qt::WindowFlags flags = 0;
       flags |= Qt::Window;
       flags |= Qt::X11BypassWindowManagerHint;
       flags |= Qt::CustomizeWindowHint;
       this->setWindowFlags(flags);


       flags |= Qt::SplashScreen;
       flags |= Qt::X11BypassWindowManagerHint;
       flags |= Qt::WindowStaysOnTopHint;

      QWidget *sayacWg=new QWidget();
       sayacWg->resize(200,300);


       sayacWg->setWindowFlags(flags);
sayacWg->show();
*/

sayacStartButton= new QPushButton(this);
sayacStartButton->hide();
sayacCloseButton= new QPushButton(this);
sayacCloseButton->hide();

       sayac=new QLabel(this);
          // kalemKalinlik();
           sayac->hide();
           sure=new QSpinBox(this);
           sure->setStyleSheet(
                       "QSpinBox { border: 3px solid gray; border-radius: 5px; min-height: 150px; min-width: 150px; }"
                       "QSpinBox::up-arrow { border-left: 17px solid none;"
                       "border-right: 17px solid none; border-bottom: 17px solid black; width: 0px; height: 0px; }"
                       "QSpinBox::up-arrow:hover { border-left: 17px solid none; "
                       "border-right: 17px solid none; border-bottom: 17px solid black; width: 0px; height: 0px; }"
                       "QSpinBox::up-button { min-width: 80px; min-height: 77px; background-color: gray; }"
                       "QSpinBox::up-button:hover { min-width: 80px; min-height: 77px; background-color: gray; }"
                       "QSpinBox::down-arrow { border-left: 17px solid none;"
                       "border-right: 17px solid none; border-top: 17px solid black; width: 0px; height: 0px; }"


                       "QSpinBox::down-arrow:hover { border-left: 17px solid none;"
                       "border-right: 17px solid none; border-top: 17px solid black; width: 0px; height: 0px; }"
                       "QSpinBox::down-button { min-width: 80px; min-height: 77px; background-color: gray; }"
                       "QSpinBox::down-button:hover { min-width: 80px; min-height: 77px; background-color: gray; }"

                       );
           sure->hide();
           bar=new QProgressBar(this);
           bar->hide();


       sayac->move(this->width()/2-250,this->height()/2-250);
       sayac->resize(500, 500);
       sayac->show();
       bar->show();
       //sure->hide();

       sure->move(this->width()/2-250,this->height()/2+170);
       sure->resize(200, 50);
       sure->setValue(30);
       sure->show();
        sayacStartButton->setFixedSize(e*2, b*3);
       sayacStartButton->setIconSize(QSize(e*2,b*3));
       sayacStartButton->setFlat(true);
       sayacStartButton->setIcon(QIcon(":icons/sayacplay.png"));
       sayacStartButton->move(this->width()/2-50,this->height()/2+200);
       sayacStartButton->show();
       bar->move(this->width()/2-250,this->height()/2-250);
       bar->resize(500, 50);
       connect(sayacStartButton, &QPushButton::clicked, [=]() {

           saniye=0;
           saat->start(1000);
           //delete sure;
           sure->hide();
           sayacStartButton->hide();
          // bar->hide();
          // sayacCloseButton->hide();
           bar->setMaximum(sure->value()*60);




});
          sayacCloseButton->setFixedSize(e*2, b*3);
       sayacCloseButton->setIconSize(QSize(e*2,b*3));
       sayacCloseButton->setFlat(true);
       sayacCloseButton->setIcon(QIcon(":icons/sayacstop.png"));
       sayacCloseButton->move(this->width()/2+100,this->height()/2+200);
       sayacCloseButton->show();
       connect(sayacCloseButton, &QPushButton::clicked, [=]() {
          saat->stop();
                 sayac->hide();
           sure->hide();
             bar->hide();
           sayacStartButton->hide();
           sayacCloseButton->hide();
});

});

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
  //  layout->setContentsMargins(20, 20, 20,20);
   // layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(klavyeButton, 2,1,1,1,Qt::AlignHCenter);
    layout->addWidget(tasiButton, 2, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(infoButton, 2, 3,1,1,Qt::AlignHCenter);

    layout->addWidget(saveProfileButton,5,1 ,1,1,Qt::AlignHCenter);
    layout->addWidget(loadDefaultProfileButton, 5,2 ,1,1,Qt::AlignHCenter);
    layout->addWidget(saatButton, 5, 3,1,1,Qt::AlignHCenter);
  //  layout->addWidget(kalemKapatButton, 7,1,1,1);
    layout->addWidget(new QLabel("<font size=1>Klavye</font>"),3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Taşı</font>"),3,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Bilgi</font>"),3,3,1,1,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),6,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Öntanımlı Ayarlar</font>"),6,2,1,1,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>Sayaç</font>"),6,3,1,1,Qt::AlignHCenter);
    QCheckBox *checkbox = new QCheckBox("Kopyalama Yeni Sayfada Açılsın", menu);
    QFont ff( "Arial", 8, QFont::Normal);
    checkbox->setFont(ff);
    checkbox->setChecked(copyState);
    //qDebug()<<copyState;
    connect(checkbox, &QCheckBox::clicked, [=]() {
        copyState=checkbox->checkState();
       // qDebug()<<copyState;
});
    layout->addWidget(checkbox,7,1,1,3,Qt::AlignHCenter);
   // layout->addWidget(new QLabel("<font size=1>Sayaç</font>"),6,3,1,1,Qt::AlignHCenter);

  //  layout->addWidget(new QLabel("<font size=1>Kapat</font>"),8,1,1,1,Qt::AlignHCenter);


  //  layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

   //  menu->setStyleSheet("QMenu { width: auto; height: auto; }");
   return menu;
}

QMenu *MainWindow::eraseMenu()
{   int e=(en*0.8)/4*9;
    int b=(boy*0.6)/4*5;
    QMenu *menu = new QMenu(this);
    eraseSizePopLabel= new QLabel();
    eraseSizePopLabel->setText("Silgi Boyutu: "+QString::number(myPenSize));
  //  eraseSizePopLabel->resize(e,b);
    QFont ff( "Arial", 8, QFont::Normal);
    eraseSizePopLabel->setFont(ff);

    QSlider *eraseSize= new QSlider(Qt::Horizontal,menu);
    //eraseSize->setMinimum(2);
    //eraseSize->setMaximum(1);
    eraseSize->setRange(1,15);
    eraseSize->setSliderPosition(4);
    connect(eraseSize,SIGNAL(valueChanged(int)),this,SLOT(setEraseSize(int)));
    silMenuButton->setFixedSize(e, b);
    silMenuButton->setIconSize(QSize(e,b));
    temizleMenuButton->setFixedSize(e, b);
    temizleMenuButton->setIconSize(QSize(e,b));

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
   // layout->setContentsMargins(0, 0, 0, 3);
   // layout->setColumnMinimumWidth(0, 37);


    layout->addWidget(eraseSizePopLabel, 1, 1,1,2);
    layout->addWidget(silMenuButton, 2, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(temizleMenuButton, 2, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Sil</font>"),3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Tahta Temizle</font>"),3,2,1,1,Qt::AlignHCenter);

    layout->addWidget(eraseSize,4,1,1,2);
  //  layout->setColumnStretch(6, 255);
    connect(silMenuButton, &QPushButton::clicked, [=]() {
        scene->setPopMenuStatus(false);
        menu->close();
        //kalemButtonClick();
    });
    connect(temizleMenuButton, &QPushButton::clicked, [=]() {
        scene->setPopMenuStatus(false);
        menu->close();
        //kalemButtonClick();
    });
    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);
    eraseSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                   "background: rgba(0, 0, 50, 200);"
                                   "width:"+QString::number(e*3)+"px;"
                                    "height:"+QString::number(b/2)+"px;"
                                   "}"

                                   ".QSlider::handle:Horizontal {"
                                   "background: rgba(242, 242, 242, 95);"
                                   "border: 2px solid rgb(0,0,0);"
                                   "background: rgba(0, 0, 50, 255);"
                                   "width: "+QString::number(e/2)+"px;"
                                   "height: "+QString::number(b)+"px;"
                                    "margin:-"+QString::number(e/8*3)+"px   0   -"+QString::number(b/8*3)+"px   0;"
                                   "}");

    eraseSize->setFixedSize(QSize(e*3,b));
   // menu->setStyleSheet("QMenu { width: 290 px; height: 180 px; }");
   return menu;
}

QMenu *MainWindow::sekilMenu()
{
    int ken=300;
    //ken=300;
    int e=(en*0.8)/4*9;
    int b=(boy*0.6)/4*5;
    QMenu *menu = new QMenu(this);
   // QLabel *sekilLabel= new QLabel();
   // sekilLabel->setText("Geometrik Şekiller");
    sekilKalemSizePopLabel= new QLabel();
    sekilKalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(mySekilPenSize));
    QFont ff( "Arial", 8, QFont::Normal);
    sekilKalemSizePopLabel->setFont(ff);

    QSlider *sekilPenSize= new QSlider(Qt::Horizontal,menu);
    sekilPenSize->setMinimum(2);
    sekilPenSize->setMaximum(8);
    sekilPenSize->setSliderPosition(4);
    connect(sekilPenSize,SIGNAL(valueChanged(int)),this,SLOT(setSekilPenSize(int)));
    /*************************************************************************/
    DiagramItem *ditem=new DiagramItem();

    QPushButton *penStyleSolidLine = new QPushButton;
    penStyleSolidLine->setFixedSize(e, b);
    penStyleSolidLine->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    penStyleSolidLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::SolidLine,ken,ken));
    connect(penStyleSolidLine, &QPushButton::clicked, [=]() {setSekilPenStyle(Qt::SolidLine);});

    QPushButton *penStyleDashLine = new QPushButton;
    penStyleDashLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DashLine,ken,ken));
    penStyleDashLine->setFixedSize(e, b);
    penStyleDashLine->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(penStyleDashLine, &QPushButton::clicked, [=]() {setSekilPenStyle(Qt::DashLine);});

    QPushButton *penStyleDotLine = new QPushButton;
    penStyleDotLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DotLine,ken,ken));
    penStyleDotLine->setFixedSize(e, b);
    penStyleDotLine->setIconSize(QSize(e,b));
   // penStyleDotLine->setFlat(true);
    connect(penStyleDotLine, &QPushButton::clicked, [=]() {setSekilPenStyle(Qt::DotLine);});
/********************************************************************/

  //  DiagramItem *ditem=new DiagramItem();

    QPushButton *cizgi= new QPushButton;
    cizgi->setFixedSize(e, b);
    cizgi->setIconSize(QSize(e,b));
   // cizgi->setFlat(true);
    cizgi->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Cizgi,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cizgi, &QPushButton::clicked, [=]() {
    //    setPenStyle(Qt::SolidLine);
          setSekilType(DiagramItem::DiagramType::Cizgi);
          scene->setMode(Scene::Mode::DrawLine, DiagramItem::DiagramType::Cizgi);

           menu->close();
    });

    QPushButton *ok= new QPushButton;
    ok->setFixedSize(e, b);
    ok->setIconSize(QSize(e,b));
    //ok->setFlat(true);
    ok->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Ok,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ok, &QPushButton::clicked, [=]() {
   setSekilType(DiagramItem::DiagramType::Ok);
   scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Ok);

    menu->close();
    });

    QPushButton *ciftok= new QPushButton;
    ciftok->setFixedSize(e, b);
    ciftok->setIconSize(QSize(e,b));
    //ciftok->setFlat(true);
    ciftok->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::CiftOk,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ciftok, &QPushButton::clicked, [=]() {
        setSekilType(DiagramItem::DiagramType::CiftOk);
        scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::CiftOk);

         menu->close();
    });

    QPushButton *ucgen= new QPushButton;
    ucgen->setFixedSize(e, b);
    ucgen->setIconSize(QSize(e,b));
   // ucgen->setFlat(true);
    ucgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Ucgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(ucgen, &QPushButton::clicked, [=]() {
        setSekilType(DiagramItem::DiagramType::Ucgen);
        scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Ucgen);

         menu->close();
    });

    QPushButton *dortgen= new QPushButton;
    dortgen->setFixedSize(e, b);
    dortgen->setIconSize(QSize(e,b));
    //dortgen->setFlat(true);
    dortgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Dortgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(dortgen, &QPushButton::clicked, [=]() {
       setSekilType(DiagramItem::DiagramType::Dortgen);
       scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Dortgen);

        menu->close();
    });

    QPushButton *cember= new QPushButton;
    cember->setFixedSize(e, b);
    cember->setIconSize(QSize(e,b));
   // cember->setFlat(true);
    cember->setIcon(imageEllipse(ditem->sekilStore(DiagramItem::DiagramType::Cember,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cember, &QPushButton::clicked, [=]() {
      setSekilType(DiagramItem::DiagramType::Cember);
      scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Cember);

       menu->close();
    });

    QPushButton *baklava= new QPushButton;
    baklava->setFixedSize(e, b);
    baklava->setIconSize(QSize(e,b));
    //baklava->setFlat(true);
    baklava->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Baklava,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(baklava, &QPushButton::clicked, [=]() {
        setSekilType(DiagramItem::DiagramType::Baklava);
        scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Baklava);

         menu->close();
    });

    QPushButton *yamuk= new QPushButton;
    yamuk->setFixedSize(e, b);
    yamuk->setIconSize(QSize(e,b));
    //yamuk->setFlat(true);
    yamuk->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Yamuk,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(yamuk, &QPushButton::clicked, [=]() {
         setSekilType(DiagramItem::DiagramType::Yamuk);
         scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Yamuk);

          menu->close();
    });

    QPushButton *besgen= new QPushButton;
    besgen->setFixedSize(e, b);
    besgen->setIconSize(QSize(e,b));
    //esgen->setFlat(true);
    besgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Besgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(besgen, &QPushButton::clicked, [=]() {
 setSekilType(DiagramItem::DiagramType::Besgen);
 scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Besgen);

 menu->close();
 //delete menu;
 //qDebug()<<"sss";
    });

    QPushButton *altigen= new QPushButton;
    altigen->setFixedSize(e, b);
    altigen->setIconSize(QSize(e,b));
    //altigen->setFlat(true);
    altigen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Altigen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(altigen, &QPushButton::clicked, [=]() {
     setSekilType(DiagramItem::DiagramType::Altigen);
     scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Altigen);

      menu->close();
    });

    QPushButton *sekizgen= new QPushButton;
    sekizgen->setFixedSize(e, b);
    sekizgen->setIconSize(QSize(e,b));
    //sekizgen->setFlat(true);
    sekizgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Sekizgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(sekizgen, &QPushButton::clicked, [=]() {
         setSekilType(DiagramItem::DiagramType::Sekizgen);
         scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Sekizgen);

          menu->close();
    });

    QPushButton *dikucgen= new QPushButton;
    dikucgen->setFixedSize(e, b);
    dikucgen->setIconSize(QSize(e,b));
    //dikucgen->setFlat(true);
    dikucgen->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::DikUcgen,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(dikucgen, &QPushButton::clicked, [=]() {
        setSekilType(DiagramItem::DiagramType::DikUcgen);
        scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::DikUcgen);

     menu->close();
    });

    QPushButton *guzelyazi= new QPushButton;
    guzelyazi->setFixedSize(e, b);
    guzelyazi->setIconSize(QSize(e,b));
    //guzelyazi->setFlat(true);
    guzelyazi->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::GuzelYazi,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(guzelyazi, &QPushButton::clicked, [=]() {
         setSekilType(DiagramItem::DiagramType::GuzelYazi);
         scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::GuzelYazi);

     menu->close();
    });

    QPushButton *muzik= new QPushButton;
    muzik->setFixedSize(e, b);
    muzik->setIconSize(QSize(e,b));
    //muzik->setFlat(true);
    muzik->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::Muzik,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(muzik, &QPushButton::clicked, [=]() {
         setSekilType(DiagramItem::DiagramType::Muzik);
         scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Muzik);

          menu->close();
    });

    QPushButton *cizgilisayfa= new QPushButton;
    cizgilisayfa->setFixedSize(e, b);
    cizgilisayfa->setIconSize(QSize(e,b));
   // cizgilisayfa->setFlat(true);
    cizgilisayfa->setIcon(image(ditem->sekilStore(DiagramItem::DiagramType::CizgiliSayfa,QRectF(QPointF(b,b),QPointF(ken-b,ken-b))),ken,ken));
    connect(cizgilisayfa, &QPushButton::clicked, [=]() {
    //    setPenStyle(Qt::SolidLine);
        setSekilType(DiagramItem::DiagramType::CizgiliSayfa);
        scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::CizgiliSayfa);

         menu->close();
    });
    QPushButton *resimEkle= new QPushButton;
    resimEkle->setFixedSize(e, b);
    resimEkle->setIconSize(QSize(e,b));
    resimEkle->setFlat(true);
    resimEkle->setIcon(QIcon(":/icons/addimage.png"));
    connect(resimEkle, &QPushButton::clicked, [=]() {
        Qt::WindowFlags flags = 0;
        flags |= Qt::Window;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::CustomizeWindowHint;
        this->setWindowFlags(flags);

        flags |= Qt::SplashScreen;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::WindowStaysOnTopHint;
        QFileDialog abc;
        abc.setWindowFlags(flags);

        abc.setWindowFlags(flags);
        if(QSysInfo::kernelType()=="linux"){
            QString fileName = abc.getOpenFileName(this,
                                                   tr("Resim Aç jpg png bmp"), QDir::homePath()+"/Masaüstü", tr("Image Files (*.png *.jpg *.bmp)"));
            // qDebug()<<fileName;
            if(fileName!="")
            {
                QPixmap image = QPixmap(fileName);
                scene->setImage(image);
                scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Resim);
            }

        }
        else
        {//windows
            QString fileName = abc.getOpenFileName(this,
                                                   tr("Resim Aç jpg png bmp"), QDir::homePath()+"/desktop", tr("Image Files (*.png *.jpg *.bmp)"));
            if(fileName!="")
            {
                QPixmap image = QPixmap(fileName);
                scene->setImage(image);
                scene->setMode(Scene::Mode::DrawRectangle, DiagramItem::DiagramType::Resim);
            }

        }
        flags |= Qt::Window;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::WindowStaysOnTopHint;
        this->setWindowFlags(flags);
        show();
/***************************************/

         menu->close();
    });
    resimEkle->setFixedSize(e,b);
    resimEkle->setIconSize(QSize(e,b));

    sekilKalemRenkButton->setFixedSize(e,b);
    sekilKalemRenkButton->setIconSize(QSize(e,b));
    sekilZeminRenkButton->setFixedSize(e,b);
    sekilZeminRenkButton->setIconSize(QSize(e,b));

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
   // layout->setContentsMargins(20, 0, 0, 0);
    //layout->setColumnMinimumWidth(0, 37);
    //layout->addWidget(sekilLabel, 0, 1,1,3);
    layout->addWidget(sekilKalemSizePopLabel, 1, 1,1,3);
    layout->addWidget(sekilPenSize, 2, 1,1,3);

    layout->addWidget(penStyleSolidLine, 3, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDashLine, 3, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDotLine, 3, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çizgi</font>"),4,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Kesik Çizgi</font>"),4,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Noktalı Çizgi</font>"),4,3,1,1,Qt::AlignHCenter);


    layout->addWidget(sekilKalemRenkButton, 5, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(resimEkle, 5, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(sekilZeminRenkButton, 5, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Kenar R.</font>"),6,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Resim Ekle</font>"),6,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Zemin Rengi</font>"),6,3,1,1,Qt::AlignHCenter);

    layout->addWidget(cizgi, 8, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(ok, 8, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(ciftok, 8, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çizgi</font>"),9,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Ok</font>"),9,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çift Ok</font>"),9,3,1,1,Qt::AlignHCenter);

    layout->addWidget(ucgen, 10, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(dortgen, 10, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(cember, 10, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Üçgen</font>"),11,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Dörtgen</font>"),11,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çember</font>"),11,3,1,1,Qt::AlignHCenter);

    layout->addWidget(baklava, 15, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(yamuk, 15, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(besgen, 15, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Baklava</font>"),16,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Yamuk</font>"),16,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Beşgen</font>"),16,3,1,1,Qt::AlignHCenter);

    layout->addWidget(altigen, 20, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(sekizgen, 20, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(dikucgen, 20, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Altıgen</font>"),21,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Sekizgen</font>"),21,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Dik Üçgen</font>"),21,3,1,1,Qt::AlignHCenter);

    layout->addWidget(guzelyazi, 25, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(muzik, 25, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(cizgilisayfa, 25, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>G.Yazı</font>"),26,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Müzik</font>"),26,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çizgili Sayfa</font>"),26,3,1,1,Qt::AlignHCenter);

 //   layout->setColumnStretch(10, 255);
    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);
    sekilPenSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                   "background: rgba(0, 0, 0, 200);"
                                   "width:"+ QString::number(e*3.5)+"px;"
                                    "height:"+ QString::number(b/2)+"px;"
                                   "}"

                                   ".QSlider::handle:Horizontal {"
                                   "background: rgba(242, 242, 242, 95);"
                                   "border: 2px solid rgb(0,0,0);"
                                   "background: rgba(0, 0, 0, 255);"
                                   "width: "+ QString::number(e/2)+"px;"
                                   "height:"+ QString::number(b/2)+"px;"
                                    "margin:-"+ QString::number(b/4*3)+"px   0   -"+ QString::number(b/4*3)+"px   0;"
                                   "}");

    sekilPenSize->setFixedSize(QSize(e*3.5,b));
   // menu->setStyleSheet("QMenu { width: 180 px; height: 200 px;/*background: rgba(220, 220, 220, 200);*/ }");
    return menu;
}

QMenu *MainWindow::penMenu()
{
    int ken=300;
    int e=(en*0.8)/4*9;
    int b=(boy*0.6)/4*5;

    QMenu *menu = new QMenu(this);
    kalemSizePopLabel= new QLabel();
    kalemSizePopLabel->setText("Kalem Boyutu: "+QString::number(myPenSize));
    QFont ff( "Arial", 8, QFont::Normal);
    kalemSizePopLabel->setFont(ff);

   /* QSlider *penSize= new QSlider(Qt::Horizontal,menu);
    penSize->setMinimum(2);
    penSize->setMaximum(8);
    penSize->setSliderPosition(4);
    connect(penSize,SIGNAL(valueChanged(int)),this,SLOT(setPenSize(int)));
*/
    DiagramItem *ditem=new DiagramItem();

    QPushButton *penStyleSolidLine = new QPushButton;
    penStyleSolidLine->setFixedSize(e, b);
    penStyleSolidLine->setIconSize(QSize(e,b));
    //penStyleSolidLine->setFlat(true);
    penStyleSolidLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::SolidLine,ken,ken));
    connect(penStyleSolidLine, &QPushButton::clicked, [=]() {setPenStyle(Qt::SolidLine);});

    QPushButton *penStyleDashLine = new QPushButton;
    penStyleDashLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DashLine,ken,ken));
    penStyleDashLine->setFixedSize(e, b);
    penStyleDashLine->setIconSize(QSize(e,b));
    //penStyleDashLine->setFlat(true);
    connect(penStyleDashLine, &QPushButton::clicked, [=]() {setPenStyle(Qt::DashLine);});

    QPushButton *penStyleDotLine = new QPushButton;
    penStyleDotLine->setIcon(lineImage(ditem->sekilStore(DiagramItem::DiagramType::Kalem,QRectF(QPointF(0,0),QPointF(ken,ken))),Qt::DotLine,ken,ken));
    penStyleDotLine->setFixedSize(e, b);
    penStyleDotLine->setIconSize(QSize(e,b));
   // penStyleDotLine->setFlat(true);
    connect(penStyleDotLine, &QPushButton::clicked, [=]() {setPenStyle(Qt::DotLine);});

    QPushButton *kalemSekilTanimlama= new QPushButton;
    kalemSekilTanimlama->setIcon(QIcon(":icons/smartpen.png"));
    kalemSekilTanimlama->setFixedSize(e, b);
    kalemSekilTanimlama->setIconSize(QSize(e,b));
    kalemSekilTanimlama->setFlat(true);



    kalemMenuButton->setFixedSize(e, b);
    kalemMenuButton->setIconSize(QSize(e,b));

    //connect(penBtn, &QPushButton::clicked, [=]() {/*setPenStyle(Qt::DotLine);*/
   // penBtn->setIcon(QIcon(":icons/selectpen.png"));
    //});
    QPushButton *nokta2 = new QPushButton;
    nokta2->setIcon(QIcon(":icons/nokta.png"));
    nokta2->setFixedSize(e*0.4, b);
    nokta2->setIconSize(QSize(e*0.2,b*0.2));
    nokta2->setFlat(true);
    connect(nokta2, &QPushButton::clicked, [=]() {setPenSize(1);});

    QPushButton *nokta4 = new QPushButton;
    nokta4->setIcon(QIcon(":icons/nokta.png"));
    nokta4->setFixedSize(e*0.4, b);
    nokta4->setIconSize(QSize(e*0.4,b*0.4));
    nokta4->setFlat(true);
    connect(nokta4, &QPushButton::clicked, [=]() {setPenSize(2);});

    QPushButton *nokta6 = new QPushButton;
    nokta6->setIcon(QIcon(":icons/nokta.png"));
    nokta6->setFixedSize(e*0.4, b);
    nokta6->setIconSize(QSize(e*0.6,b*0.6));
    nokta6->setFlat(true);
    connect(nokta6, &QPushButton::clicked, [=]() {setPenSize(3);});

    QPushButton *nokta8 = new QPushButton;
    nokta8->setIcon(QIcon(":icons/nokta.png"));
    nokta8->setFixedSize(e*0.4, b);
    nokta8->setIconSize(QSize(e*0.8,b*0.8));
    nokta8->setFlat(true);
    connect(nokta8, &QPushButton::clicked, [=]() {setPenSize(4);});

    QPushButton *nokta10 = new QPushButton;
    nokta10->setIcon(QIcon(":icons/nokta.png"));
    nokta10->setFixedSize(e*0.4, b);
    nokta10->setIconSize(QSize(e*1,b*1));
    nokta10->setFlat(true);
    connect(nokta10, &QPushButton::clicked, [=]() {setPenSize(5);});

    QPushButton *nokta12 = new QPushButton;
    nokta12->setIcon(QIcon(":icons/nokta.png"));
    nokta12->setFixedSize(e*0.4, b);
    nokta12->setIconSize(QSize(e*1.2,b*1.2));
    nokta12->setFlat(true);
    connect(nokta12, &QPushButton::clicked, [=]() {setPenSize(6);});

    QPushButton *nokta14 = new QPushButton;
    nokta14->setIcon(QIcon(":icons/nokta.png"));
    nokta14->setFixedSize(e*0.4, b);
    nokta14->setIconSize(QSize(e*1.4,b*1.4));
    nokta14->setFlat(true);
    connect(nokta14, &QPushButton::clicked, [=]() {setPenSize(7);});

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
   // layout->setContentsMargins(0, 0, 0, 3);
   // layout->setColumnMinimumWidth(0, 37);

    fosforluKalemButton->setFixedSize(e, b);
    fosforluKalemButton->setIconSize(QSize(e,b));
   // geriAlButton->setFixedSize(70, 50);
    //geriAlButton->setIconSize(QSize(70,50));

    connect(kalemMenuButton, &QPushButton::clicked, [=]() {

        scene->setPopMenuStatus(false);
        menu->close();
        scene->setSekilTanimlamaStatus(false);

    });
    connect(kalemButton, &QPushButton::clicked, [=]() {

       // scene->setPopMenuStatus(false);
        //menu->close();
        scene->setSekilTanimlamaStatus(false);


    });
    connect(fosforluKalemButton, &QPushButton::clicked, [=]() {

        scene->setPopMenuStatus(false);
        menu->close();
        //kalemButtonClick();
        scene->setSekilTanimlamaStatus(false);

    });
    connect(kalemSekilTanimlama, &QPushButton::clicked, [=]()
    {
        scene->setPopMenuStatus(false);
        menu->close();
        kalemButtonClick();
        scene->setSekilTanimlamaStatus(true);
        buttonColorClear();
        palette->setColor(QPalette::Button, QColor(212,0,0,255));
       // kalemSekilTanimlama->setPalette(*palette);
        //kalemSekilTanimlama->setAutoFillBackground(true);
        kalemButton->setPalette(*palette);
        kalemButton->setAutoFillBackground(true);
        kalemButton->setIcon(QIcon(":icons/smartpen.png"));
//kalemButton->setIconSize(QSize(20,20));
    });

    layout->addWidget(kalemSizePopLabel, 0, 1,1,3);
 //   layout->addWidget(geriAlButton,1,2,1,1);
//    layout->addWidget(new QLabel("<font size=1>Geri Al</font>"),2,2,1,1,Qt::AlignHCenter);

    layout->addWidget(kalemMenuButton,3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(fosforluKalemButton,3,3,1,1,Qt::AlignHCenter);
 //   layout->addWidget(kalemSekilTanimlama,3,3,1,2,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Kalem</font>"),4,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Fosforlu Kalem</font>"),4,3,1,1,Qt::AlignHCenter);
  //  layout->addWidget(new QLabel("<font size=1>Akıllı Kalem</font>"),4,3,1,1,Qt::AlignHCenter);

   // layout->addWidget(penSize,5,1,1,3,Qt::AlignHCenter);

    QHBoxLayout *layout1 = new QHBoxLayout;
         layout1->addWidget(nokta2);
         layout1->addWidget(nokta4);
         layout1->addWidget(nokta6);
         layout1->addWidget(nokta8);
         layout1->addWidget(nokta10);
         layout1->addWidget(nokta12);
         layout1->addWidget(nokta14);


    layout->addLayout(layout1, 6, 1,1,3,Qt::AlignHCenter);
    //layout->addWidget(nokta4, 6, 2,1,1,Qt::AlignHCenter);
    //layout->addWidget(nokta8, 6, 3,1,1,Qt::AlignHCenter);
    //layout->addWidget(nokta12, 6, 4,1,1,Qt::AlignHCenter);

    layout->addWidget(penStyleSolidLine, 7, 1,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDashLine, 7, 2,1,1,Qt::AlignHCenter);
    layout->addWidget(penStyleDotLine, 7, 3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Düz</font>"),8,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Kesik</font>"),8,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Noktalı</font>"),8,3,1,1,Qt::AlignHCenter);


  //  layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);
   /* penSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                   "background: rgba(0, 0, 0, 200);"
                                   "width:"+QString::number(e*4)+"px;"
                                    "height: "+QString::number(b/2)+"px;"
                                   "}"

                                   ".QSlider::handle:Horizontal {"
                                   "background: rgba(242, 242, 242, 95);"
                                   "border: 2px solid rgb(0,0,0);"
                                   "background: rgba(0, 0, 0, 255);"
                                   "width: "+QString::number(e/2)+"px;"
                                   "height: "+QString::number(b)+"px;"
                                    "margin:-"+QString::number(e/8*3)+"px   0   -"+QString::number(b/8*3)+"px   0;"
                                   "}");
*/
   // penSize->setFixedSize(QSize(e*4,b));
    //menu->setStyleSheet("QMenu { width: 290 px; height: 250 px; }");
return menu;
}

QMenu *MainWindow::zeminMenu()
{  //int e=en;
   // int b=boy;
    int e=(en*0.8)/4*9;
    int b=(boy*0.6)/4*5;

    QMenu *menu = new QMenu(this);
    QLabel  *zeminLabel= new QLabel();
    zeminLabel->setText("Arkaplan Seçenekleri");
    QFont ff( "Arial", 8, QFont::Normal);
    zeminLabel->setFont(ff);

    gridSizePopLabel= new QLabel();
    gridSizePopLabel->setText("Grid Boyutu: "+QString::number(myGridSize));
    gridSizePopLabel->setFont(ff);

    QSlider *penSize= new QSlider(Qt::Horizontal,menu);
    penSize->setMinimum(2);
    penSize->setMaximum(8);
    penSize->setSliderPosition(4);
    connect(penSize,SIGNAL(valueChanged(int)),this,SLOT(setGridSize(int)));


    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    //layout->setContentsMargins(0, 0, 0, 3);
    //layout->setColumnMinimumWidth(0, 37);
    zeminSeffafButton->setFixedSize(e, b);zeminSeffafButton->setIconSize(QSize(e,b));
    zeminSiyahButton->setFixedSize(e, b);zeminSiyahButton->setIconSize(QSize(e,b));
    zeminBeyazButton->setFixedSize(e, b);zeminBeyazButton->setIconSize(QSize(e,b));
    gridYatayButton->setFixedSize(e, b);gridYatayButton->setIconSize(QSize(e,b));
    gridDikeyButton->setFixedSize(e, b);gridDikeyButton->setIconSize(QSize(e,b));
    gridDisableButton->setFixedSize(e, b);gridDisableButton->setIconSize(QSize(e,b));
    zeminCustomColorButton->setFixedSize(e, b);zeminCustomColorButton->setIconSize(QSize(e,b));
    zeminMuzikButton->setFixedSize(e, b);zeminMuzikButton->setIconSize(QSize(e,b));
    zeminGuzelYaziButton->setFixedSize(e, b);zeminGuzelYaziButton->setIconSize(QSize(e,b));
    openButton->setFixedSize(e, b);openButton->setIconSize(QSize(e,b));

    DiagramItem *ditem=new DiagramItem();
    int ken=300;
    QPushButton *zeminCizgiliSayfaButton = new QPushButton;
    zeminCizgiliSayfaButton->setIcon(QIcon(":icons/cizgiliSayfa.png"));
    zeminCizgiliSayfaButton->setFixedSize(e, b);
    zeminCizgiliSayfaButton->setIconSize(QSize(e,b));
    zeminCizgiliSayfaButton->setFlat(true);
    connect(zeminCizgiliSayfaButton, &QPushButton::clicked, [=]()
    {
          myZeminColor=QColor(0,0,0,0);
        gridDisableButtonClick();
        DiagramItem *ditem=new DiagramItem();
        mySekilType=DiagramItem::DiagramType::CizgiliSayfa;
        QPixmap pim(zeminImage(ditem->sekilStore(mySekilType,QRectF(QPointF(0,0),QPointF(this->width(),this->height()))),this->width(),this->height(),myGridColor,2));
        scene->setForegroundBrush(pim);

        //setSekilPenStyle(Qt::DashLine);
    });
/*    QPushButton *zeminTemizleButton = new QPushButton;
    zeminTemizleButton->setIcon(QIcon(":icons/zeminTemizle.png"));
    zeminTemizleButton->setFixedSize(e, b);
    zeminTemizleButton->setIconSize(QSize(e,b));
    zeminTemizleButton->setFlat(true);
    connect(zeminTemizleButton, &QPushButton::clicked, [=]()
    {
       scene->setForegroundBrush(QColor(0,0,0,0));
        scene->setPopMenuStatus(false);
      //  menu->close();
      //  gridOnOffButtonClick();

    });*/

    QPushButton *gridRenkButton = new QPushButton;
    gridRenkButton->setIcon(QIcon(":icons/gridRenk.png"));
    gridRenkButton->setFixedSize(e, b);
    gridRenkButton->setIconSize(QSize(e,b));
    gridRenkButton->setFlat(true);
    palette->setColor(QPalette::Button, myGridColor);
    gridRenkButton->setPalette(*palette);
    gridRenkButton->update();

    connect(gridRenkButton, &QPushButton::clicked, [=]()
    {
        scene->setPopMenuStatus(false);

        Qt::WindowFlags flags = 0;
        flags |= Qt::Dialog;
        flags |= Qt::X11BypassWindowManagerHint;
        QColorDialog abc(this);
        abc.setWindowFlags(flags);
        abc.setCurrentColor(myGridColor);
        abc.exec();

        QColor newColor = abc.selectedColor();
         if (newColor.isValid())
          {
            /// qDebug()<<"renk seçildi"<<scene->sceneGridYatay<<scene->sceneGridDikey<<scene->sceneGuzelYazi;
            myGridColor = QColor(newColor.red(),newColor.green(),newColor.blue(),128);
            palette->setColor(QPalette::Button, myGridColor);
            gridRenkButton->setPalette(*palette);
            gridRenkButton->setAutoFillBackground(true);
            gridRenkButton->update();
            if(scene->sceneGridYatay) gridYatayButtonClick(scene->sceneGridYatay);
            if(scene->sceneGridDikey) gridDikeyButtonClick(scene->sceneGridDikey);
            if(scene->sceneGuzelYazi) zeminGuzelYaziButtonClick(scene->sceneGuzelYazi);

               }

    });

    connect(zeminSeffafButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(zeminSiyahButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(zeminBeyazButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(zeminCustomColorButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(zeminCizgiliSayfaButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(zeminMuzikButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(zeminGuzelYaziButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
  ///  connect(zeminTemizleButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(gridRenkButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(gridYatayButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(gridDikeyButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});
    connect(gridDisableButton, &QPushButton::clicked, [=](){scene->setPopMenuStatus(false);/* menu->close();*/});

    layout->addWidget(zeminLabel, 0, 1,1,3);
    layout->addWidget(gridSizePopLabel, 1, 1,1,3);
    layout->addWidget(zeminSeffafButton,2,1,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminSiyahButton,2,2,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminBeyazButton,2,3,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminCustomColorButton,2,4,1,1,Qt::AlignHCenter);


    layout->addWidget(new QLabel("<font size=1>Şeffaf Tahta</font>"),3,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Siyah Tahta</font>"),3,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Beyaz Tahta</font>"),3,3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Zemin Rengi Seç</font>"),3,4,1,1,Qt::AlignHCenter);


    layout->addWidget(zeminCizgiliSayfaButton,5,1,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminMuzikButton,5,2,1,1,Qt::AlignHCenter);
    layout->addWidget(zeminGuzelYaziButton,5,3,1,1,Qt::AlignHCenter);
    layout->addWidget(openButton,5,4,1,1,Qt::AlignHCenter);

    layout->addWidget(new QLabel("<font size=1>Çizgi Deseni</font>"),6,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Müzik Deseni</font>"),6,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Güzelyazı</font>"),6,3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Desen Resim Ekle</font>"),6,4,1,1,Qt::AlignHCenter);

    layout->addWidget(penSize,10,1,1,4,Qt::AlignHCenter);

    layout->addWidget(gridRenkButton,15,1,1,1,Qt::AlignHCenter);
    layout->addWidget(gridYatayButton,15,2,1,1,Qt::AlignHCenter);
    layout->addWidget(gridDikeyButton,15,3,1,1,Qt::AlignHCenter);
    layout->addWidget(gridDisableButton,15,4,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çizgi Rengi Seç</font>"),16,1,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Yatay Çizgi</font>"),16,2,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Dikey Çizgi</font>"),16,3,1,1,Qt::AlignHCenter);
    layout->addWidget(new QLabel("<font size=1>Çizgi Temizle</font>"),16,4,1,1,Qt::AlignHCenter);

    //openButton->show();
    //openButton->resize(e,b);
   // layout->addWidget( openButton,17,2,1,1,Qt::AlignHCenter);
   // layout->addWidget(new QLabel("<font size=1>Resim Ekle</font>"),18,2,1,1,Qt::AlignHCenter);

    //layout->setColumnStretch(6, 255);
    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
    //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

    penSize->setStyleSheet(".QSlider::groove:Horizontal {"
                                   "background: rgba(0, 0, 0, 200);"
                                   "width:"+QString::number(e*4.5)+"px;"
                                    "height: "+QString::number(b/2)+"px;"
                                   "}"

                                   ".QSlider::handle:Horizontal {"
                                   "background: rgba(242, 242, 242, 95);"
                                   "border: 2px solid rgb(0,0,0);"
                                   "background: rgba(0, 0, 0, 255);"
                                   "width: "+QString::number(e/2)+"px;"
                                   "height: "+QString::number(b)+"px;"
                                    "margin:-"+QString::number(e/8*3)+"px   0   -"+QString::number(b/8*3)+"px   0;"
                                   "}");

    penSize->setFixedSize(QSize(e*4.5,b));

   // menu->setStyleSheet("QMenu { width: 340 px; height: 410 px; }");
return menu;
}




#endif // POPMENU_H
