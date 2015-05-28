TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11

SOURCES += main.cpp \
    crawler.cpp \
    linkqueue.cpp \
    htmlparse.cpp \
    dbutil.cpp \
    handleurl.cpp

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH+=/usr/local/opt/curl/include
INCLUDEPATH+=/usr/local/opt/berkeley-db/include
INCLUDEPATH+=/usr/local/include





win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lre2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lre2
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lre2

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/release/libre2.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/debug/libre2.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/release/re2.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/debug/re2.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libre2.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/release/ -lcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/debug/ -lcurl
else:unix: LIBS += -L$$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/ -lcurl

INCLUDEPATH += $$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/include
DEPENDPATH += $$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/release/libcurl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/debug/libcurl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/release/curl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/debug/curl.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.41.0_1/lib/libcurl.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/release/ -ldb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/debug/ -ldb
else:unix: LIBS += -L$$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/ -ldb

INCLUDEPATH += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/include
DEPENDPATH += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/release/libdb.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/debug/libdb.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/release/db.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/debug/db.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/libdb.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/release/ -ldb_cxx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/debug/ -ldb_cxx
else:unix: LIBS += -L$$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/ -ldb_cxx

INCLUDEPATH += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/include
DEPENDPATH += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/release/libdb_cxx.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/debug/libdb_cxx.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/release/db_cxx.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/debug/db_cxx.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/berkeley-db/6.1.19/lib/libdb_cxx.a

HEADERS += \
    crawler.h \
    linkqueue.h \
    htmlparse.h \
    dbutil.h \
    handleurl.h
