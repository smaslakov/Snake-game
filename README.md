# Snake Game

This repository contains a C++ implementation of a snake game, inspired by the popular game [Slither.io](http://slither.io/), developed using the Qt framework.

## Features

- Classic Snake gameplay with additional features
- Multiple levels and difficulties
- High score tracking and leaderboard

## Installation

To build and run the project, follow these steps:

1. **Clone the repository:**

   ```sh
   git clone https://github.com/smaslakov/Snake-game.git
   cd Snake-game
   ```
2. **Ensure you have Qt installed:**
Make sure you have Qt 6.6.1 installed on your system. You can download it from Qt's official website.

3. **Build the project:**
 ```sh
mkdir build
cd build
cmake ..
make
```
4. **To run the game, navigate to the build directory and execute the generated binary:**
```sh
./Snake_game
```

## File Structure

-main.cpp: The entry point of the application.
-CMakeLists.txt: CMake configuration file.
-food.cpp, food.h: Implementation and header for the food entity.
-mainwindow.cpp, mainwindow.h, mainwindow.ui: Main window implementation.
-menuwindow.cpp, menuwindow.h, menuwindow.ui: Menu window implementation.
-snake.cpp, snake.h: Implementation and header for the snake entity.
-snakeAI.cpp, snakeAI.h: Implementation and header for the bot entity.
Pepper.cpp, Pepper.h, ItemsContainer.cpp, ItemsContainer.h, SnakeAI.cpp, SnakeAI.h, SnakePart.cpp, SnakePart.h, Stone.cpp, Stone.h, leaderboardwindow.cpp, leaderboardwindow.h, leaderboardwindow.ui, database.cpp, database.h: Other game components and utilities.
## Screenshots

### Main Menu
![Main Menu](https://github.com/user-attachments/assets/54e81dbe-ea3b-4ca3-bea7-9f858795b7b4)

### In-Game
![In-Game](https://github.com/user-attachments/assets/8b4792e6-e566-4ab0-bea1-89f153af4ada)

### LeaderBoard
![LeaderBoard](https://github.com/user-attachments/assets/e3137ce2-3349-41fd-9c54-38f0932a3384)
