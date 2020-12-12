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
    //qDebug()<<"selam"<<scene->adas;
    ///scene->setBackgroundBrush(QColor(0,0,0,0));
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
    //setPenSize(0);
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
void MainWindow::sekilButtonIconSlot(){
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
}

void MainWindow::sekilButtonClick(){
    sekilButtonIconSlot();

    scene->setMode(Scene::Mode::DrawRectangle, mySekilType);
    currentScreenMode=Scene::Mode::DrawRectangle;
    scene->setSekilPenSize(mySekilPenSize);
    scene->setSekilKalemColor(mySekilKalemColor);
    scene->setSekilPenStyle(mySekilPenStyle);
    buttonColorClear();
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
        /*Qt::WindowFlags flags = 0;
        flags |= Qt::Window;
        flags |= Qt::X11BypassWindowManagerHint;
        flags |= Qt::WindowStaysOnTopHint;
        this->setWindowFlags(flags);
        this->show();
        */
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

void MainWindow::gridDisableButtonClick(){
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    scene->sceneGuzelYazi=false;
    myZeminColor=QColor(0,0,0,0);
    gridLines = new GridLines (this->width(), this->height(),myPenSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();

    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    scene->setForegroundBrush(bkgnd);
   }
void MainWindow::gridYatayButtonClick(bool toggle){
//qDebug()<<toggle;
    if(toggle)scene->sceneGridYatay=true;
    else scene->sceneGridYatay=!scene->sceneGridYatay;
    scene->sceneGuzelYazi=false;
    myZeminColor=QColor(0,0,0,0);
    gridLines = new GridLines (this->width(), this->height(),myGridSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    scene->setForegroundBrush(bkgnd);
}
void MainWindow::gridDikeyButtonClick(bool toggle){

    if(toggle) scene->sceneGridDikey=true;
    else scene->sceneGridDikey=!scene->sceneGridDikey;
    scene->sceneGuzelYazi=false;

    myZeminColor=QColor(0,0,0,0);
    gridLines = new GridLines (this->width(), this->height(),myGridSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();

    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    scene->setForegroundBrush(bkgnd);

}

void MainWindow::zeminSeffafButtonClick(){
    myZeminType=0;
    myZeminColor=QColor(0,0,0,0);
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    scene->sceneGuzelYazi=false;
    ///qDebug()<<myGridSize<<gridYatay<<gridDikey<<guzelYazi<<myZeminColor<< myGridColor;
    gridLines = new GridLines (this->width(), this->height(),myGridSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    //bkgnd.show();
    scene->setBackgroundBrush(bkgnd);

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_NoSystemBackground, false);
    //this->setAttribute(Qt::WA_NoBackground,true);
    this->repaint();
    QPalette palet;
    palet.setBrush(QPalette::Background, QColor(0,0,0,1));
    this->setPalette(palet);  //setZeminColor(myZeminColor);


}
void MainWindow::zeminSiyahButtonClick(){
    myZeminType=1;
    myZeminColor=QColor(0,0,0,255);
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    scene->sceneGuzelYazi=false;

    gridLines = new GridLines (this->width(), this->height(),myGridSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();

    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    scene->setBackgroundBrush(bkgnd);


}
void MainWindow::zeminBeyazButtonClick(){
    myZeminType=2;

    myZeminColor=QColor(255,255,255,255);
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    scene->sceneGuzelYazi=false;

    gridLines = new GridLines (this->width(), this->height(),myGridSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();

    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    scene->setBackgroundBrush(bkgnd);

}
void MainWindow::zeminCustomColorButtonClick(){

    myZeminType=3;
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    scene->sceneGuzelYazi=false;
    // qDebug()<<"selam";
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

        gridLines = new GridLines (this->width(), this->height(),myGridSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
        QSize screenSize = qApp->screens()[0]->size();

        QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
        scene->setBackgroundBrush(bkgnd);

    }

}
void MainWindow::zeminCustomColorInitButtonClick(){
    ///   qDebug()<<"zeminCustomColorInitButtonClick çalıştı";
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    scene->sceneGuzelYazi=false;

    gridLines = new GridLines (this->width(), this->height(),myPenSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();
    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    scene->setBackgroundBrush(bkgnd);
    /* this->setAttribute(Qt::WA_TranslucentBackground, false);
        this->setAttribute(Qt::WA_NoSystemBackground, false);

        this->repaint();
        QPalette palet;
        palet.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palet);

*/
}
void MainWindow::zeminGuzelYaziButtonClick(bool toggle){
    // qDebug()<<"zeminGuzelYaziButtonClick";
   // gridDisableButtonClick();
    //gridDikey=false;
    scene->sceneGridYatay=false;
    scene->sceneGridDikey=false;
    if(toggle) scene->sceneGuzelYazi=true;
    else scene->sceneGuzelYazi=!scene->sceneGuzelYazi;

    myZeminColor=QColor(0,0,0,0);
    gridLines = new GridLines (this->width(), this->height(),myGridSize*10,scene->sceneGridYatay,scene->sceneGridDikey,scene->sceneGuzelYazi,myZeminColor, myGridColor);
    QSize screenSize = qApp->screens()[0]->size();

    QPixmap bkgnd=gridLines->PixItem(gridLines,screenSize.width(),screenSize.height());
    scene->setForegroundBrush(bkgnd);

}
void MainWindow::zeminMuzikButtonClick(){
    myZeminColor=QColor(0,0,0,0);
    DiagramItem *ditem=new DiagramItem();
    mySekilType=DiagramItem::DiagramType::Muzik;
    QPixmap pim(zeminImage(ditem->sekilStore(mySekilType,QRectF(QPointF(0,0),QPointF(this->width(),this->height()))),this->width(),this->height(),myGridColor,2));
    scene->setForegroundBrush(pim);
    //gridOnOffButtonClick();
}

void MainWindow::ileriSayfaButtonClick(){
    //qDebug()<<"ileri sayfa";
    if(sceneSayfaActiveNumber<sceneSayfaNumber)sceneSayfaActiveNumber++;
    scene=sceneSayfa[sceneSayfaActiveNumber];
    view->setScene(scene);
    // kalemButtonClick();
    ///  Scene::Mode tempMode=currentScreenMode;
    //scene->setMode(Scene::Mode::GeriAlMode, DiagramItem::DiagramType::NoType);
    ///  scene->setMode(tempMode,mySekilType);
    iconButton();
    buttonColorClear();
    setPenColor(scene->myPenColor);             ///çok önemli işlem
    myPenSize=(scene->myPenSize);               ///çook önemli
    setPenStyle(scene->myPenStyle);             ///çook önemli
    setPenAlpha(scene->myPenAlpha);             ///çook önemli
    mySekilType=scene->mySekilType;           ///çok önemli
    sekilButtonIconSlot();
    mySekilZeminColor=scene->mySekilZeminColor; ///çok önemli
    mySekilPenSize=scene->mySekilPenSize;       ///çok önemli
    mySekilKalemColor=scene->mySekilKalemColor; ///çok önemli
    setSekilPenStyle(scene->mySekilPenStyle);   ///çok önemli
    myEraseSize=scene->myEraseSize;             ///çok önemli
    currentScreenMode=scene->sceneMode;         ///çok önemli

    currentScreenModeSlot();

    //sayfaLabel->setText("Sayfa\n( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");
    //pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");

    //qDebug()<<"--sayfa No="<<sceneSayfaNumber<<"Aktif Sayfa="<<sceneSayfaActiveNumber;
    ileriGeriSayfa();
}
void MainWindow::geriSayfaButtonClick(){
    ///qDebug()<<"geri sayfa";
    if(sceneSayfaActiveNumber>0)sceneSayfaActiveNumber--;
    scene=sceneSayfa[sceneSayfaActiveNumber];
    view->setScene(scene);
    iconButton();
    buttonColorClear();
    setPenColor(scene->myPenColor);             ///çok önemli işlem
    myPenSize=(scene->myPenSize);               ///çook önemli
    setPenStyle(scene->myPenStyle);             ///çook önemli
    setPenAlpha(scene->myPenAlpha);             ///çook önemli
    mySekilType=scene->mySekilType;           ///çok önemli
    sekilButtonIconSlot();
    mySekilZeminColor=scene->mySekilZeminColor; ///çok önemli
    mySekilPenSize=scene->mySekilPenSize;       ///çok önemli
    mySekilKalemColor=scene->mySekilKalemColor; ///çok önemli
    setSekilPenStyle(scene->mySekilPenStyle);   ///çok önemli
    myEraseSize=scene->myEraseSize;             ///çok önemli
    currentScreenMode=scene->sceneMode;         ///çok önemli

    currentScreenModeSlot();
    //sayfaLabel->setText("Sayfa\n( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");
    // pageNumberPopLabel->setText("Sayfa( "+QString::number(sceneSayfaNumber+1)+" / "+QString::number(sceneSayfaActiveNumber+1)+" )");

    // qDebug()<<"--sayfa No="<<sceneSayfaNumber<<"Aktif Sayfa="<<sceneSayfaActiveNumber;
    ileriGeriSayfa();
}
void MainWindow::ekleSayfaButtonClick(){
   /// qDebug()<<"ekle sayfa";
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
   /// qDebug()<<"buton ekleniyor";
    auto _screenbtn = new QToolButton(pageListwg);
    // _screenbtn->resize(75,75);
    _screenbtn->setFixedSize(QSize(boy,boy));

    _screenbtn->setIconSize(QSize(boy*0.7,boy*0.7));
    _screenbtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    _screenbtn->setText(QString::number(sceneSayfaNumber));
    _screenbtn->setToolTip(QString::number(sceneSayfaNumber));
    screenlayout->addWidget(_screenbtn);
    pageList.append(_screenbtn);
    connect(_screenbtn, &QPushButton::clicked, [=]() {
        /// qDebug()<<"tooltip:"<<_screenbtn->toolTip();
         sceneSayfaActiveNumber=_screenbtn->toolTip().toInt();
         scene=sceneSayfa[sceneSayfaActiveNumber];
         view->setScene(scene);
         iconButton();
         buttonColorClear();
         setPenColor(scene->myPenColor);             ///çok önemli işlem
         myPenSize=(scene->myPenSize);               ///çook önemli
         setPenStyle(scene->myPenStyle);             ///çook önemli
         setPenAlpha(scene->myPenAlpha);             ///çook önemli
         mySekilType=scene->mySekilType;           ///çok önemli
         sekilButtonIconSlot();
         mySekilZeminColor=scene->mySekilZeminColor; ///çok önemli
         mySekilPenSize=scene->mySekilPenSize;       ///çok önemli
         mySekilKalemColor=scene->mySekilKalemColor; ///çok önemli
         setSekilPenStyle(scene->mySekilPenStyle);   ///çok önemli
         myEraseSize=scene->myEraseSize;             ///çok önemli
         currentScreenMode=scene->sceneMode;         ///çok önemli

         currentScreenModeSlot();
        ileriGeriSayfa();
       /// qDebug()<<"sayı:"<<pageList.length();
        /**********************************************/
        for(int i=0;i<pageList.length();i++)
        {
            palette->setColor(QPalette::Button, QColor(225,225,225,255));
            pageList[i]->setPalette(*palette);
            pageList[i]->setAutoFillBackground(true);

        }
        palette->setColor(QPalette::Button, QColor(255,0,0,100));
        _screenbtn->setPalette(*palette);
        _screenbtn->setAutoFillBackground(true);

        /************************************************/
    });

    /*****************Sayfa Eklenince mutlaka Çalışmalı*****************************/
    for(int i=0;i<pageList.length();i++)
    {
        palette->setColor(QPalette::Button, QColor(225,225,225,255));
        pageList[i]->setPalette(*palette);
        pageList[i]->setAutoFillBackground(true);

    }
    palette->setColor(QPalette::Button, QColor(255,0,0,100));
    _screenbtn->setPalette(*palette);
    _screenbtn->setAutoFillBackground(true);
    scene->sceneGridYatay=false;///?isteğe bağlı
    scene->sceneGridDikey=false;///?isteğe bağlı
    scene->sceneGuzelYazi=false;///?isteğe bağlı

    /************************************************/


}
void MainWindow::silSayfaButtonClick(){
 ///qDebug()<<"sil sayfa-0"<<sceneSayfaActiveNumber;

    //pageList.append(_screenbtn);

    ///screenlayout->update();
   /// if(sceneSayfaNumber>0)sceneSayfaNumber--;

    if(sceneSayfaActiveNumber>0){
        ///qDebug()<<"sil sayfa-1"<<sceneSayfaActiveNumber;
        delete pageList[sceneSayfaActiveNumber];
        pageList.removeAt(sceneSayfaActiveNumber);

        sceneSayfa.removeAt(sceneSayfaActiveNumber);
        sceneSayfaActiveNumber--;
        scene=sceneSayfa[sceneSayfaActiveNumber];
        view->setScene(scene);
        sceneSayfaNumber--;
    }
    else if(sceneSayfaActiveNumber==0){
        if(sceneSayfaNumber>0)
        {
          ///  qDebug()<<"sil sayfa-2"<<sceneSayfaActiveNumber;
            delete pageList[sceneSayfaActiveNumber];
            pageList.removeAt(sceneSayfaActiveNumber);

            sceneSayfa.removeAt(sceneSayfaActiveNumber);
            // sceneSayfaActiveNumber--;
            scene=sceneSayfa[sceneSayfaActiveNumber];
            view->setScene(scene);
            sceneSayfaNumber--;
        }
    }
    /***********************************************/
    for(int i=0;i<pageList.length();i++)
    {
        pageList[i]->setToolTip(QString::number(i));
        pageList[i]->setText(QString::number(i));
        palette->setColor(QPalette::Button, QColor(225,225,225,255));
        pageList[i]->setPalette(*palette);
        pageList[i]->setAutoFillBackground(true);


    }
    palette->setColor(QPalette::Button, QColor(255,0,0,100));
    pageList[sceneSayfaActiveNumber]->setPalette(*palette);
    pageList[sceneSayfaActiveNumber]->setAutoFillBackground(true);

    /**********************************************/
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
     system("killall eta-keyboard");
    system("sleep 1");
       system("nohup eta-keyboard show &\n");
    system("sleep 1");
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
                   "/*****************************************************************************"
                   "\n   Copyright (C) 2020 by Bayram KARAHAN                                     "
                   "\n   <bayramk@gmail.com>  <www.bayramkarahan.blogspot.com>                                                    "
                    "\n                                                                           "
                    "\n   This program is free software; you can redistribute it and/or modify    "
                    "\n   it under the terms of the GNU General Public License as published by    "
                    "\n   the Free Software Foundation; either version 3 of the License, or       "
                    "\n   (at your option) any later version.                                     "
                    "\n                                                                           "
                    "\n   This program is distributed in the hope that it will be useful,         "
                    "\n   but WITHOUT ANY WARRANTY; without even the implied warranty of          "
                    "\n   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           "
                    "\n   GNU General Public License for more details.                            "
                    "\n                                                                           "
                    "\n   You should have received a copy of the GNU General Public License       "
                    "\n   along with this program; if not, write to the                          "
                    "\n   Free Software Foundation, Inc.,                                         "
                    "\n   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .          "
                    "\n****************************************************************************"

                   );
    msgBox.setWindowTitle("E-Tahta 6.0");


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
    QSize sSize = qApp->screens()[0]->size();
    QGraphicsTextItem *text = new QGraphicsTextItem(".");
    scene->addItem(text);
    text->setPos(0, 0);
    QGraphicsTextItem *text1 = new QGraphicsTextItem(".");
    scene->addItem(text1);
    text1->setPos(sSize.width()-2, sSize.height()-2);

    QPixmap pixmap(sSize.width(),sSize.height());
    pixmap.fill(Qt::transparent);     // Start all pixels transparent
    ///pixmap.fill(Qt::white);     // Start all pixels white
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    scene->render(&painter); //scene.render
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.end();
    if(QSysInfo::kernelType()=="linux"){
        QDir directory(QDir::homePath()+"/Masaüstü");
        QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
        int deger=0;
        foreach(QString filename, images) {
            filename.chop(4);
            QString dosya=filename.right(filename.size()-10);
           /// qDebug() <<filename<<dosya;
            if(deger<dosya.toInt()) deger=dosya.toInt();
        }
        deger++;
        pixmap.save(QDir::homePath()+"/Masaüstü/screenshot"+QString::number(deger)+".png");
    }
     else{//windows işletim sistemi için
        QDir directory(QDir::homePath()+"/desktop");
        QStringList images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);
        int deger=0;
        foreach(QString filename, images) {
            filename.chop(4);
            QString dosya=filename.right(filename.size()-10);
          ///  qDebug() <<filename<<dosya;
            if(deger<dosya.toInt()) deger=dosya.toInt();
        }
        deger++;
        pixmap.save(QDir::homePath()+"/desktop/screenshot"+QString::number(deger)+".png");

        }

    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    flags |= Qt::X11BypassWindowManagerHint;

    QMessageBox messageBox(this);
    messageBox.setWindowFlags(flags);
    messageBox.setText("Bilgi\t\t\t");
    messageBox.setInformativeText("Ekran Görüntüsü Masaüstünüze Kaydedildi!");
    QAbstractButton *evetButton =messageBox.addButton(tr("Tamam"), QMessageBox::ActionRole);
   // QAbstractButton *hayirButton =messageBox.addButton(tr("Hayır"), QMessageBox::ActionRole);
    messageBox.setIcon(QMessageBox::Information);
            messageBox.exec();


}
void MainWindow::openButtonClick(){
 ///   qDebug() <<"resim aç";
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
        QPixmap image = QPixmap(fileName).scaled(this->width()*0.99,this->height()*0.99);
        scene->setBackgroundBrush(image);
        }

    }
    else
    {//windows
        QString fileName = abc.getOpenFileName(this,
        tr("Resim Aç jpg png bmp"), QDir::homePath()+"/desktop", tr("Image Files (*.png *.jpg *.bmp)"));
        if(fileName!="")
        {
        QPixmap image = QPixmap(fileName).scaled(this->width()*0.99,this->height()*0.99);
        scene->setBackgroundBrush(image);
        }

    }
    flags |= Qt::Window;
    flags |= Qt::X11BypassWindowManagerHint;
    flags |= Qt::WindowStaysOnTopHint;
    this->setWindowFlags(flags);
    show();
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
