QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    comando_cursiva.cpp \
    comando_negrita.cpp \
    comando_subrayado.cpp \
    comandoformato.cpp \
    main.cpp \
    cframe.cpp \
    tarea_diaria.cpp \
    tarea_semanal.cpp \
    tareabase.cpp

HEADERS += \
    cframe.h \
    comando_cursiva.h \
    comando_negrita.h \
    comando_subrayado.h \
    comandoformato.h \
    tarea_diaria.h \
    tarea_semanal.h \
    tareabase.h

FORMS += \
    cframe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
