cmake_minimum_required(VERSION 3.5)
project(Intelligent-Door-Lock)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -ldl -lpthread -Wall")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++fs")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(OpenCV REQUIRED)
find_package(OpenMP REQUIRED)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/ncnn/include)
LINK_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/ncnn/lib)
set(PROJECT_SOURCES
         src/main.cpp
         src/welcome.cpp
         src/welcome.h
         src/welcome.ui
         src/FacePreprocess.h
         src/arcface.h
         src/live.h
         src/mtcnn_new.h
         src/arcface.cpp
         src/live.cpp
         src/livefacereco.cpp
         src/mtcnn_new.cpp
         src/parallel_video_capture.cpp
         src/defs.hpp
         src/livefacereco.hpp
         src/math.hpp
         src/parallel_video_capture.hpp
)
add_executable(Intelligent-Door-Lock ${PROJECT_SOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS} ${Qt5Widgets_LIBRARIES} ncnn pthread -lstdc++fs ${WIRINGPI_LIBRARIES} gomp)