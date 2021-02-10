cmake_minimum_required(VERSION 3.14)

project(lightdm-krkr-dbus-server LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Core DBus REQUIRED)

include(FindPkgConfig)
pkg_check_modules(LIGHTDM_QT liblightdm-qt5-3)

include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}
                      ${CMAKE_CURRENT_BINARY_DIR}
                      ${LIGHTDM_QT_INCLUDE_DIRS}
)
set(dbus_xml net.fascode.lightdm.krkr_dbus.xml)
set(SOURCES
    main.cpp
    lightdmobject.cpp
    lightdmobject.h
    greeter_subprocess_runner.cpp
    greeter_subprocess_runner.h
    dbus_lightdm_server.cpp
    dbus_lightdm_server.h)
qt5_add_dbus_interface(SOURCES ${dbus_xml} lightdm_krkr_dbus_ifce)
qt5_add_dbus_adaptor(SOURCES ${dbus_xml} lightdmobject.h lightdmobject)


add_executable(lightdm-krkr-dbus-server
    ${SOURCES}
)
target_link_libraries(lightdm-krkr-dbus-server Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::DBus ${LIGHTDM_QT_LIBRARIES})
