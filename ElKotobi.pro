QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += /Users/merhab/Desktop/alKotobi/vendor/spdlog/include
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CORE/mnfield.cpp \
    CORE/mnrecord.cpp \
    DB/mndb.cpp \
    DB/mnquery.cpp \
    HELPERS/log.cpp \
    HELPERS/mnpathes.cpp \
    TESTS/frmtests.cpp \
    common/mncommon.cpp \
    common/mnkotob.cpp \
    common/mnmainkalimat.cpp \
    common/mnothors.cpp \
    import/mnimport.cpp \
    import/mnindexorg.cpp \
    import/mnkitaborg.cpp \
    import/mnothororg.cpp \
    kitab/mnindex.cpp \
    kitab/mnkalimat.cpp \
    kitab/mnkitab.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CORE/mnfield.h \
    CORE/mnrecord.h \
    DB/mndb.h \
    DB/mnquery.h \
    HELPERS/log.h \
    HELPERS/mnpathes.h \
    TESTS/frmtests.h \
    common/mncommon.h \
    common/mnkotob.h \
    common/mnmainkalimat.h \
    common/mnothors.h \
    headers.h \
    import/mnimport.h \
    import/mnindexorg.h \
    import/mnkitaborg.h \
    import/mnothororg.h \
    kitab/mnindex.h \
    kitab/mnkalimat.h \
    kitab/mnkitab.h \
    mainwindow.h

FORMS += \
    TESTS/frmtests.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
