TARGET = e-tahta
TEMPLATE = app
CONFIG += c++11

LIBS += -L/usr/local/lib -lpoppler-qt5
QMAKE_CXXFLAGS = -std=c++11
QT += widgets gui printsupport xml


SOURCES += \
    mainwindow.cpp \
    main.cpp \
    gridlines.cpp \
    scene.cpp \
    dotsignal.cpp \
    verectangle.cpp \
    depo.cpp

HEADERS += \
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

target.path = /usr/bin

desktop_file.files = e-tahta.desktop
desktop_file.path = /usr/share/applications/
icon.files = icons/e-tahta.png
icon.path = /usr/share/e-tahta


INSTALLS += target desktop_file icon

DISTFILES += \
    icons/e-tahta.png

