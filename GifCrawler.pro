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
    handleurl.cpp \
    imgutil.cpp \
    md5.cpp

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH+=/usr/local/opt/curl/include
INCLUDEPATH+=/usr/local/opt/berkeley-db/include
INCLUDEPATH+=/usr/local/include


HEADERS += \
    crawler.h \
    linkqueue.h \
    htmlparse.h \
    dbutil.h \
    handleurl.h \
    imgutil.h \
    md5.h



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/release/ -lcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/debug/ -lcurl
else:unix: LIBS += -L$$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/ -lcurl

INCLUDEPATH += $$PWD/../../../../../usr/local/Cellar/curl/7.42.1/include
DEPENDPATH += $$PWD/../../../../../usr/local/Cellar/curl/7.42.1/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/release/libcurl.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/debug/libcurl.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/release/curl.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/debug/curl.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/curl/7.42.1/lib/libcurl.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/release/ -lre2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/debug/ -lre2
else:unix: LIBS += -L$$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/ -lre2

INCLUDEPATH += $$PWD/../../../../../usr/local/Cellar/re2/20150501/include
DEPENDPATH += $$PWD/../../../../../usr/local/Cellar/re2/20150501/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/release/libre2.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/debug/libre2.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/release/re2.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/debug/re2.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/Cellar/re2/20150501/lib/libre2.a


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/berkeley-db/lib/release/ -ldb_cxx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/berkeley-db/lib/debug/ -ldb_cxx
else:unix: LIBS += -L$$PWD/berkeley-db/lib/ -ldb_cxx

INCLUDEPATH += $$PWD/berkeley-db/include
DEPENDPATH += $$PWD/berkeley-db/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/berkeley-db/lib/release/libdb_cxx.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/berkeley-db/lib/debug/libdb_cxx.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/berkeley-db/lib/release/db_cxx.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/berkeley-db/lib/debug/db_cxx.lib
else:unix: PRE_TARGETDEPS += $$PWD/berkeley-db/lib/libdb_cxx.a
