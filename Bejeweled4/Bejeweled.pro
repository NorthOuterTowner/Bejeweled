QT       += core gui widgets network multimedia sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Login.cpp \
    PixmapSlider.cpp \
    about.cpp \
    client.cpp \
    end.cpp \
    game.cpp \
    # gameitems.cpp \
    gametimer.cpp \
    globalvalue.cpp \
    heatmap.cpp \
    help.cpp \
    hoverbutton.cpp \
    main.cpp \
    mainwindow.cpp \
    rankdialog.cpp \
    settingwidget.cpp \
    pause.cpp \
    shopwidget.cpp \
    signup.cpp \
    stonelabel.cpp \
    utils.cpp

HEADERS += \
    Login.h \
    PixmapSlider.h \
    about.h \
    client.h \
    end.h \
    game.h \
    # gameitems.h \
    gametimer.h \
    globalvalue.h \
    heatmap.h \
    help.h \
    hoverbutton.h \
    mainwindow.h \
    rankdialog.h \
    settingwidget.h \
    pause.h \
    shopwidget.h \
    signup.h \
    stonelabel.h \
    utils.h

FORMS += \
    Login.ui \
    about.ui \
    client.ui \
    end.ui \
    game.ui \
    heatmap.ui \
    help.ui \
    mainwindow.ui \
    rankdialog.ui \
    settingwidget.ui \
    pause.ui \
    shopwidget.ui \
    signup.ui\
    settingwidget.ui

TRANSLATIONS += \
    Bejeweled_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    build/Gems/jewel.qrc \
    build/rankback/rank.qrc \
    music.qrc \
    picture/picture.qrc

DISTFILES += \
    build/Fruits/Fruit1.png \
    build/Fruits/Fruit2.png \
    build/Fruits/Fruit3.png \
    build/Fruits/Fruit4.png \
    build/Fruits/Fruit5.png \
    build/Fruits/Fruit6.png \
    build/Fruits/Fruit7.png \
    build/Fruits/Fruit8.png \
    build/Fruits/Fruit9.png \
    build/Fruits/Grape.png \
    music/background/music-1.wav \
    music/background/music-2.wav \
    music/button/button_mouseleave.wav \
    music/button/button_mouseover.wav \
    music/button/button_press.wav \
    music/button/button_release.wav \
    music/effect/Time_Up.wav \
    music/effect/Welcome.wav \
    music/effect/bad.wav \
    music/effect/effect1.wav \
    music/effect/effect2.wav \
    music/effect/effect3.wav \
    music/effect/effect4.wav \
    music/effect/effect5.wav \
    music/effect/hit.wav \
    picture/3balls/ball1.png \
    picture/3balls/ball2.png \
    picture/3balls/ball3.png \
    picture/ArrowUp.png \
    picture/GADJET3balls.png \
    picture/GameWidget/Gem/0000.gif \
    picture/GameWidget/Gem/Blue.gif \
    picture/GameWidget/Gem/Blue.png \
    picture/GameWidget/Gem/Gold.gif \
    picture/GameWidget/Gem/Gold.png \
    picture/GameWidget/Gem/Green.gif \
    picture/GameWidget/Gem/Green.png \
    picture/GameWidget/Gem/Magic.gif \
    picture/GameWidget/Gem/Magic.png \
    picture/GameWidget/Gem/Red.gif \
    picture/GameWidget/Gem/Red.png \
    picture/GameWidget/Gem/Silver.gif \
    picture/GameWidget/Gem/Silver.png \
    picture/GameWidget/Gem/fire.gif \
    picture/GameWidget/Gem/goldSQ.gif \
    picture/GameWidget/Gem/orange.gif \
    picture/GameWidget/Gem/orange.png \
    picture/GameWidget/Gem/violet.gif \
    picture/GameWidget/Gem/violet.png \
    picture/GameWidget/Gem/waterSQ.gif \
    picture/GameWidget/selected.png \
    picture/Settingpage/.keep \
    picture/Settingpage/BttomBar.png \
    picture/Settingpage/DialogButtonGlow.png \
    picture/Settingpage/Toggle.png \
    picture/Settingpage/Toggle_1.png \
    picture/Settingpage/Toggle_2.png \
    picture/Settingpage/dialogbox.png \
    picture/Settingpage/dialogbox_select.png \
    picture/Settingpage/dialogbutton.png \
    picture/Settingpage/dialogtitle.png \
    picture/Settingpage/slider-track-1.png \
    picture/Settingpage/slider-track-2.png \
    picture/Settingpage/slider-track.png \
    picture/Settingpage/thumb.png \
    picture/StartPage/BackgroundHQ.png \
    picture/StartPage/background.png \
    picture/StartPage/title.png \
    picture/app_icon.ico \
    picture/arrow.png \
    picture/backdrop00.jpg \
    picture/blueBar.png \
    picture/button/Level.png \
    picture/button/Level_back.png \
    picture/button/ball.png \
    picture/frame.png \
    picture/frame_red.png \
    picture/images/GADJET3balls_01.png \
    picture/images/GADJET3balls_02.png \
    picture/images/GADJET3balls_03.png \
    picture/images/GADJET3balls_03_tmp19649 \
    picture/images/GADJET3balls_04.png \
    picture/images/GADJET3balls_05.png \
    picture/images/GADJET3balls_06.png \
    picture/images/GADJET3balls_07.png \
    picture/mouse1.png \
    picture/mouse2.png \
    picture/mouse3.png \
    picture/radius_back.png \
    picture/radius_front.png \
    picture/redBar.png \
    picture/scorepod.png \
    picture/splash.jpg \
    picture/starsBK.gif \
    picture/time_out.png \
    qsqlited.dll
