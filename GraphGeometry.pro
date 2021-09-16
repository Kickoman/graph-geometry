TEMPLATE = lib
QT += core
CONFIG += c++11
TARGET = GraphGeometry
DEFINES += GRAPHGEOMETRY_LIBRARY

HEADERS += \
    graphgeometry_global.h \
    include/line.h   \
    include/mathematics.h       \
    include/point.h   \
    include/section.h  \
    include/twodvector.h

SOURCES += \
    src/line.cpp \
    src/point.cpp     \
    src/section.cpp \
    src/twodvector.cpp    \

# Output
CONFIG(debug, debug|release): {
    OUTPUT_DIR = "$$PWD/build/debug"
} else: {
    OUTPUT_DIR = "$$PWD/build/release"
}

OBJECTS_DIR = "$$OUTPUT_DIR/obj/"
MOC_DIR     = "$$OUTPUT_DIR/moc/"
RCC_DIR     = "$$OUTPUT_DIR/res/"
UI_DIR      = "$$OUTPUT_DIR/ui/"
DESTDIR     = "$$OUTPUT_DIR/bin/"

message("libGraphGeometry library (.so) will be placed at: $$DESTDIR")

INCLUDEPATH += \
    include/ \
    $$PWD/
