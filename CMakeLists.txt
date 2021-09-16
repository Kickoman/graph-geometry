cmake_minimum_required(VERSION 3.5)

project(GraphGeometry LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Default build type
if(NOT GRAPH_GEOMETRY_LIB_TYPE)
    set(GRAPH_GEOMETRY_LIB_TYPE "SHARED")
endif()

set(HEADERS_DIR include/)
set(SOURCES_DIR src/)

add_subdirectory(${HEADERS_DIR}/2d/)
add_subdirectory(${SOURCES_DIR}/2d/)
add_subdirectory(${HEADERS_DIR}/3d/)
add_subdirectory(${SOURCES_DIR}/3d/)

set(HEADERS
    ${GEOMETRY_2D_HEADERS}
    ${GEOMETRY_3D_HEADERS}

    ${HEADERS_DIR}/mathematics.h
)

set(SOURCES
    ${GEOMETRY_2D_SOURCES}
    ${GEOMETRY_3D_SOURCES}
)

add_library(graphgeometry ${GRAPH_GEOMETRY_LIB_TYPE} ${HEADERS} ${SOURCES})
target_include_directories(graphgeometry PUBLIC ${HEADERS_DIR} ${GEOMETRY_2D_INCLUDEDIR})
message("include directory: ${GEOMETRY_2D_INCLUDEDIR}")

set_target_properties(
    graphgeometry PROPERTIES
    ENABLE_EXPORTS 1
    WINDOWS_EXPORT_ALL_SYMBOLS 1
)
