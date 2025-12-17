cmake_minimum_required(VERSION 2.8.12.2)
project(courseDesign)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 强制显式启用C++11支持
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH  "/opt/qtlib560_base")
#set(QT_RCC_EXECUTABLE "D:/Qt/5.15.2/mingw81_64/bin/rcc.exe")

set(SDL_ROOT "/opt/sdl2-arm")


# 头文件目录
include_directories(
        src/core
        src/input
        src/widget/
        src/character/
        ${SDL_ROOT}/include
        ${QT5_ROOT}/include
)

# 库文件目录
link_directories(
    ${SDL_ROOT}/lib
    ${QT5_ROOT}/lib
)

set(SRCS
        src/core/game_manager.cpp
        src/input/in_manager.cpp
        src/widget/gameView.cpp
)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

# 添加资源文件
qt5_add_resources(RESOURCES  "resources/resources.qrc")

add_executable(courseDesign main.cpp ${SRCS} ${RESOURCES})

target_link_libraries(courseDesign
         Qt5::Core
         Qt5::Gui
         Qt5::Widgets
         libSDL2.so
)
