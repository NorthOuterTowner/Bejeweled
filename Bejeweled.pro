QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    globalvalue.cpp \
    gridwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    stonelabel.cpp

HEADERS += \
    game.h \
    globalvalue.h \
<<<<<<< HEAD
    gridwidget.h \
    maingaminglabel.h \
=======
>>>>>>> parent of c78b449 (update the delete method)
    mainwindow.h \
    stonelabel.h

FORMS += \
    game.ui \
    mainwindow.ui

TRANSLATIONS += \
    Bejeweled_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    build/Gems/jewel.qrc
