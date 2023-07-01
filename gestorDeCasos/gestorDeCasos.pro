QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogmain.cpp \
    fechas.cpp \
    fechasadd.cpp \
    main.cpp \
    iniciarsesion.cpp \
    mainwindow.cpp \
    pagos.cpp \
    pagosadd.cpp \
    singup.cpp \
    todolist.cpp

HEADERS += \
    dialogmain.h \
    fechas.h \
    fechasadd.h \
    iniciarsesion.h \
    mainwindow.h \
    pagos.h \
    pagosadd.h \
    singup.h \
    todolist.h

FORMS += \
    dialogmain.ui \
    fechas.ui \
    fechasadd.ui \
    iniciarsesion.ui \
    mainwindow.ui \
    pagos.ui \
    pagosadd.ui \
    singup.ui \
    todolist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
