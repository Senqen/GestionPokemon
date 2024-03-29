QT       += widgets
QT       += multimedia

TARGET = PokeGestion
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        gestion_page.cpp \
        gestion_page_tab.cpp \
        main.cpp \
        mainwindow.cpp \
        create_page.cpp

HEADERS += \
        gestion_page.h \
        gestion_page_tab.h \
        mainwindow.h \
        create_page.h

FORMS += \
        create_page.ui \
        gestion_page.ui \
        gestion_page_tab.ui \
        mainwindow.ui

RESOURCES += \
    background.qrc
