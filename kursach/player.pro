TEMPLATE = app
TARGET = player

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    controls.h \
    video.h \
    playlist.h \
    videoplayer.h
SOURCES = main.cpp \
    controls.cpp \
    video.cpp \
    playlist.cpp \
    videoplayer.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/player
INSTALLS += target
