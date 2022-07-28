QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formproducto.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    excepcionNumeroNegativo.h \
    formproducto.h \
    mainwindow.h

FORMS += \
    formproducto.ui \
    mainwindow.ui

TRANSLATIONS += \
    ui_es_CR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -ltrastienda
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -ltrastienda
else:unix: LIBS += -L$$PWD/../../lib/ -ltrastienda

INCLUDEPATH += $$PWD/../../lib/include
DEPENDPATH += $$PWD/../../lib/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lproducto
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lproducto
else:unix: LIBS += -L$$PWD/../../lib/ -lproducto

INCLUDEPATH += $$PWD/../../lib/include
DEPENDPATH += $$PWD/../../lib/include
