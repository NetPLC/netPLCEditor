# project netPLCEditor

project(netPLCEditor)
cmake_minimum_required(VERSION 2.6)

# unset SOURCE_DATE_EPOCH env for timestamp issue
unset(ENV{SOURCE_DATE_EPOCH})

set(GIT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# 使能 MOC 构建
set(CMAKE_AUTOMOC ON)
# 使能 UIC 构建
set(CMAKE_AUTOUIC ON)
# 使能 RCC 构建
set(CMAKE_AUTORCC ON)
# 使能当前目录包含
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# 使能打印更详细的构建信息/出错信息
set(CMAKE_VERBOSE_MAKEFILE ON)

# 查找 Qt5 QWidgets 库路径
find_package(Qt5Gui REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5XmlPatterns REQUIRED)

file(GLOB_RECURSE qui_data RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.ui)
file(GLOB_RECURSE qrc_data RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.qrc)

qt5_wrap_ui(qui_srcs ${qui_data})
qt5_add_resources(qrc_srcs ${qrc_data})

set(qt_srcs
    ${qui_srcs}
    ${qrc_srcs})

set(plc_incs
    ${PROJECT_BINARY_DIR}
    src
    src/ui
    src/plc
    src/core)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/GitVersion.cmake)

# setup sources
aux_source_directory(src main_srcs)
aux_source_directory(src/ui ui_srcs)
aux_source_directory(src/core core_srcs)
aux_source_directory(src/plc plc_srcs)

set(src_srcs
    ${main_srcs}
    ${core_srcs}
    ${plc_srcs}
    # qt gui
    ${ui_srcs}
    ${qt_srcs}
)

# add macros
SET(CMAKE_CXX_FLAGS "-O3 -Wall -Wunused-function -fpermissive")
SET(CMAKE_C_FLAGS "-O3 -Wall -Wunused-function --std=gnu99")
add_definitions(-D_POSIX -D__USE_MISC)

SET(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,-Map=${CMAKE_PROJECT_NAME}.map")

# add includes
include_directories(${plc_incs})

# generate library
add_executable(netPLCEditor ${src_srcs})
qt5_use_modules(netPLCEditor Core Widgets Gui Network Xml XmlPatterns)

if(WIN32)
    target_link_libraries(netPLCEditor
        stdc++
        gcc
        ws2_32
        winmm
        wsock32)
elseif (UNIX)
    target_link_libraries(netPLCEditor
        stdc++
        gcc
        pthread
        rt)
endif()

# install executable
install(TARGETS netPLCEditor
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
