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

#ifndef KALEMLAYOUT_H
#define KALEMLAYOUT_H
//#include<mainwindow.h>
#include<diagramitem.h>

void MainWindow::kalemLayout()
{

auto layout = new QGridLayout();
layout->setContentsMargins(1,0, 0,0);
layout->setSpacing(1);
float c=1;
float cc=0.7;
float b=0.7;
clockButton=new QPushButton(this);
clockButton->setFixedSize(en*c, boy/2);
clockButton->setFlat(true);
clockButton->setStyleSheet("QPushButton{color: rgb(62, 140, 183);}");
 zamanlama();
connect(clockButton, &QPushButton::clicked, [=]() {

    clock=!clock;
    zamanlama();
});

layout->addWidget(clockButton, 0, 0,1,2);
//colorButton->setFixedSize(en*c, boy*0.5);
//colorButton->setIconSize(QSize(en*cc,boy*0.5));
//layout->addWidget(colorButton, 1, 0,1,2);

ekranButton->setFixedSize(en*c, boy*b);
ekranButton->setIconSize(QSize(en*cc,boy*b));

layout->addWidget(ekranButton, 3, 0,1,2);
secButton->setFixedSize(en*c, boy*b);
secButton->setIconSize(QSize(en*cc,boy*b));

layout->addWidget(secButton, 4, 0,1,2);
/***************************************************************/


copyButton = new QPushButton(this);
copyButton->setIcon(QIcon(":icons/copy.png"));
copyButton->setFixedSize(en*c, boy*b);
copyButton->setIconSize(QSize(en*cc,boy*b));
copyButton->setFlat(true);
//copyButton->hide();
//copyButton->move(this->width()/2-en,this->height()-boy-10);
connect(copyButton, &QPushButton::clicked, [=]()
{ ///qDebug()<<"kopy kalem çalıştı"<<screenDesktop;
//if (!screenDesktop)kalemButtonClick();

    scene->setMode(Scene::Mode::CopyMode, DiagramItem::DiagramType::Copy);
    currentScreenMode=Scene::Mode::CopyMode;
    iconButton();
    buttonColorClear();
    scene->setSekilTanimlamaStatus(false);
     palette->setColor(QPalette::Button, QColor(212,0,0,255));
     secButton->setPalette(*palette);
     secButton->setAutoFillBackground(true);
             QSize screenSize = qApp->screens()[0]->size();
     QPixmap desk = qApp->screens().at(0)->grabWindow(
     QDesktopWidget().winId(),
    0,
    0,
     screenSize.width(),
     screenSize.height());
     scene->setImage(desk);
     timerCopy->start(1000);
     /*****************************/
     FileCrud *fc=new FileCrud();
     fc->dosya="E-Tahta.copy.ini";
     if(fc->fileexists()) fc->fileremove();
     fc->fileWrite("copy=0");
currentScreenModeSlot();
     /**********************************/
});
layout->addWidget(copyButton, 5, 0,1,2);
/***************************************************************/
temizleButton->setFixedSize(en*c, boy*b);
temizleButton->setIconSize(QSize(en*cc,boy*b));

layout->addWidget(temizleButton, 7,0,1,2);
//layout->addWidget(geriAlButton, 7, 0,1,1);
siyahButton->setFixedSize(en*c, boy*0.5);
//siyahButton->setIconSize(QSize(en*0.75,boy*0.5));

layout->addWidget(siyahButton, 8, 0,1,2);
kirmiziButton->setFixedSize(en*c, boy*0.5);
//kirmiziButton->setIconSize(QSize(en*0.75,boy*0.5));

layout->addWidget(kirmiziButton, 9, 0,1,2);
//kalemRenkButton->setFixedSize(en*c, boy*0.5);
kalemRenkButton->setFixedSize(en*c, boy*b);
kalemRenkButton->setIconSize(QSize(en*c,boy*b));

//yesilButton->setIconSize(QSize(en*0.75,boy*0.5));

layout->addWidget(maviButton, 10, 0,1,2);
maviButton->setFixedSize(en*c, boy*0.5);
//maviButton->setIconSize(QSize(en*0.75,boy*0.5));

layout->addWidget(kalemRenkButton, 11, 0,1,2);
/******************************************************/

ileriAlButton->setIcon(QIcon(":icons/redo.png"));
ileriAlButton->setFixedSize(en*c/2, boy*b);
ileriAlButton->setIconSize(QSize(en*cc*0.6,boy*b));
ileriAlButton->setFlat(true);
connect(ileriAlButton, &QPushButton::clicked, [=]()
{currentScreenModeSlot();
    Scene::Mode tempMode=currentScreenMode;
 scene->setMode(Scene::Mode::IleriAlMode, DiagramItem::DiagramType::NoType);
     scene->setMode(tempMode,mySekilType);

});
/*************************************************************/
//layout->addWidget(kalemSizePopLabel, 0, 1,1,3);
geriAlButton->setFixedSize(en*c/2, boy*b);
geriAlButton->setIconSize(QSize(en*cc*0.6,boy*b));
layout->addWidget(geriAlButton,12,0,1,1);
layout->addWidget(ileriAlButton,12,1,1,1);

kalemButton->setFixedSize(en*c/2, boy*b);
kalemButton->setIconSize(QSize(en*cc*0.7,boy*b));
kalemPopButton->setFixedSize(en*c/2, boy*b);
kalemPopButton->setIconSize(QSize(en*cc*0.7,boy*b));

layout->addWidget(kalemButton, 14, 0,1,1);
layout->addWidget(kalemPopButton,14,1,1,1);
QMenu *kalemMenus=penMenu();
kalemMenus->show();kalemMenus->hide();

//kalemPopButton->setMenu(penMenu(SLOT(kalemPopButton()), DiagramItem::DiagramType::Cizgi));
connect(kalemPopButton, &QPushButton::clicked, [=]() {//en*6+en/10
    currentScreenModeSlot();
    scene->setPopMenuStatus(true);
    kalemMenus->exec(mapToGlobal(kalemPopButton->pos() + QPoint(kutuLeft-kalemMenus->width()-kutuWidth/2,kutuTop+boy/2)));
    scene->setPopMenuStatus(false);
});
  gizleGosterButton->setIcon(QIcon(":icons/gizle.png"));
silButton->setFixedSize(en*c/2, boy*b);
silButton->setIconSize(QSize(en*cc*0.7,boy*b));

silPopButton->setFixedSize(en*c/2, boy*b);
silPopButton->setIconSize(QSize(en*cc*0.7,boy*b));

layout->addWidget(silButton, 15,0,1,1);
layout->addWidget(silPopButton, 15,1,1,1);
QMenu *silMenus=eraseMenu();
silMenus->show();silMenus->hide();

//silPopButton->setMenu(eraseMenu(SLOT(silPopButton()), DiagramItem::DiagramType::Cizgi));
connect(silPopButton, &QPushButton::clicked, [=]() {
       currentScreenModeSlot();
       scene->setPopMenuStatus(true);
      silMenus->exec(mapToGlobal(silPopButton->pos() + QPoint(kutuLeft-silMenus->width()-kutuWidth/2,kutuTop+boy/2)));
      scene->setPopMenuStatus(false);

});

zeminButton->setFixedSize(en*c/2, boy*b);
zeminButton->setIconSize(QSize(en*cc*0.7,boy*b));
zeminPopButton->setFixedSize(en*c/2, boy*b);
zeminPopButton->setIconSize(QSize(en*cc*0.7,boy*b));

layout->addWidget(zeminButton, 25,0,1,1);
layout->addWidget(zeminPopButton, 25,1,1,1);
QMenu *zeminMenus=zeminMenu();
zeminMenus->show();zeminMenus->hide();
//zeminPopButton->setMenu(zeminMenu(SLOT(zeminPopButton()), DiagramItem::DiagramType::Cizgi));
connect(zeminPopButton, &QPushButton::clicked, [=]() {
    //qDebug()<<"zeminpop click";
    currentScreenModeSlot();
   scene->setPopMenuStatus(true);
    zeminMenus->exec(mapToGlobal(zeminPopButton->pos() + QPoint(kutuLeft-zeminMenus->width()-kutuWidth/2,kutuTop+boy/2)));
    scene->setPopMenuStatus(false);


});

sekilButton->setFixedSize(en*c/2, boy*b);
sekilButton->setIconSize(QSize(en*cc*0.7,boy*b));

sekilPopButton->setFixedSize(en*c/2, boy*b);
sekilPopButton->setIconSize(QSize(en*cc*0.7,boy*b));

layout->addWidget(sekilButton, 35,0,1,1);
layout->addWidget(sekilPopButton, 35,1,1,1);
QMenu *sekilMenus=sekilMenu();
sekilMenus->show();sekilMenus->hide();
//sekilPopButton->setMenu(sekilMenu(SLOT(sekilPopButton()), DiagramItem::DiagramType::Cizgi));
connect(sekilPopButton, &QPushButton::clicked, [=]() {
   // scene->setPopMenuStatus(true);
     currentScreenModeSlot();
     //qDebug()<<"sssss";
    sekilMenus->exec(mapToGlobal(sekilPopButton->pos() + QPoint(kutuLeft-sekilMenus->width()-kutuWidth/2,kutuTop+boy/2)));
    scene->setPopMenuStatus(false);

});
/**********************************/
screenClickButton = new QPushButton(this);
screenClickButton->setIcon(QIcon(":/icons/screenClick.png"));
screenClickButton->setFixedSize(en*c, boy*b);
screenClickButton->setIconSize(QSize(en*c,boy*b));
screenClickButton->setFlat(true);
connect(screenClickButton,SIGNAL(clicked()),this,SLOT(screenClickButtonClick()));

layout->addWidget(screenClickButton, 36,0,1,2);
/*connect(screenClickButton, &QPushButton::clicked, [=]() {
    screenClickDrm=!screenClickDrm;
    if(screenClickDrm)
    {
    tempcurrentScreenMode=currentScreenMode;
    scene->setMode(Scene::Mode::NoMode, DiagramItem::DiagramType::NoType);
     }else
    {
        currentScreenMode=tempcurrentScreenMode;
        scene->setMode(currentScreenMode, DiagramItem::DiagramType::NoType);

    }
     currentScreenModeSlot();
});*/
/**************************************/

addShapeButton = new QPushButton(this);
addShapeButton->setIcon(QIcon(":/icons/addimage.png"));
addShapeButton->setFixedSize(en*c, boy*b);
addShapeButton->setIconSize(QSize(en*cc,boy*b));
addShapeButton->setFlat(true);
connect(addShapeButton, &QPushButton::clicked, [=]()
{
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
});layout->addWidget(addShapeButton, 38, 0,1,2);
/***************************************************************/
/**************************************/
/*pageSaveButton = new QPushButton(this);
pageSaveButton->setIcon(QIcon(":/icons/save.png"));
*/

saveButton->setFixedSize(en*c, boy*0.8);
saveButton->setIconSize(QSize(en*cc,boy*0.8));
saveButton->setFlat(true);
layout->addWidget(saveButton, 40, 0,1,2);
/************************************************************/
//QPushButton *
yazdirButton= new QPushButton;
yazdirButton->setFixedSize(en*c, boy*0.8);
yazdirButton->setIconSize(QSize(en*cc,boy*0.7));
yazdirButton->setFlat(true);
yazdirButton->setIcon(QIcon(":icons/print.png"));

connect(yazdirButton, &QPushButton::clicked, [=]() {
        //menu->close();

       //   QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",
          //QString(), "*.pdf");
          QPrinter printer(QPrinter::HighResolution);
          printer.setPageSize(QPrinter::A4);
         // printer.setOrientation(Qt::Horizontal);
          printer.setOrientation(QPrinter::Landscape);
         // printer.setOutputFormat(QPrinter::PdfFormat);
          //printer.setOutputFileName(fileName);


        int filenumber=20;
        QSize screenSize = qApp->screens()[0]->size();

        QPixmap desk = qApp->screens().at(0)->grabWindow(
        QDesktopWidget().winId(),
        0,
        0,
        screenSize.width(),
        screenSize.height());
        //QString stdout="/home/etapadmin";

        //stdout.append(QString("/Masaüstü/screenshot%1.png").arg(++filenumber));
       // desk.save(stdout);

        QPainter p;
        p.begin(&printer);
       // p.begin();
      //  desk.scaled(printer.pageRect().width(), printer.pageRect().height(), Qt::KeepAspectRatio);
       //p.setWindow(printer.pageRect());
        p.setWindow(QRect(0, 0, desk.width(), desk.height()));
        p.drawPixmap (0, 0, desk);
       // scene->render(&p);

        p.end();
});
layout->addWidget(yazdirButton, 41,0,1,2);

loadPdfButton= new QPushButton;
loadPdfButton->setFixedSize(en*c, boy*0.8);
loadPdfButton->setIconSize(QSize(en*cc,boy*1.3));
loadPdfButton->setFlat(true);
loadPdfButton->setIcon(QIcon(":icons/loadpdf.png"));

connect(loadPdfButton, &QPushButton::clicked, [=]() {
      //  menu->close();
    /*******************************************/
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
     QString fileName;
    /****************************************************/
    if(QSysInfo::kernelType()=="linux"){
        fileName = abc.getOpenFileName(this, tr("Open PDF file"),
                                                        QDir::homePath()+"/Masaüstü",
                                                        tr("PDF file (*.pdf)"));
     }
    else
    {
       fileName = abc.getOpenFileName(this, tr("Open PDF file"),
                                                        QDir::homePath()+"/desktop",
                                                        tr("PDF file (*.pdf)"));
    }

     flags |= Qt::Window;
    flags |= Qt::X11BypassWindowManagerHint;
    flags |= Qt::WindowStaysOnTopHint;
    this->setWindowFlags(flags);
    show();

    if (fileName.isEmpty()) {
        return;
    }

    Poppler::Document *doc = Poppler::Document::load(fileName);
    doc->setRenderHint(Poppler::Document::TextAntialiasing);
    doc->setRenderHint(Poppler::Document::Antialiasing);
    doc->setRenderHint(Poppler::Document::TextHinting);
    doc->setRenderHint(Poppler::Document::TextSlightHinting);
    doc->setRenderHint(Poppler::Document::ThinLineSolid);
    doc->setRenderBackend(Poppler::Document::ArthurBackend);
   // doc->setPaperColor(Qt::transparent);

    int page = 0;
    bool son=false;
       while (page <doc->numPages()) {
           //QImage image =  QImage(doc->page(page)->pageSize().width(),doc->page(page)->pageSize().height(), QImage::Format_ARGB32);
          // qDebug()<<doc->page(page)->pageSize().width()<<doc->page(page)->pageSize().height();
           QImage image = doc->page(page)->renderToImage(91.0,91.0,-1,-1,-1,-1);
          // QImage image = doc->page(page)->renderToImage(300.0,100.0);

          view->setSceneRect(0,0,this->width(),image.height());
            scene->setBackgroundBrush(image.scaled(this->width(),image.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
            QGraphicsTextItem *text = new QGraphicsTextItem("E-Tahta");
            scene->addItem(text);
            text->setPos(0, 0);

            QGraphicsTextItem *text1 = new QGraphicsTextItem("E-Tahta");
            scene->addItem(text1);
            text1->setPos(this->width()-150, image.height()-40);

            if(son)
            {
                ekleSayfaButtonClick();
                page += 1;
               // qDebug()<<page;
            }
            son=true;

       }
       sceneSayfaActiveNumber=0;
       geriSayfaButtonClick();

});
layout->addWidget(loadPdfButton, 43, 0,1,2);

savePdfButton= new QPushButton;
savePdfButton->setFixedSize(en*c, boy*0.8);
savePdfButton->setIconSize(QSize(en,boy*0.7));
savePdfButton->setFlat(true);
savePdfButton->setIcon(QIcon(":icons/savepdf.png"));

connect(savePdfButton, &QPushButton::clicked, [=]() {
       // menu->close();
   // qDebug()<<"hhh";
    QString fileName;
    if(QSysInfo::kernelType()=="linux"){
        fileName=QDir::homePath()+"/Masaüstü/E-Tahta.pdf";
        }
    else{//windows
        fileName=QDir::homePath()+"/desktop/E-Tahta.pdf";
       }

QPdfWriter pdfWriter(fileName);
QPainter painter(&pdfWriter);
sceneSayfaActiveNumber=0;
geriSayfaButtonClick();
for (int i=0; i<=sceneSayfaNumber; i++) {
    /*************************************************/
    //scene->setForegroundBrush(zImage(this->width(),this->height(),QColor(255,255,255,250)));
   // view->setSceneRect(0,0,scene->width(),scene->height());
   if(scene->height()<this->height())
   {
    QGraphicsTextItem *text = new QGraphicsTextItem("E-Tahta");
    scene->addItem(text);
    text->setPos(0, 0);
    QGraphicsTextItem *text1 = new QGraphicsTextItem("E-Tahta");
    scene->addItem(text1);
    text1->setPos(this->width()-150, this->height()-40);
   }
    /*************************************************/
   QImage img(scene->width(),scene->height(),QImage::Format_ARGB32_Premultiplied);
   QPainter p(&img);
   p.setWindow(QRect(0, 0, scene->width(), scene->height()));
   p.eraseRect(QRect(0, 0, scene->width(), scene->height()));
   scene->render(&p);
  // p.setBrush(QBrush(Qt::white));
   p.end();
    //painter.fillRect(0, 0, scene->width(), scene->height(), Qt::green);
   // img.save("/home/by/temp.png");
 //  painter.setCompositionMode(QPainter::CompositionMode_Clear);

   painter.setWindow(QRect(0, 0, scene->width(), scene->height()));
 //  painter.eraseRect(QRect(0, 0, scene->width(), scene->height()));

   painter.drawImage(0,0,img);
  // painter.setBrush(QBrush(Qt::white));
     /*  QEventLoop loop;
       QTimer::singleShot(1000, &loop, SLOT(quit()));
       loop.exec();*/
   if(i!=sceneSayfaNumber)
   {
       pdfWriter.newPage();
       ileriSayfaButtonClick();
   }
//delete img;

}
QString st;
st.append(QDir::homePath()+"/Masaüstü/E-Tahta.pdf");
st.append("\n\nDosyası Masaüstünüze Kaydedildi. ");


 Qt::WindowFlags flags = 0;
 flags |= Qt::Dialog;
 flags |= Qt::X11BypassWindowManagerHint;

 QMessageBox messageBox(this);
 messageBox.setWindowFlags(flags);
 messageBox.setText("Bilgi\t\t\t");
 messageBox.setInformativeText(st);
 QAbstractButton *evetButton =messageBox.addButton(tr("Tamam"), QMessageBox::ActionRole);
// QAbstractButton *hayirButton =messageBox.addButton(tr("Hayır"), QMessageBox::ActionRole);
 messageBox.setIcon(QMessageBox::Information);
         messageBox.exec();
});
layout->addWidget(savePdfButton, 44,0,1,2);
/*******************************/

//layout->addWidget(pageButton, 50, 0,1,1);
//layout->addWidget(pagePopButton,50,1,1,1);

//layout->addWidget(sayfaLabel,5,0,1,2);
//pagePopButton->setMenu(pageMenu(SLOT(pagePopButton()), DiagramItem::DiagramType::Cizgi));
/*QMenu *pageMenus=pageMenu();
connect(pagePopButton, &QPushButton::clicked, [=]() {
    scene->setPopMenuStatus(true);
    pageMenus->exec(mapToGlobal(pagePopButton->pos() + QPoint(kutuLeft-315,kutuTop+boy/2)));
    scene->setPopMenuStatus(false);
});*/
/*ileriGeriSayfaLabel=new QLabel(this);
//ileriGeriSayfaLabel->setText("( "+QString::number(sceneSayfaNumber+1)+"/"+QString::number(sceneSayfaActiveNumber+1)+" )");
ileriGeriSayfaLabel->setText("  "+QString::number(sceneSayfaNumber+1)+"/"+QString::number(sceneSayfaActiveNumber+1));
ileriGeriSayfaLabel->setStyleSheet("QLabel { color:#3e8cb7;}");
ileriGeriSayfaLabel->move(this->width()/2-en/10,this->height()-boy-boy/10);
ileriGeriSayfaLabel->hide();
*/
/***************************************************************/
/*nextSayfaButton = new QPushButton(this);
nextSayfaButton->setIcon(QIcon(":icons/nextpage.png"));
nextSayfaButton->setFixedSize(en, boy);
nextSayfaButton->setIconSize(QSize(en,boy));
nextSayfaButton->setFlat(true);
nextSayfaButton->hide();
nextSayfaButton->move(this->width()/20*10.5+boy*2,this->height()-boy-boy/4);

connect(nextSayfaButton, &QPushButton::clicked, [=]()
{
    ileriSayfaButtonClick();
   });*/
/***************************************************************/
/*backSayfaButton = new QPushButton(this);
backSayfaButton->setIcon(QIcon(":icons/backpage.png"));
backSayfaButton->setFixedSize(en, boy);
backSayfaButton->setIconSize(QSize(en,boy));
backSayfaButton->setFlat(true);
backSayfaButton->hide();
backSayfaButton->move(this->width()/20*9.5-boy*2,this->height()-boy-boy/4);
connect(backSayfaButton, &QPushButton::clicked, [=]()
{
geriSayfaButtonClick();
});*/
/***************************************************************/
/***************************************************************/
delSayfaButton = new QPushButton(this);
delSayfaButton->setIcon(QIcon(":icons/delpage.png"));
delSayfaButton->setFixedSize(en, boy);
delSayfaButton->setIconSize(QSize(en*0.8,boy*0.8));
delSayfaButton->setFlat(true);
///delSayfaButton->hide();
delSayfaButton->setEnabled(false);
delSayfaButton->move(this->width()/4*3,this->height()-boy-boy);
connect(delSayfaButton, &QPushButton::clicked, [=]()
{
silSayfaButtonClick();
});
/***************************************************************/
/***************************************************************/
addSayfaButton = new QPushButton(this);
addSayfaButton->setIcon(QIcon(":icons/addpage.png"));
addSayfaButton->setFixedSize(en*c, boy);
addSayfaButton->setIconSize(QSize(en*0.8,boy*0.8));
addSayfaButton->setFlat(true);
//addSayfaButton->hide();
addSayfaButton->move(this->width()/4-boy,this->height()-boy-boy);
connect(addSayfaButton, &QPushButton::clicked, [=]()
{
ekleSayfaButtonClick();
});
/*************************/
ayarButton->setFixedSize(en*c, boy*0.8);
ayarButton->setIconSize(QSize(en,boy*0.7));
layout->addWidget(ayarButton, 50, 0,1,2);
//pagePopButton->setMenu(pageMenu(SLOT(pagePopButton()), DiagramItem::DiagramType::Cizgi));
QMenu *ayarMenus=ayarMenu();
ayarMenus->show();ayarMenus->hide();

connect(ayarButton, &QPushButton::clicked, [=]() {
   scene->setPopMenuStatus(true);
   ayarMenus->exec(mapToGlobal(ayarButton->pos() + QPoint(kutuLeft-ayarMenus->width(),kutuTop+boy/2)));
   scene->setPopMenuStatus(false);
});
/***************************************************************/

//layout->addWidget(backSayfaButton, 50,0,1,2);
//layout->addWidget(nextSayfaButton, 50,1,1,2);
gizleGosterButton->setFixedSize(en*c, boy*0.8);
gizleGosterButton->setIconSize(QSize(en*0.7,boy*0.7));
layout->addWidget(gizleGosterButton, 55,0,1,2);

kalemKapatButton->setFixedSize(en*c, boy*0.8);
kalemKapatButton->setIconSize(QSize(en*1.2,boy*0.7));

layout->addWidget(kalemKapatButton,60,0,1,2);
//layout->setColumnStretch(3, 25);
kokLayot->addLayout(layout);
//buyukKutu->setLayout(layout);

/***********************kalem Move button******************************/
auto MoveLeft= new QPushButton(this);
MoveLeft->setIcon(QIcon(":icons/kalemmove.png"));
MoveLeft->setFixedSize(en*c, boy);
MoveLeft->setIconSize(QSize(en*0.8,boy*0.8));
MoveLeft->setFlat(true);
//addSayfaButton->hide();
MoveLeft->move(20,this->height()-boy-boy);
connect(MoveLeft, &QPushButton::clicked, [=]()
{
    if(kutuLeft!=10)
    {
    buyukKutu->setGeometry(QRect(10,kutuTop,kutuWidth,kutuHeight));
    kutuLeft=10;
   /// kutuTop=50;
    gizleGosterButtonClick();
    gizleGosterButtonClick();
    }else{
        buyukKutu->setGeometry(QRect(this->width()-kutuWidth-10,kutuTop,kutuWidth,kutuHeight));
        kutuLeft=this->width()-kutuWidth-10;
       /// kutuTop=50;
        gizleGosterButtonClick();
        gizleGosterButtonClick();
    }
});
auto MoveRight= new QPushButton(this);
MoveRight->setIcon(QIcon(":icons/kalemmove.png"));
MoveRight->setFixedSize(en*c, boy);
MoveRight->setIconSize(QSize(en*0.8,boy*0.8));
MoveRight->setFlat(true);
//addSayfaButton->hide();
MoveRight->move(this->width()-en-20,this->height()-boy-boy);
connect(MoveRight, &QPushButton::clicked, [=]()
{
    if(kutuLeft!=this->width()-kutuWidth-10)
    {
    buyukKutu->setGeometry(QRect(this->width()-kutuWidth-10,kutuTop,kutuWidth,kutuHeight));
    kutuLeft=this->width()-kutuWidth-10;
   /// kutuTop=50;
    gizleGosterButtonClick();
    gizleGosterButtonClick();
    }else{
        buyukKutu->setGeometry(QRect(10,kutuTop,kutuWidth,kutuHeight));
        kutuLeft=10;
       /// kutuTop=50;
        gizleGosterButtonClick();
        gizleGosterButtonClick();

    }
});
/******************************************************/

}

#endif // KALEMLAYOUT_H
