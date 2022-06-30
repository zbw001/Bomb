cmake_minimum_required(VERSION 3.5)

project(Bomb VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES Bomb_zh_CN.ts)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g")

set(PROJECT_SOURCES
        main.cpp
        items/tile_map.cpp
        items/tile_map.h
        items/sprite.cpp
        items/sprite.h
        items/HP_bar.cpp
        items/HP_bar.h
        items/bomb.cpp
        items/bomb.h
        items/character.cpp
        items/character.h
        items/props.cpp
        items/props.h
        scenes/game.h
        scenes/game.cpp
        scenes/start.h
        scenes/start.cpp
        scenes/game.h
        scenes/game.cpp
        scenes/over.h
        scenes/over.cpp
        scenes/scene_manager.cpp
        scenes/scene_manager.h
        scenes/scene.h
        scenes/scene.cpp
        globals.h
        globals.cpp
        animation.h
        animation.cpp
        physics_manager.cpp
        physics_manager.h
        physics_object.h
        physics_object.cpp
        ${TS_FILES}
)

set(CMAKE_AUTORCC ON)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Bomb
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_add_resources(Bomb "assets"
        PREFIX "/"
        FILES
            assets/像素Silver.ttf
            assets/summer.png
            assets/character/mark.png
            assets/start_button.png
            assets/blocks/dirt.png
            assets/bomb/bomb.png
            assets/bomb/bomb2.png
            assets/bomb/bomb3.png
            assets/bomb/select_bomb.png
            assets/character/idle.png
            assets/character/down.png
            assets/character/slide.png
            assets/character/hp_background.png
            assets/character/hp_bar.png
            assets/start_button.png
            assets/bomb/explosion1/1_0.png
            assets/bomb/explosion1/1_1.png
            assets/bomb/explosion1/1_2.png
            assets/bomb/explosion1/1_3.png
            assets/bomb/explosion1/1_4.png
            assets/bomb/explosion1/1_5.png
            assets/bomb/explosion1/1_6.png
            assets/bomb/explosion1/1_7.png
            assets/bomb/explosion1/1_8.png
            assets/bomb/explosion1/1_9.png
            assets/bomb/explosion1/1_10.png
            assets/bomb/explosion1/1_11.png
            assets/bomb/explosion1/1_12.png
            assets/bomb/explosion1/1_13.png
            assets/bomb/explosion1/1_14.png
            assets/bomb/explosion1/1_15.png
            assets/bomb/explosion1/1_16.png
            assets/bomb/explosion1/1_17.png
            assets/bomb/explosion1/1_18.png
            assets/bomb/explosion1/1_19.png
            assets/bomb/explosion1/1_20.png
            assets/bomb/explosion1/1_21.png
            assets/bomb/explosion1/1_22.png
            assets/bomb/explosion1/1_23.png
            assets/bomb/explosion1/1_24.png
            assets/bomb/explosion1/1_25.png
            assets/bomb/explosion1/1_26.png
            assets/bomb/explosion1/1_27.png
            assets/bomb/explosion1/1_28.png
            assets/bomb/explosion1/1_29.png
            assets/bomb/explosion1/1_30.png
            assets/bomb/explosion1/1_31.png
            assets/bomb/explosion1/1_32.png
            assets/bomb/explosion1/1_33.png
            assets/bomb/explosion1/1_34.png
            assets/bomb/explosion1/1_35.png
            assets/bomb/explosion1/1_36.png
            assets/bomb/explosion1/1_37.png
            assets/bomb/explosion1/1_38.png
            assets/bomb/explosion1/1_39.png
            assets/bomb/explosion1/1_40.png
            assets/bomb/explosion1/1_41.png
            assets/bomb/explosion1/1_42.png
            assets/bomb/explosion1/1_43.png
            assets/bomb/explosion1/1_44.png
            assets/bomb/explosion1/1_45.png
            assets/bomb/explosion1/1_46.png
            assets/bomb/explosion1/1_47.png
            assets/bomb/explosion1/1_48.png
            assets/bomb/explosion1/1_49.png

    )
    
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Bomb APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Bomb SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Bomb
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Bomb PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Bomb PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Bomb)
endif()
