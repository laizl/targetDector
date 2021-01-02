# cmake的最低版本要求
cmake_minimum_required(VERSION 3.10.0)

# 设置项目名称
set(PRO_NAME targetCheck)

project(${PRO_NAME})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 在相应的构建目录中查找头文件
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 设置CMake在需要时自动运行moc
set(CMAKE_AUTOMOC ON)

# 从Qt设计师文件列表中创建代码
set(CMAKE_AUTOUIC ON)


set(CMAKE_AUTORCC ON)

# 设置Qt的
set(CMAKE_PREFIX_PATH /home/laizl/Qt5.14.2/5.14.2/gcc_64/lib/cmake/)

#search include
include_directories( ${PROJECT_SOURCE_DIR}/include/) 

# 搜索当前目录下的源文件
aux_source_directory(. DIR_SRCS)

set(SourceFile 
      ./src/mainwindow.cpp
      ./src/ShowMatWidget.cpp
      ./src/test.cpp
)

# # 寻找Qt5的库
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Gui REQUIRED)
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5OpenGL REQUIRED)

SET(QT_OBJECT_HEADERS  ./include/mainwindow.h ./include/ShowMatWidget.h)
SET(QT_UI_LISTS  
./ui/mainwindow.ui
./ui/ShowMatWidget.ui
 )
#add search path
SET(CMAKE_AUTOUIC_SEARCH_PATHS ui)

QT5_WRAP_CPP(MOC_HEADLISTS ${QT_OBJECT_HEADERS})
QT5_WRAP_UI(UI_HEADLISTS ${QT_UI_LISTS})
# SET(can_ui_FORMS src/widget.ui)

# # message(${Qt5Widgets})
#添加预编译宏
ADD_DEFINITIONS(-DTORRENT_LIBRARY)
ADD_DEFINITIONS(-DNO_FREETYPE)
ADD_DEFINITIONS(-DUNICODE -D_UNICODE)
ADD_DEFINITIONS(-DHCPP_LEGACY_API)

# ADD_SUBDIRECTORY( src )
# 设置可执行文件 QObject
# set (Qobject_lists include/mainwindow.h)

# 编译完成libdark.so库后
#opencv
add_definitions(-std=c++11) 
ADD_DEFINITIONS(-DOPENCV)
ADD_DEFINITIONS(-DGPU)
set(DBUILD_TIFF ON)
#########   opencv   #########
FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

MESSAGE(STATUS "Project: ${PROJECT_NAME}")
MESSAGE(STATUS "OpenCV library status:")
MESSAGE(STATUS "    version: ${OpenCV_VERSION}")
MESSAGE(STATUS "    libraries: ${OpenCV_LIBS}")
MESSAGE(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

#########         darknet   #########
include_directories(./dark/include/darknet/)
find_library(darknet libdarknet.so ./dark/lib/)

# qobject在camke中要单独处理
add_executable(${PRO_NAME} ${DIR_SRCS}  ${SourceFile} ${MOC_HEADLISTS} ${UI_HEADLISTS} )

# Qt5::Widgets Qt5::Gui Qt5::Core Qt5::OpenGL 

# 链接Qt5的库
target_link_libraries(${PRO_NAME} Qt5::Widgets Qt5::Gui Qt5::Core Qt5::OpenGL ${OpenCV_LIBS}  ${darknet})