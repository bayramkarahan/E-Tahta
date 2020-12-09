#ifndef BUTTONCLICK_H
#define BUTTONCLICK_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include<mainwindow.h>
#include<depo.h>
class ExceptionEx; // Class which is inherited std::exception
void MainWindow::screenClickButtonClick()
{

    iconButton();
    buttonColorClear();

    if(screenClickDrm)
    {  //qDebug()<<"pasif";
        screenClickDrm=false;
        currentScreenModeSlot();
        palette->setColor(QPalette::Button, QColor(0,0,0,0));
        screenClickButton->setPalette(*palette);
        screenClickButton->setAutoFillBackground(true);
        //currentScreenMode=tempcurrentScreenMode;
        scene->setMode(currentScreenMode, DiagramItem::DiagramType::NoType);
        scene->setMousePressStatus(true);
        //
    }else
    {
        //qDebug()<<"aktif";
        screenClickDrm=true;
        palette->setColor(QPalette::Button, QColor(212,0,0,255));
        screenClickButton->setPalette(*palette);
        screenClickButton->setAutoFillBackground(true);
       // tempcurrentScreenMode=currentScreenMode;
        scene->setMode(Scene::Mode::NoMode, DiagramItem::DiagramType::NoType);
    scene->setMousePressStatus(false);
    //currentScreenModeSlot();

    }

}
/*void MainWindow::penColorButtonClick()
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    flags |= Qt::X11BypassWindowManagerHint;
    QColorDialog abc(this);
    abc.setWindowFlags(flags);
    abc.setCurrentColor(myPenColor);
    abc.exec();

    QColor newColor = abc.selectedColor();
    if (newColor.isValid())
        setPenColor(newColor);

}*/
void MainWindow::kalemRenkButtonClick()
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    flags |= Qt::X11BypassWindowManagerHint;
    QColorDialog abc(this);
    abc.setWindowFlags(flags);
    abc.setCurrentColor(myPenColor);
    abc.exec();

    QColor newColor = abc.selectedColor();
    if (newColor.isValid())
        setPenColor(newColor);

}
void MainWindow::geriAlButtonClick()
{
    Scene::Mode tempMode=currentScreenMode;
 scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
     scene->setMode(tempMode,mySekilType);

currentScreenModeSlot();
   //kalemButtonClick();
}
void MainWindow::sekilZeminRenkButtonClick(){

    sekilZeminRenkDrm=(!sekilZeminRenkDrm)?true:false;

    if(sekilZeminRenkDrm)

    {
        Qt::WindowFlags flags = 0;
        flags |= Qt::Dialog;
        flags |= Qt::X11BypassWindowManagerHint;
        QColorDialog abc(this);
        abc.setWindowFlags(flags);
        abc.setCurrentColor(mySekilZeminColor);
        abc.exec();
        sekilZeminRenkButton->setIcon(QIcon(":icons/sekilZeminRenk.png"));
        sekilZeminRenkButton->setAutoFillBackground(true);

        QColor newColor = abc.selectedColor();
           if (newColor.isValid())
             {
               palette->setColor(QPalette::Button,newColor);
               sekilZeminRenkButton->setPalette(*palette);
               sekilZeminRenkButton->update();

           mySekilZeminColor=newColor;
           scene->setSekilZeminColor(mySekilZeminColor);
           }

    }else
    {
          sekilZeminRenkButton->setIcon(QIcon(":icons/sekilZeminRenk.png"));
        //  myZeminColor = QColor(newColor.red(),newColor.green(),newColor.blue(),alpha);
          palette->setColor(QPalette::Button, QColor(0,0,0,0));
          sekilZeminRenkButton->setPalette(*palette);
          sekilZeminRenkButton->update();
          scene->setSekilZeminColor(QColor(0,0,0,0));
          mySekilZeminColor=QColor(0,0,0,0);
    }
}
void MainWindow::sekilKalemRenkButtonClick(){

    sekilKalemRenkDrm=(!sekilKalemRenkDrm)?true:false;

    if(sekilKalemRenkDrm)

    { Qt::WindowFlags flags = 0;
        flags |= Qt::Dialog;
        flags |= Qt::X11BypassWindowManagerHint;
        QColorDialog abc(this);
        abc.setWindowFlags(flags);
        abc.setCurrentColor(mySekilKalemColor);
        abc.exec();

        QColor newColor = abc.selectedColor();
        sekilKalemRenkButton->setIcon(QIcon(":icons/sekilKalemRenk.png"));
        sekilKalemRenkButton->setAutoFillBackground(true);

        if (newColor.isValid())
            setPenColor(newColor);
             if (newColor.isValid())
             {
               palette->setColor(QPalette::Button,newColor);
               sekilKalemRenkButton->setPalette(*palette);
               sekilKalemRenkButton->update();

           mySekilKalemColor=newColor;
           scene->setSekilKalemColor(mySekilKalemColor);
           }

    }else
    {
          sekilKalemRenkButton->setIcon(QIcon(":icons/sekilKalemRenk.png"));
        //  myZeminColor = QColor(newColor.red(),newColor.green(),newColor.blue(),alpha);
          palette->setColor(QPalette::Button, QColor(0,0,0,0));
          sekilKalemRenkButton->setPalette(*palette);
          sekilKalemRenkButton->update();
          scene->setSekilKalemColor(QColor(0,0,0,255));
          mySekilKalemColor=QColor(0,0,0,255);
    }
}
void MainWindow::kirmiziButtonClick(){
    QColor newColor = QColor(255,0,0); setPenColor(newColor);currentScreenModeSlot();//kalemButtonClick();
}


void MainWindow::maviButtonClick(){
    QColor newColor = QColor(0,0,255); setPenColor(newColor);currentScreenModeSlot();//kalemButtonClick();
}
void MainWindow::siyahButtonClick(){
    QColor newColor = QColor(0,0,0); setPenColor(newColor);currentScreenModeSlot();//kalemButtonClick();
}
void MainWindow::kalemButtonClick(){
    scene->setMode(Scene::Mode::DrawPen, DiagramItem::DiagramType::NoType);
    currentScreenMode=Scene::Mode::DrawPen;
    iconButton();
    buttonColorClear();
    palette->setColor(QPalette::Button, QColor(212,0,0,255));
    setPenAlpha(250);
    setPenColor(myPenColor);
   // setPenSize(myPenSize);
    scene->setPenSize(myPenSize);
    setPenStyle(myPenStyle);
    setPenAlpha(myPenAlpha);
     kalemButton->setIcon(QIcon(":icons/pen.png"));
    scene->setSekilTanimlamaStatus(false);
    currentScreenModeSlot();
}
void MainWindow::kalemPopButtonClick(){}
void MainWindow::silPopButtonClick(){}
void MainWindow::silMenuButtonClick(){/*silButtonClick'e bağlıdır*/}
void MainWindow::temizleMenuButtonClick(){/*temizleButtonClick'e bağlıdır*/}
void MainWindow::kalemMenuButtonClick(){/*kalemButtonClick'e bağlıdır*/}
void MainWindow::pagePopButtonClick(){}
//void MainWindow::pageButtonClick(){/*silButtonClick'e bağlıdır*/}
void MainWindow::zeminButtonClick(){}
void MainWindow::zeminPopButtonClick(){}
void MainWindow::sekilButtonClick(){
    DiagramItem *ditem=new DiagramItem();
    int ken=300;
     if(DiagramItem::DiagramType::Cember==mySekilType)
    {
         QPixmap pixmap(imageEllipse(ditem->sekilStore(mySekilType,QRectF(QPointF(20,50),QPointF(ken-50,ken-50))),ken,ken));
         sekilButton->setIcon(pixmap);
    }
    else
    {
         QPixmap pixmap(image(ditem->sekilStore(mySekilType,QRectF(QPointF(20,50),QPointF(ken-50,ken-50))),ken,ken));
         sekilButton->setIcon(pixmap);
     }
 /*   if(mySekilType==DiagramItem::DiagramType::Cizgi)
        scene->setMode(Scene::Mode::DrawLine, mySekilType);
    else*/
        scene->setMode(Scene::Mode::DrawRectangle, mySekilType);
      //  Scene::Mode tempMode=currentScreenMode;
    currentScreenMode=Scene::Mode::DrawRectangle;
     scene->setSekilPenSize(mySekilPenSize);
     scene->setSekilKalemColor(mySekilKalemColor);
     scene->setSekilPenStyle(mySekilPenStyle);
    // iconButton();
     buttonColorClear();
    // secButton->setIcon(QIcon(":icons/selectpointer.png"));
  /*  palette->setColor(QPalette::Button, QColor(212,0,0,255));
     sekilButton->setPalette(*palette);
     sekilButton->setAutoFillBackground(true);
     */
     currentScreenModeSlot();

}
void MainWindow::sekilPopButtonClick(){}
void MainWindow::fosforluKalemButtonClick(){
    //myPenAlpha=35;
    setPenAlpha(100);
    setPenColor(myPenColor);
    scene->setMode(Scene::Mode::DrawPenFosfor, DiagramItem::DiagramType::NoType);
    iconButton();
    buttonColorClear();
    palette->setColor(QPalette::Button, QColor(212,0,0,255));
    fosforluKalemButton->setPalette(*palette);
    fosforluKalemButton->setAutoFillBackground(true);
    kalemButton->setPalette(*palette);
    kalemButton->setAutoFillBackground(true);
    kalemButton->setIcon(QIcon(":icons/fosforlupen.png"));

}
void MainWindow::silButtonClick(){
    /*QPixmap p(":/icons/erase.png");
    QPixmap pResult;
    QTransform trans = QTransform();
    trans.rotate(0);
    pResult = p.transformed(trans);
    setCursor(pResult.scaled(24,24,Qt::KeepAspectRatio));
*/
    scene->setMode(Scene::Mode::EraseMode, DiagramItem::DiagramType::NoType);
    currentScreenMode=Scene::Mode::EraseMode;
    iconButton();
    buttonColorClear();
    palette->setColor(QPalette::Button, QColor(212,0,0,255));
    silButton->setPalette(*palette);
    silButton->setAutoFillBackground(true);
    scene->setEraseSize(myEraseSize);
    currentScreenModeSlot();

   //
   /* QPixmap pd(":/icons/erase.png");
    QPixmap pResult;
    QTransform trans = QTransform();
   pResult = pd.transformed(trans);
   setCursor(pResult.scaled(50,50,Qt::KeepAspectRatio));
*/

}
void MainWindow::temizleButtonClick(){
    Scene::Mode tempMode=currentScreenMode;

    scene->setMode(Scene::Mode::ClearMode, DiagramItem::DiagramType::NoType);
    scene->setMode(tempMode,mySekilType);

    //kalemButtonClick();
//    qDebug()<<"as:"<<depo::as;
}

void MainWindow::ekranButtonClick(){

buttonColorClear();
                                    //scene->setMode(Scene::Mode::ScreenMode, DiagramItem::DiagramType::NoMode);

                                    if(screenDesktop)
                                       {
                                           //  qDebug()<<"ekran aktif";
                                        screenDesktop=false;
                                        if(gizleGoster)
                                        {
                                            timerGizle->stop();
                                          //  qDebug()<<"dur"<<gizleGoster<<screenDesktop;
                                        }

                                        this->resize(0,0);
                                       // this->move(kutuLeft,kutuHeight-boy-boy/2);
                                       // this->setGeometry(QRect(kutuLeft,kutuHeight-boy-boy/2,kutuWidth,boy));
                                         view->hide();
                                         Qt::WindowFlags flags = 0;
                                        flags |= Qt::Window;
                                        flags |= Qt::X11BypassWindowManagerHint;
                                        flags |= Qt::WindowStaysOnTopHint;
                                        this->setWindowFlags(flags);
                                        this->show();
                                        this->setMinimumSize(0,0);
                                        QSize screenSize = qApp->screens()[0]->size();
                                       if(gizleGoster==false)
                                       {
                                           //qDebug()<<"hehe";
                                        //this->setGeometry(QRect(screenSize.width()-kutuWidth-15,kutuTop,kutuWidth,kutuHeight-boy*0.75*6));
                                         this->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight-boy*0.75*6));

                                           buyukKutu->setGeometry(0,0,kutuWidth,kutuHeight-boy*0.75*6);
                                       }
                                        else
                                       {
                                           // qDebug()<<"hihi";
                                       // this->setGeometry(QRect(screenSize.width()-kutuWidth-15,kutuTop,kutuWidth,kutuHeight));
                                          this->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight));

                                            buyukKutu->setGeometry(0,0,kutuWidth,kutuHeight);
                                       }

                                               /*  tasiButton->hide();
                                        colorButton->hide();
                                             clockButton->hide();
                                            secButton->hide();

                                           gizleGosterButton->hide();
                                           */
                                       view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                                       view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

                                         ///   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                                         ///  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                                          /* kalemKapatButton->hide();

                                            hideButton();

*/
                                          ///  buyukKutu->setGeometry(QRect(0,0,kutuWidth,kutuHeight));
                                           // buyukKutu->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight));

                                            ekranButton->setIcon(QIcon(":icons/screenpen.png"));
                                            palette->setColor(QPalette::Button, QColor(212,0,0,255));
                                            ekranButton->setPalette(*palette);
                                            ekranButton->setAutoFillBackground(true);


                                    }
                                       else
                                       {
                                        screenDesktop=true;
                                        if(gizleGoster)
                                        {
                                           timerGizle->start(15000);
                                          //  qDebug()<<"dur"<<gizleGoster<<screenDesktop;
                                        }

                                        if(gizleGoster==true)
                                        { //qDebug()<<"hehe";
                                            buyukKutu->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight));
                                        }
                                        else
                                        {
                                            // qDebug()<<"hihi";
                                            buyukKutu->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight-boy*0.75*6));
                                        }
                                        QSize screenSize = qApp->screens()[0]->size();

                                            setGeometry(0,0,screenSize.width(),screenSize.height());
                                        ekranButton->setIcon(QIcon(":icons/screendesktop.png"));
                                      /*  tasiButton->show();
                                        colorButton->show();
                                        clockButton->show();

                                        secButton->show();



                                          gizleGosterButton->show();
                                          kalemKapatButton->show();
                                            showPenButton();
                                          showZeminButton();
                                          showPcButton();
                                          */
                                        view->show();
                                      ///  view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
                                      /// view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                                        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                                        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

                                          //ScreenMode;
                                          //scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);


                                           if(myZeminType==0) zeminSeffafButtonClick();
                                           if(myZeminType==1) zeminSiyahButtonClick();
                                           if(myZeminType==2) zeminBeyazButtonClick();
                                           if(myZeminType==3) zeminCustomColorInitButtonClick();

                                       }

                                     }
void MainWindow::kalemKapatButtonClick(){sayfaListeView->close();close();}
void MainWindow::gridOnOffButtonClick(){gridYatay=false;gridDikey=false;guzelYazi=false;
gridLines = new GridLines (this->width(), this->height(),myPenSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, QColor(128,128,128,255));
                                    QSize screenSize = qApp->screens()[0]->size();

                                    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
                                    //scene->setBackgroundBrush(bkgnd);
                                    this->setAttribute(Qt::WA_TranslucentBackground, false);
                                    this->setAttribute(Qt::WA_NoSystemBackground, false);
                                    //this->setAttribute(Qt::WA_NoBackground,true);
                                    this->repaint();
                                    QPalette palet;
                                    palet.setBrush(QPalette::Background, bkgnd);
                                    this->setPalette(palet);}
void MainWindow::gridYatayButtonClick(){gridYatay=true;guzelYazi=false;
gridLines = new GridLines (this->width(), this->height(),myGridSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, myGridColor);
                                  //  qDebug()<<myZeminColor;
                                    QSize screenSize = qApp->screens()[0]->size();

                                    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
                                    //scene->setBackgroundBrush(bkgnd);

                                    this->setAttribute(Qt::WA_TranslucentBackground, false);
                                    this->setAttribute(Qt::WA_NoSystemBackground, false);
                                    //this->setAttribute(Qt::WA_NoBackground,true);
                                    this->repaint();
                                    QPalette palet;
                                    palet.setBrush(QPalette::Background, bkgnd);
                                    this->setPalette(palet);
                                    scene->setBackgroundBrush(QColor(0,0,0,0));
                                       }
void MainWindow::gridDikeyButtonClick(){gridDikey=true;guzelYazi=false;
gridLines = new GridLines (this->width(), this->height(),myGridSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, myGridColor);
                                    QSize screenSize = qApp->screens()[0]->size();

                                    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
                                    //scene->setBackgroundBrush(bkgnd);

                                    this->setAttribute(Qt::WA_TranslucentBackground, false);
                                    this->setAttribute(Qt::WA_NoSystemBackground, false);
                                    //this->setAttribute(Qt::WA_NoBackground,true);
                                    this->repaint();
                                    QPalette palet;
                                    palet.setBrush(QPalette::Background, bkgnd);
                                    this->setPalette(palet);
                                       scene->setBackgroundBrush(QColor(0,0,0,0));
                                       }
void MainWindow::zeminSeffafButtonClick(){
   // qDebug()<<myZeminColor;
   // myZeminColor=QColor(0,0,0,0);
     //myZeminColor.setAlpha(0);
   //  qDebug()<<myZeminColor;
     myZeminType=0;

     myZeminColor=QColor(0,0,0,0);guzelYazi=false;
 gridLines = new GridLines (this->width(), this->height(),myGridSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, QColor(128,128,128,255));
 QSize screenSize = qApp->screens()[0]->size();

 QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
 //scene->setBackgroundBrush(bkgnd);

 this->setAttribute(Qt::WA_TranslucentBackground, true);
 this->setAttribute(Qt::WA_NoSystemBackground, false);
 //this->setAttribute(Qt::WA_NoBackground,true);
 this->repaint();
 QPalette palet;
 palet.setBrush(QPalette::Background, bkgnd);
 this->setPalette(palet);  //setZeminColor(myZeminColor);

    /*guzelYazi=false;gridYatay=false;gridDikey=false;
    gridLines = new GridLines (this->width(), this->height(),myPenSize*10,gridYatay,gridDikey,guzelYazi,QColor(0,0,0,0), QColor(128,128,128,255));
    QPixmap bkgnd=gridLines->PixItem(gridLines,mainScreenSize.width(),mainScreenSize.height());
    //scene->setBackgroundBrush(bkgnd);
     //scene->setBackgroundBrush(QColor(0,0,0,0));
   // this->setAttribute(Qt::WA_TranslucentBackground, false);
    this->setAttribute(Qt::WA_NoSystemBackground, false);
    this->setAttribute(Qt::WA_NoBackground,false);

    QPalette palet;
    palet.setBrush(QPalette::Background, bkgnd);
   // this->setPalette(palet);
   // setBackgroundBrush(QBrush::red);
     // setZeminColor(myZeminColor);
    //setAttribute(Qt::WA_TranslucentBackground, true);
    */

}
void MainWindow::zeminSiyahButtonClick(){
    myZeminType=1;
    myZeminColor=QColor(0,0,0,255);guzelYazi=false;
gridLines = new GridLines (this->width(), this->height(),myGridSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, QColor(128,128,128,255));
QSize screenSize = qApp->screens()[0]->size();

QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
//scene->setBackgroundBrush(bkgnd);

this->setAttribute(Qt::WA_TranslucentBackground, false);
this->setAttribute(Qt::WA_NoSystemBackground, false);
//this->setAttribute(Qt::WA_NoBackground,true);
this->repaint();
QPalette palet;
palet.setBrush(QPalette::Background, bkgnd);
this->setPalette(palet);  //setZeminColor(myZeminColor);
}
void MainWindow::zeminBeyazButtonClick(){
    myZeminType=2;

    myZeminColor=QColor(255,255,255,255);guzelYazi=false;
gridLines = new GridLines (this->width(), this->height(),myGridSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, QColor(128,128,128,255));
QSize screenSize = qApp->screens()[0]->size();

QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
//scene->setBackgroundBrush(bkgnd);
this->setAttribute(Qt::WA_TranslucentBackground, false);
this->setAttribute(Qt::WA_NoSystemBackground, false);
//this->setAttribute(Qt::WA_NoBackground,true);
this->repaint();
QPalette palet;
palet.setBrush(QPalette::Background, bkgnd);
this->setPalette(palet);   // setZeminColor(myZeminColor);
}
void MainWindow::zeminCustomColorButtonClick(){
   // qDebug()<<"selam";
    myZeminType=3;
    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    flags |= Qt::X11BypassWindowManagerHint;
    QColorDialog abc(this);
    abc.setWindowFlags(flags);
    abc.setCurrentColor(myZeminColor);
    abc.exec();
 QColor newColor = abc.selectedColor();
       if (newColor.isValid())
      {
      //  setZeminColor(newColor);
        myZeminColor = QColor(newColor.red(),newColor.green(),newColor.blue(),myPenAlpha);
        palette->setColor(QPalette::Button, myZeminColor);
        zeminCustomColorButton->setPalette(*palette);
        zeminCustomColorButton->update();
guzelYazi=false;
gridLines = new GridLines (this->width(), this->height(),myGridSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, QColor(128,128,128,255));
QSize screenSize = qApp->screens()[0]->size();

QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
//scene->setBackgroundBrush(bkgnd);
this->setAttribute(Qt::WA_TranslucentBackground, false);
this->setAttribute(Qt::WA_NoSystemBackground, false);
//this->setAttribute(Qt::WA_NoBackground,true);
this->repaint();
QPalette palet;
palet.setBrush(QPalette::Background, bkgnd);
this->setPalette(palet);
    }

}
void MainWindow::zeminCustomColorInitButtonClick(){
         guzelYazi=false;
       gridLines = new GridLines (this->width(), this->height(),myPenSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, QColor(128,128,128,255));
       QSize screenSize = qApp->screens()[0]->size();
       QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());

        this->setAttribute(Qt::WA_TranslucentBackground, false);
        this->setAttribute(Qt::WA_NoSystemBackground, false);

        this->repaint();
        QPalette palet;
        palet.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palet);


}
void MainWindow::zeminGuzelYaziButtonClick(){
     gridDikey=false;guzelYazi=true;
    gridLines = new GridLines (this->width(), this->height(),myGridSize*10,gridYatay,gridDikey,guzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();

        QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
                                        //scene->setBackgroundBrush(bkgnd);

                                        this->setAttribute(Qt::WA_TranslucentBackground, false);
                                        this->setAttribute(Qt::WA_NoSystemBackground, false);
                                        //this->setAttribute(Qt::WA_NoBackground,true);
                                        this->repaint();
                                        QPalette palet;
                                        palet.setBrush(QPalette::Background, bkgnd);
                                        this->setPalette(palet);
                                           scene->setBackgroundBrush(QColor(0,0,0,0));
}
void MainWindow::zeminMuzikButtonClick(){
    DiagramItem *ditem=new DiagramItem();
    mySekilType=DiagramItem::DiagramType::Muzik;
    QPixmap pim(zeminImage(ditem->sekilStore(mySekilType,QRectF(QPointF(0,0),QPointF(this->width(),this->height()))),this->width(),this->height(),myGridColor,2));
    scene->setBackgroundBrush(pim);
    gridOnOffButtonClick();
}
void MainWindow::ileriSayfaButtonClick(){
  //  qDebug()<<"ileri sayfa";
   if(sceneSayfaActiveNumber<sceneSayfaNumber)sceneSayfaActiveNumber++;
   scene=sceneSayfa[sceneSayfaActiveNumber];
   view->setScene(scene);
   // kalemButtonClick();
    Scene::Mode tempMode=currentScreenMode;
 //scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
     scene->setMode(tempMode,mySekilType);

    scene->setSekilZeminColor(mySekilZeminColor);
    //sayfaLabel->setText("Sayfa\n( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");
    //pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");

    //qDebug()<<"--sayfa No="<<sceneSayfaNumber<<"Aktif Sayfa="<<sceneSayfaActiveNumber;
ileriGeriSayfa();
}
void MainWindow::geriSayfaButtonClick(){
  // qDebug()<<"geri sayfa";
    if(sceneSayfaActiveNumber>0)sceneSayfaActiveNumber--;
    scene=sceneSayfa[sceneSayfaActiveNumber];
    view->setScene(scene);
     //kalemButtonClick();
     Scene::Mode tempMode=currentScreenMode;
     //scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
         scene->setMode(tempMode,mySekilType);

     scene->setSekilZeminColor(mySekilZeminColor);
     //sayfaLabel->setText("Sayfa\n( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");
    // pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");

     // qDebug()<<"--sayfa No="<<sceneSayfaNumber<<"Aktif Sayfa="<<sceneSayfaActiveNumber;
ileriGeriSayfa();
}
void MainWindow::ekleSayfaButtonClick(){
   // qDebug()<<"ekle sayfa";
    sceneSayfaNumber++;
    sceneSayfaActiveNumber=sceneSayfaNumber;
    _scene = new Scene(this);
    sceneSayfa.append(_scene);
    scene=_scene;
    view->setScene(scene);


    scene->setSekilZeminColor(mySekilZeminColor);
   // pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");

    ileriGeriSayfa();

      kalemButtonClick();
    //  Scene::Mode tempMode=currentScreenMode;
     // scene->setMode(tempMode,mySekilType);
      //scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);

}
void MainWindow::silSayfaButtonClick(){
    //qDebug()<<"sil sayfa";
    if(sceneSayfaNumber>0)sceneSayfaNumber--;

    if(sceneSayfaActiveNumber>0){
    sceneSayfa.removeAt(sceneSayfaActiveNumber);
    sceneSayfaActiveNumber--;
    scene=sceneSayfa[sceneSayfaActiveNumber];
    view->setScene(scene);
    }
    else if(sceneSayfaActiveNumber==0&&sceneSayfaNumber>0){
    sceneSayfa.removeAt(sceneSayfaActiveNumber);
   // sceneSayfaActiveNumber--;
    scene=sceneSayfa[sceneSayfaActiveNumber];
    view->setScene(scene);

    }
 //   kalemButtonClick();
    Scene::Mode tempMode=currentScreenMode;
    //scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
        scene->setMode(tempMode,mySekilType);


    scene->setSekilZeminColor(mySekilZeminColor);
    //sayfaLabel->setText("Sayfa\n( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");
  //  pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");

    //qDebug()<<"--sayfa No="<<sceneSayfaNumber<<"Aktif Sayfa="<<sceneSayfaActiveNumber;
ileriGeriSayfa();
}
void MainWindow::secButtonClick(){
    scene->setMode(Scene::Mode::SelectObject, DiagramItem::DiagramType::NoType);
    iconButton();
    buttonColorClear();
      currentScreenMode=Scene::Mode::SelectObject;
   // secButton->setIcon(QIcon(":icons/selectpointer.png"));
    palette->setColor(QPalette::Button, QColor(212,0,0,255));
    secButton->setPalette(*palette);
    secButton->setAutoFillBackground(true);
currentScreenModeSlot();
}
void MainWindow::tasiButtonClick(){
    tasi=true;  /* scene->setMode(Scene::Mode::MoveMode, DiagramItem::DiagramType::NoMode);*/
    iconButton();
    buttonColorClear();
    palette->setColor(QPalette::Button, QColor(212,0,0,255));
    tasiButton->setPalette(*palette);
    tasiButton->setAutoFillBackground(true);

}
void MainWindow::gizleGosterButtonClick(){
  /*  if(switched)
       {*/
    buttonColorClear();

            if(gizleGoster)
               {
                gizleGoster=false;
                gizleGosterButton->setIcon(QIcon(":icons/goster.png"));
                  /* palette->setColor(QPalette::Button, QColor(212,0,0,255));
                   gizleGosterButton->setPalette(*palette);
                   gizleGosterButton->setAutoFillBackground(true);
                   */
/*
                   tasiButton->hide();
                   colorButton->hide();
                   clockButton->hide();
                   secButton->hide();
                   ekranButton->hide();
                   kalemKapatButton->hide();
                   /**************************************/
                  // openButton->hide();
                   saveButton->hide();
                   yazdirButton->hide();
                   savePdfButton->hide();
                   loadPdfButton->hide();
                   addShapeButton->hide();
                   ayarButton->hide();
                   /*******************************************/
                   //view->hide();
                   //sayfaLabel->hide();
                  // qDebug()<<"gizlendi";
                   if (screenDesktop==false)
                   {
                     //  qDebug()<<"ekran seçili gizleme";

                        QSize screenSize = qApp->screens()[0]->size();
                       this->setGeometry(QRect(screenSize.width()-kutuWidth-15,kutuHeight+kutuTop-boy-boy,kutuWidth,boy*0.8));
                        buyukKutu->setGeometry(QRect(0,0,kutuWidth,boy*0.8));
                   }
                   else
                   {
//                       qDebug()<<"e-tahta seçili gizleme";
                       QSize screenSize = qApp->screens()[0]->size();
                       buyukKutu->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight-boy*0.75*6));
                   }

                  // hideButton();
             }
               else
               {
               // view->hide();
                   gizleGoster=true;
                   gizleGosterButton->setIcon(QIcon(":icons/gizle.png"));


                   tasiButton->show();
                   kalemRenkButton->show();
                   clockButton->show();
                  // penSizeSelector->show();
                   secButton->show();

                   ekranButton->show();

                   kalemKapatButton->show();

                   showPenButton();
                   showZeminButton();

                   showPcButton();
                    //sayfaLabel->show();
                     if (screenDesktop==false)
                   {
                       //qDebug()<<"ekran seçili gosterme";
                       QSize screenSize = qApp->screens()[0]->size();
                      this->setGeometry(QRect(screenSize.width()-kutuWidth-15,kutuTop,kutuWidth,kutuHeight));

                       buyukKutu->setGeometry(QRect(0,0,kutuWidth,kutuHeight));
                       ekranButton->setIcon(QIcon(":icons/screenpen.png"));
                    /*   palette->setColor(QPalette::Button, QColor(212,0,0,255));
                       ekranButton->setPalette(*palette);
                       ekranButton->setAutoFillBackground(true);
*/
                     }
                     else
                     {
                        // qDebug()<<"e-tahta seçili gosterme";
                         buyukKutu->setGeometry(QRect(kutuLeft,kutuTop,kutuWidth,kutuHeight));

                     }
                     //kalemButtonClick();
                  // Scene::Mode tempMode=currentScreenMode;
                   //scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
                   scene->setMode(currentScreenMode,mySekilType);


               }
currentScreenModeSlot();
}
void MainWindow::klavyeButtonClick(){
    QFile data(QDir::homePath()+"/.config/eta/virtualkeyboard/config.ini");
        data.open(QIODevice::Text | QIODevice::ReadOnly);
        QString dataText = data.readAll();

        QRegularExpression re("AutoShow=true");
        QString replacementText("AutoShow=false");

        dataText.replace(re, replacementText);

        QFile newData(QDir::homePath()+"/.config/eta/virtualkeyboard/config.ini");
        if(newData.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream out(&newData);
            out << dataText;
        }
        newData.close();
  /******************************************************/
  // system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggle");
 system("killall eta-keyboard");
  system("sleep 1");
  //system("eta-keyboard show");

// komut.append("sed -i 's/false/true/' ").append(stdout).append("/.config/eta/virtualkeyboard/config.ini");
// qDebug()<<komut;
 // arg << "-c" <<komut;
 //p1.start("/bin/bash",arg);
 //p1.waitForFinished(-1); // will wait forever until finished
  //system("sleep 1");


  system("nohup eta-keyboard show &\n");
  system("sleep 1");
  //p1.execute("eta-keyboard show");
 //
  // system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggleAutoShow");
   //system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggleAutoShow");
  // sleep(5);
  // system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.showFromBottom");
   //system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggle");
/*****************************************************************************/
  QFile data1(QDir::homePath()+"/.config/eta/virtualkeyboard/config.ini");
      data1.open(QIODevice::Text | QIODevice::ReadOnly);
      QString dataText1 = data1.readAll();

      QRegularExpression re1("AutoShow=false");
      QString replacementText1("AutoShow=true");

      dataText1.replace(re1, replacementText1);

      QFile newData1(QDir::homePath()+"/.config/eta/virtualkeyboard/config.ini");
      if(newData1.open(QFile::WriteOnly | QFile::Truncate)) {
          QTextStream out(&newData1);
          out << dataText1;
      }
      newData1.close();
  /*******************************************************************/


}
void MainWindow::infoButtonClick(){
    QMessageBox msgBox;
                   msgBox.setText("Bu uygulama etkileşimli tahtalarda kullanılmak üzere yazılmıştır."
                                  "\n"
                                  "\nYapılabilecek Eylemler:"
                                  "\n\t* Çeşitli Kalem(Normal, Fosforlu, Akıllı)"
                                  "\n\t* Tahta Rengi (Şeffaf, Beyaz, Siyah,Özel Renk)"
                                  "\n\t* Tahta Desenleri(Yatay/Dikey Çizgi, Müzik,GüzelYazi)"
                                  "\n\t* Otomatik Silgi Seçimi(Kalem Kalınlığına Uygun)"
                                  "\n\t* Ekranda Taşıma Özelliği"
                                  "\n\t* Tam Ekran Modunda Çalışmalarda Üstte Konumlanma"
                                  "\n\t* Dışarıdan Arkaplan Resim Yükleme Özelliği"
                                  "\n\t* Ekran Görüntüsünü Kaydetme Özelliği"
                                  "\n\t* Geometrik Şekil Seçme,Taşıma,Boyutlandırma Özelliği"
                                  "\n\t* Farklı Sanal Masaüstünde Çalışma Özelliği"
                                  "\n\t* Geri Alma Özelliği"
                                  "\n\t* İleri Alma Özelliği"
                                  "\n\t* Ekranın Her Alanına Yazma Özelliği"
                                  "\n\t* Pdf Dosyaları Yükleme ve Çalışma Özelliği"
                                  "\n\t* Yapılan Çalışmaları PDF Olarak Kaydetme Özelliği"
                                  "\n\t* Nesne Olarak Resim Ekleme Özelliği"
                                  "\n\t* Yazdırma Özelliği"
                                  "\n\t* Ekranın Bölgesini (Kesme,Taşıma,Büyültme) Özelliği"
                                  "\n\t* Kullanıcı Ayarlarını Kaydetme ve Açma Özelliği"
                                  "\n\t* Saat Gösterme-Gizleme Özelliği"
                                  "\n\t* Sınavlar için Sayaç Özelliği"
                                  "\n"
                                  "\n\t         Bayram KARAHAN"
                                  "\n\tBilişim Teknolojileri Öğretmeni");
                   msgBox.setWindowTitle("E-Tahta 5.0");
                   msgBox.setInformativeText("İstek ve önerileriniz için;"
                                             "\nE-Posta: bayramk@gmail.com"
                                             "\nwww.bayramkarahan.blogspot.com"
                                             "\n");
                                            // "\nÖneri ve Görüşleriyle Projeye Katkı Sağlayanlar");

                   msgBox.setStandardButtons(QMessageBox::Ok);
                   Qt::WindowFlags flags = 0;
                   flags |= Qt::Window;
                   flags |= Qt::X11BypassWindowManagerHint;
                   flags |= Qt::CustomizeWindowHint;
                   this->setWindowFlags(flags);

                    flags = 0;
                   flags |= Qt::Window;

                    //  QColorDialog abc;
                   msgBox.setWindowFlags(flags);



                   //msgBox.setDefaultButton(QMessageBox::Save);
                   msgBox.exec();
                //   kalemEgitim();
                   flags |= Qt::Window;
                   flags |= Qt::X11BypassWindowManagerHint;
                   flags |= Qt::WindowStaysOnTopHint;
               this->setWindowFlags(flags);
               show();


}
void MainWindow::saveButtonClick(){
            QStringList arguments,arg;
            arguments << "-c" << "echo $HOME";
            QProcess process,dosyasayisi;
            process.start("/bin/bash",arguments);
            process.waitForFinished(-1); // will wait forever until finished
            QString stdout = process.readAllStandardOutput();
            stdout.chop(1);
           // qDebug()<<"yol "<<stdout;
            QString yol=stdout;
            yol="ls "+yol;
            /***********************************************/
            yol.append(QString("/Masaüstü/screenshot*|wc -l"));
                 // qDebug()<<yol;
            arg << "-c" << yol;
            dosyasayisi.start("/bin/bash",arg);
            dosyasayisi.waitForFinished(-1); // will wait forever until finished
            QString filecount = dosyasayisi.readAllStandardOutput();
            filecount.chop(1);
            int filenumber=filecount.toInt();
         // qDebug()<<"ls "<<stdout<<"/Masaüstü/screenshot*|wc -l";
            // qDebug()<<"dosya sayısı: "<<filenumber;
            /***************************************/
    /*******************scene fotosunu çekiyor fakat transparan********************/
         /*   QDesktopWidget widget;
            mainScreenSize = widget.availableGeometry(widget.primaryScreen());
            //  setGeometry(mainScreenSize);
            QImage img(mainScreenSize.width(),mainScreenSize.height(),QImage::Format_ARGB32_Premultiplied);
            QPainter p(&img);
            render(&p);
            p.end();

            img.save(stdout);
            */

   /*******************scene fotosunu çekiyor fakat none transparan********************/
    /* QPixmap pixmap(mainScreenSize.width(),mainScreenSize.height());
                    QPainter painter(&pixmap);
                    painter.setRenderHint(QPainter::Antialiasing);
                    scene->render(&painter); //scene.render

                    painter.setRenderHint(QPainter::Antialiasing, false);
                    painter.end();
                    pixmap.save("/home/by/Masaüstü/scene.png");*/
        // qDebug() <<"zamanlama";
        //  qDebug()<<stdout;


  /*******************scene fotosunu çekiyor fakat transparan çoklu çekim yapar  *********/
             /*  QWidget *w = QApplication::activeWindow();
            if(w) {
              // static int count = 0;
               QPixmap p = QPixmap::grabWidget(w);
               stdout.append(QString("/Masaüstü/screenshot%1.png").arg(++filenumber));
               p.save(stdout);
               stdout.append("\nEkran Görüntüsü Masaüstünüze Kaydedildi. ");
                QMessageBox msgBox;msgBox.setText(stdout);msgBox.setStandardButtons(QMessageBox::Ok);msgBox.exec();
                 }
*/
//buyukKutu->hide();
            QSize screenSize = qApp->screens()[0]->size();

    QPixmap desk = qApp->screens().at(0)->grabWindow(
    QDesktopWidget().winId(),
    0,
    0,
    screenSize.width(),
    screenSize.height());
    stdout.append(QString("/Masaüstü/screenshot%1.png").arg(++filenumber));
    desk.save(stdout);
   // buyukKutu->show();
    stdout.append("\nEkran Görüntüsü Masaüstünüze Kaydedildi. ");
    QMessageBox msgBox;
    /*******************************************/
     Qt::WindowFlags flags = 0;
    flags |= Qt::Window;
    flags |= Qt::X11BypassWindowManagerHint;
    flags |= Qt::CustomizeWindowHint;
    this->setWindowFlags(flags);

flags = 0;
    flags |= Qt::Window;
   // flags |= Qt::X11BypassWindowManagerHint;
    //flags |= Qt::WindowStaysOnTopHint;
   // QFileDialog abc;
    msgBox.setWindowFlags(flags);
    /****************************************************/

     msgBox.setText(stdout);msgBox.setStandardButtons(QMessageBox::Ok);msgBox.exec();
     /************************************/
     flags |= Qt::Window;
     flags |= Qt::X11BypassWindowManagerHint;
     flags |= Qt::WindowStaysOnTopHint;
     this->setWindowFlags(flags);
     show();
 /***************************************/

  //  QPixmap desk = qApp->screens().at(0)->grabWindow(QDesktopWidget().winId());
   // desk.save("/home/etapadmin/Masaüstü/deneme.png");

}
void MainWindow::openButtonClick(){
qDebug()<<"zemin resim ekle";
    QStringList arguments;
    arguments << "-c" << "echo $HOME";
    QProcess process;
    process.start("/bin/bash",arguments);
    process.waitForFinished(-1); // will wait forever until finished
    QString stdout = process.readAllStandardOutput();
    stdout.chop(1);
 stdout.append(QString("/Masaüstü/"));
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

QString fileName = abc.getOpenFileName(this,
         tr("Resim Aç jpg png bmp"), stdout, tr("Image Files (*.png *.jpg *.bmp)"));
//qDebug() <<fileName;
flags |= Qt::Window;
flags |= Qt::X11BypassWindowManagerHint;
flags |= Qt::WindowStaysOnTopHint;
this->setWindowFlags(flags);
show();

    QPixmap image = QPixmap(fileName).scaled(this->width()*0.99,this->height()*0.99);

    this->setAttribute(Qt::WA_TranslucentBackground, true);
     this->setAttribute(Qt::WA_NoSystemBackground, false);
    // this->setAttribute(Qt::WA_NoBackground,true);
     this->repaint();
    QPalette palet;
     palet.setBrush(QPalette::Background, image);
    this->setPalette(palet);

}
void MainWindow::buttonColorClear(){
    palette->setColor(QPalette::Button, QColor(212,0,0,0));
    silButton->setPalette(*palette);
    silButton->setAutoFillBackground(true);
    silPopButton->setPalette(*palette);
    silPopButton->setAutoFillBackground(true);
    kalemButton->setPalette(*palette);
    kalemButton->setAutoFillBackground(true);
    kalemMenuButton->setPalette(*palette);
    kalemMenuButton->setAutoFillBackground(true);
    kalemPopButton->setPalette(*palette);
    kalemPopButton->setAutoFillBackground(true);

    fosforluKalemButton->setPalette(*palette);
    fosforluKalemButton->setAutoFillBackground(true);
    tasiButton->setPalette(*palette);
    tasiButton->setAutoFillBackground(true);
    secButton->setPalette(*palette);
    secButton->setAutoFillBackground(true);
    ekranButton->setPalette(*palette);
    ekranButton->setAutoFillBackground(true);
    gizleGosterButton->setPalette(*palette);
    gizleGosterButton->setAutoFillBackground(true);

   sekilButton->setPalette(*palette);
   sekilButton->setAutoFillBackground(true);
   sekilPopButton->setPalette(*palette);
   sekilPopButton->setAutoFillBackground(true);



}

#endif // BUTTONCLICK_H
