cmake_minimum_required(VERSION 3.16)
project(QtVehicle_QTableView_Theme_Model_Year LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtVehicle_QTableView_Theme_Model_Year
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.hpp
    src/MainWindow.ui
)

target_link_libraries(QtVehicle_QTableView_Theme_Model_Year PRIVATE Qt6::Widgets)
