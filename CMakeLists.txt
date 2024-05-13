cmake_minimum_required(VERSION 3.26)
project(Snake_game)

set(CMAKE_PREFIX_PATH "/Users/sagot/Qt/6.6.1/macos")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)
qt_standard_project_setup()

qt_add_executable(Snake_game
        food.cpp
        food.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        snake.cpp
        snake.h
        Pepper.cpp
        Pepper.h
        ItemsContainer.cpp
        ItemsContainer.h
        SnakeAI.cpp
        SnakeAI.h
        SnakePart.cpp
        SnakePart.h
        menuwindow.cpp
        menuwindow.h
        menuwindow.ui
        Stone.cpp
        Stone.h
        leaderboardwindow.cpp
        leaderboardwindow.h
        leaderboardwindow.ui)
target_link_libraries(Snake_game PRIVATE Qt6::Widgets Qt6::Sql)

set_target_properties(Snake_game PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)