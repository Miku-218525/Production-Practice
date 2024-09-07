QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customplot/XxwCustomPlot.cpp \
    customplot/XxwTracer.cpp \
    customplot/qcustomplot.cpp \
    customplotform.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    customplot/XxwCustomPlot.h \
    customplot/XxwTracer.h \
    customplot/qcustomplot.h \
    customplotform.h \
    mainwindow.h

FORMS += \
    customplotform.ui \
    mainwindow.ui

TRANSLATIONS += \
    widgets_903_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# 引入头文件
INCLUDEPATH += $$PWD\SP++3.0\include

# 引入库文件
LIBS += $$PWD\SP++3.0\lib\libfftw3-3.lib
LIBS += $$PWD\SP++3.0\lib\libfftw3f-3.lib
LIBS += $$PWD\SP++3.0\lib\libfftw3l-3.lib

RESOURCES += \
    icon.qrc
