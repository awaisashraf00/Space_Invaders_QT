cmake_minimum_required(VERSION 3.16)

project(Qt_Game VERSION 1.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Qml
    Quick
    QuickControls2
)

qt_standard_project_setup(REQUIRES 6.8)


add_executable(Qt_Game
    src/main.cpp
    src/player.cpp
    src/bullets.cpp
    src/control.cpp
    header_files/player.h
    header_files/control.h
    header_files/bullets.h
)

target_include_directories(Qt_Game PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/header_files
)

# Put executable in build/bin/
set_target_properties(Qt_Game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

qt_add_qml_module(Qt_Game
    URI Qt_Game
    VERSION 1.0

    OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/qml/Qt_Game"

    QML_FILES
        qml/Main.qml
        qml/Bullet.qml
)

target_link_libraries(Qt_Game PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
)