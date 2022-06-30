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
            assets/bomb/pass.png
            assets/summer.png
            assets/character/mark.png
            assets/start_button.png
            assets/blocks/dirt.png
            assets/bomb/bomb.png
            assets/bomb/bomb2.png
            assets/bomb/bomb3.png
            assets/bomb/select_bomb.png
            assets/character/idle.png
            assets/character/hurt.png
            assets/character/walk0.png
            assets/character/walk1.png
            assets/character/walk2.png
            assets/character/walk3.png
            assets/character/walk4.png
            assets/character/walk5.png
            assets/character/walk6.png
            assets/character/walk7.png
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
            assets/bomb/explosion2/frame0000.png
            assets/bomb/explosion2/frame0001.png
            assets/bomb/explosion2/frame0002.png
            assets/bomb/explosion2/frame0003.png
            assets/bomb/explosion2/frame0004.png
            assets/bomb/explosion2/frame0005.png
            assets/bomb/explosion2/frame0006.png
            assets/bomb/explosion2/frame0007.png
            assets/bomb/explosion2/frame0008.png
            assets/bomb/explosion2/frame0009.png
            assets/bomb/explosion2/frame0010.png
            assets/bomb/explosion2/frame0011.png
            assets/bomb/explosion2/frame0012.png
            assets/bomb/explosion2/frame0013.png
            assets/bomb/explosion2/frame0014.png
            assets/bomb/explosion2/frame0015.png
            assets/bomb/explosion2/frame0016.png
            assets/bomb/explosion2/frame0017.png
            assets/bomb/explosion2/frame0018.png
            assets/bomb/explosion2/frame0019.png
            assets/bomb/explosion2/frame0020.png
            assets/bomb/explosion2/frame0021.png
            assets/bomb/explosion2/frame0022.png
            assets/bomb/explosion2/frame0023.png
            assets/bomb/explosion2/frame0024.png
            assets/bomb/explosion2/frame0025.png
            assets/bomb/explosion2/frame0026.png
            assets/bomb/explosion2/frame0027.png
            assets/bomb/explosion2/frame0028.png
            assets/bomb/explosion2/frame0029.png
            assets/bomb/explosion2/frame0030.png
            assets/bomb/explosion2/frame0031.png
            assets/bomb/explosion2/frame0032.png
            assets/bomb/explosion2/frame0033.png
            assets/bomb/explosion2/frame0034.png
            assets/bomb/explosion2/frame0035.png
            assets/bomb/explosion2/frame0036.png
            assets/bomb/explosion2/frame0037.png
            assets/bomb/explosion2/frame0038.png
            assets/bomb/explosion2/frame0039.png
            assets/bomb/explosion2/frame0040.png
            assets/bomb/explosion2/frame0041.png
            assets/bomb/explosion2/frame0042.png
            assets/bomb/explosion2/frame0043.png
            assets/bomb/explosion2/frame0044.png
            assets/bomb/explosion2/frame0045.png
            assets/bomb/explosion2/frame0046.png
            assets/bomb/explosion2/frame0047.png
            assets/bomb/explosion2/frame0048.png
            assets/bomb/explosion2/frame0049.png
            assets/bomb/explosion2/frame0050.png
            assets/bomb/explosion2/frame0051.png
            assets/bomb/explosion2/frame0052.png
            assets/bomb/explosion2/frame0053.png
            assets/bomb/explosion2/frame0054.png
            assets/bomb/explosion2/frame0055.png
            assets/bomb/explosion2/frame0056.png
            assets/bomb/explosion2/frame0057.png
            assets/bomb/explosion2/frame0058.png
            assets/bomb/explosion2/frame0059.png
            assets/bomb/explosion2/frame0060.png
            assets/bomb/explosion2/frame0061.png
            assets/bomb/explosion2/frame0062.png
            assets/bomb/explosion2/frame0063.png
            assets/bomb/explosion2/frame0064.png
            assets/bomb/explosion2/frame0065.png
            assets/bomb/explosion2/frame0066.png
            assets/bomb/explosion2/frame0067.png
            assets/bomb/explosion2/frame0068.png
            assets/bomb/explosion2/frame0069.png
            assets/bomb/explosion2/frame0070.png
            assets/bomb/explosion2/frame0071.png
            assets/bomb/explosion2/frame0072.png
            assets/bomb/explosion2/frame0073.png
            assets/bomb/explosion2/frame0074.png
            assets/bomb/explosion2/frame0075.png
            assets/bomb/explosion2/frame0076.png
            assets/bomb/explosion2/frame0077.png
            assets/bomb/explosion2/frame0078.png
            assets/bomb/explosion2/frame0079.png
            assets/bomb/explosion2/frame0080.png
            assets/bomb/explosion2/frame0081.png
            assets/bomb/explosion3/frame0000.png
            assets/bomb/explosion3/frame0001.png
            assets/bomb/explosion3/frame0002.png
            assets/bomb/explosion3/frame0003.png
            assets/bomb/explosion3/frame0004.png
            assets/bomb/explosion3/frame0005.png
            assets/bomb/explosion3/frame0006.png
            assets/bomb/explosion3/frame0007.png
            assets/bomb/explosion3/frame0008.png
            assets/bomb/explosion3/frame0009.png
            assets/bomb/explosion3/frame0010.png
            assets/bomb/explosion3/frame0011.png
            assets/bomb/explosion3/frame0012.png
            assets/bomb/explosion3/frame0013.png
            assets/bomb/explosion3/frame0014.png
            assets/bomb/explosion3/frame0015.png
            assets/bomb/explosion3/frame0016.png
            assets/bomb/explosion3/frame0017.png
            assets/bomb/explosion3/frame0018.png
            assets/bomb/explosion3/frame0019.png
            assets/bomb/explosion3/frame0020.png
            assets/bomb/explosion3/frame0021.png
            assets/bomb/explosion3/frame0022.png
            assets/bomb/explosion3/frame0023.png
            assets/bomb/explosion3/frame0024.png
            assets/bomb/explosion3/frame0025.png
            assets/bomb/explosion3/frame0026.png
            assets/bomb/explosion3/frame0027.png
            assets/bomb/explosion3/frame0028.png
            assets/bomb/explosion3/frame0029.png
            assets/bomb/explosion3/frame0030.png
            assets/bomb/explosion3/frame0031.png
            assets/bomb/explosion3/frame0032.png
            assets/bomb/explosion3/frame0033.png
            assets/bomb/explosion3/frame0034.png
            assets/bomb/explosion3/frame0035.png
            assets/bomb/explosion3/frame0036.png
            assets/bomb/explosion3/frame0037.png
            assets/bomb/explosion3/frame0038.png
            assets/bomb/explosion3/frame0039.png
            assets/bomb/explosion3/frame0040.png
            assets/bomb/explosion3/frame0041.png
            assets/bomb/explosion3/frame0042.png
            assets/bomb/explosion3/frame0043.png
            assets/bomb/explosion3/frame0044.png
            assets/bomb/explosion3/frame0045.png
            assets/bomb/explosion3/frame0046.png
            assets/bomb/explosion3/frame0047.png
            assets/bomb/explosion3/frame0048.png
            assets/bomb/explosion3/frame0049.png
            assets/bomb/explosion3/frame0050.png
            assets/bomb/explosion3/frame0051.png
            assets/bomb/explosion3/frame0052.png
            assets/bomb/explosion3/frame0053.png
            assets/bomb/explosion3/frame0054.png
            assets/bomb/explosion3/frame0055.png
            assets/bomb/explosion3/frame0056.png
            assets/bomb/explosion3/frame0057.png
            assets/bomb/explosion3/frame0058.png
            assets/bomb/explosion3/frame0059.png
            assets/bomb/explosion3/frame0060.png
            assets/bomb/explosion3/frame0061.png
            assets/bomb/explosion3/frame0062.png
            assets/bomb/explosion3/frame0063.png
            assets/bomb/explosion3/frame0064.png
            assets/bomb/explosion3/frame0065.png
            assets/bomb/explosion3/frame0066.png
            assets/bomb/explosion3/frame0067.png
            assets/bomb/explosion3/frame0068.png
            assets/bomb/explosion3/frame0069.png
            assets/bomb/explosion3/frame0070.png
            assets/blocks/dt1.png
            assets/blocks/dt2.png
            assets/blocks/dt3.png
            assets/blocks/dt4.png
            assets/blocks/dt5.png
            assets/blocks/dt6.png
            assets/blocks/dt7.png
            assets/blocks/dt8.png
            assets/blocks/dt9.png
            assets/blocks/dt10.png
            assets/blocks/dt11.png
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
