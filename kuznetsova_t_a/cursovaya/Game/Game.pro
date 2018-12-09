
#QT += core gui
QT += quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coordinate.cpp \
    ball.cpp \
    canvas.cpp \
    window.cpp \
    game.cpp \
    test.cpp \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    coordinate.h \
    ball.h \
    canvas.h \
    window.h \
    game.h \
    test.h

FORMS += \
    window.ui

DISTFILES += \
    background.jpg \
    Ellipse-1.png \
    Ellipse-2.png \
    Ellipse-3.png \
    Ellipse-4.png \
    Ellipse-5.png \
    Ellipse-6.png \
    Ellipse-7.png \
    Ellipse-8.png

RESOURCES +=
