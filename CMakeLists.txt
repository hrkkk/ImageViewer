cmake_minimum_required(VERSION 3.5)

project(ImageViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGLWidgets)

# libheif库
include_directories("./3rdparty/libheif/include/")
link_directories("./3rdparty/libheif/lib/")
# libde265库
include_directories("./3rdparty/libde265/include/")
link_directories("./3rdparty/libde265/lib/")
# libx265库
include_directories("./3rdparty/libx265/include/")
link_directories("./3rdparty/libx265/lib/")
# libjpeg库
include_directories("./3rdparty/libjpeg/libjpeg-turbo64/include/")
link_directories("./3rdparty/libjpeg/libjpeg-turbo64/lib/")
# TinyEXIF库
include_directories("./3rdparty/TinyEXIF/")
# libraw库
include_directories("./3rdparty/libraw/libraw/")
link_directories("./3rdparty/libraw/lib/")

add_definitions(-DTINYEXIF_NO_XMP_SUPPORT)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        CustomOpenGLWidget.h CustomOpenGLWidget.cpp
        CustomResizableWidget.cpp CustomResizableWidget.h
        ImageReader.h ImageReader.cpp
        ./3rdparty/TinyEXIF/TinyEXIF.cpp ./3rdparty/TinyEXIF/TinyEXIF.h
        Utils.cpp Utils.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ImageViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
        DetailInfoDialog.h DetailInfoDialog.cpp DetailInfoDialog.ui
        ImageItem.h ImageItem.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ImageViewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ImageViewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ImageViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ImageViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets heif.lib libx265.lib de265.lib jpeg.lib libraw.lib)
target_link_libraries(ImageViewer PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ImageViewer)
endif()
set_target_properties(ImageViewer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ImageViewer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ImageViewer)
endif()
