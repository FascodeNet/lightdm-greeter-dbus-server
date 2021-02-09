cmake_minimum_required(VERSION 3.14)

project(lightdm-krkr-grpc-server LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

include(FindPkgConfig)
pkg_check_modules(LIGHTDM_QT liblightdm-qt5-3)

include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}
                      ${CMAKE_CURRENT_BINARY_DIR}
                      ${LIGHTDM_QT_INCLUDE_DIRS}
)


add_executable(lightdm-krkr-grpc-server
  main.cpp
  lightdmobject.cpp
  lightdmobject.h
)
target_link_libraries(lightdm-krkr-grpc-server Qt${QT_VERSION_MAJOR}::Core ${LIGHTDM_QT_LIBRARIES})
