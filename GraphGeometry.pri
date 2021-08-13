!isEmpty(GRAPHGEOMETRY_PRI_INCLUDED): error("GraphGeometry.pri is already included")
GRAPHGEOMETRY_PRI_INCLUDED = 1

INCLUDEPATH += $$PWD/include

CONFIG(debug, debug|release): {
    GRAPHGEOMETRY_OUTPUT = "$$PWD/build/debug"
} else: {
    GRAPHGEOMETRY_OUTPUT = "$$PWD/build/release"
}

message("libGraphGeometry will be looked at: $$GRAPHGEOMETRY_OUTPUT/bin")
LIBS += -L"$$GRAPHGEOMETRY_OUTPUT/bin/" -lGraphGeometry
