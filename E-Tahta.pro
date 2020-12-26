LIBS += -L/usr/local/lib -lpoppler-qt5
QMAKE_CXXFLAGS = -std=c++11
QT += widgets gui printsupport xml
SOURCES += \
    hovereventfilter.cpp \
    mainwindow.cpp \
    main.cpp \
    gridlines.cpp \
    scene.cpp \
    dotsignal.cpp \
    verectangle.cpp \
    depo.cpp

HEADERS += \
    hovereventfilter.h \
    mainwindow.h \
    gridlines.h \
    diagramitem.h \
    scene.h \
    dotsignal.h \
    verectangle.h \
    function.h \
    buttonclick.h \
    popmenu.h \
    kalemlayout.h \
    filecrud.h \
    depo.h

RESOURCES += \
    userdrawing.qrc


