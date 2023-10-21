cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME M323_LB3)

project(${PROJECT_NAME})

set(SOURCES
        src/Main.cpp
        src/Media.cpp
        src/Date.cpp
        include/Date.h
        src/Title.cpp
        include/Title.h
        src/MediaBuild.cpp
        include/MediaBuild.h
        src/Draw.cpp
        include/Draw.h
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(PkgConfig REQUIRED)

pkg_check_modules(JSONCPP jsoncpp)

link_libraries(${JSONCPP_LIBRARIES})

target_link_libraries(${PROJECT_NAME} ${JSONCPP_LIBRARIES})

