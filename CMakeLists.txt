cmake_minimum_required(VERSION 3.18)

project(KenshiLib)

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "KenshiLib requires a 64 bit build to align with Kenshi.")
endif()

message("CMAKE_VS_PLATFORM_TOOLSET: ${CMAKE_VS_PLATFORM_TOOLSET}")

add_library(KenshiLib STATIC)

set(ENV{KLIB_DIR} "${CMAKE_CURRENT_LIST_DIR}")
set(ENV{KLIB_INCLUDE_DIR} "$ENV{KLIB_DIR}/Include")
set(ENV{KLIB_SOURCE_DIR}  "$ENV{KLIB_DIR}/Source")
set(ENV{KLIB_LIBRARY_DIR}  "$ENV{KLIB_DIR}/Libraries")

add_subdirectory(Libraries)

file(GLOB KLIB_SOURCES_CORE
    "$ENV{KLIB_SOURCE_DIR}/core/*.cpp"
)
file(GLOB KLIB_SOURCES_KENSHI
    "$ENV{KLIB_SOURCE_DIR}/kenshi/*.cpp"
)
file(GLOB KLIB_SOURCES_MAIN
    "$ENV{KLIB_SOURCE_DIR}/*.cpp"
)

file(GLOB KLIB_INCLUDES_CORE
    "$ENV{KLIB_INCLUDE_DIR}/core/*.h"
)
file(GLOB KLIB_INCLUDES_KENSHI
    "$ENV{KLIB_INCLUDE_DIR}/kenshi/*.h"
)
file(GLOB KLIB_INCLUDES_MAIN
    "$ENV{KLIB_INCLUDE_DIR}/*.h"
)


set(KLIB_SOURCES
    ${KLIB_SOURCES_CORE}
    ${KLIB_SOURCES_KENSHI}
    ${KLIB_SOURCES_MAIN}

    ${KLIB_INCLUDES_CORE}
    ${KLIB_INCLUDES_KENSHI}
    ${KLIB_INCLUDES_MAIN}
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${KLIB_SOURCES})

target_sources(KenshiLib PRIVATE ${KLIB_SOURCES})
target_precompile_headers(KenshiLib PRIVATE "$ENV{KLIB_INCLUDE_DIR}/stdafx.h")
target_include_directories(KenshiLib PUBLIC "$ENV{KLIB_INCLUDE_DIR}")
target_link_libraries(KenshiLib PUBLIC ogre mygui)

