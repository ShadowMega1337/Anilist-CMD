cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME M323_LB3)

project(${PROJECT_NAME})


include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(lib/jsoncpp/)


set(SOURCES
        src/Main.cpp
        src/Media.cpp
        src/Date.cpp
        include/Date.h
        src/Title.cpp
        include/Title.h
        src/MediaBuild.cpp
        include/MediaBuild.h
        src/UI.cpp
        include/UI.h
        src/Backend.cpp
        include/Backend.h
        src/UIService.cpp
        include/UIService.h
        src/EnumMapping.cpp
        include/EnumMapping.h
)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE jsoncpp_lib)
