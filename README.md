Space Invaders — Qt/QML

A simple Space Invaders-style game built using C++ and Qt/QML.

This project is focused on learning how to combine a C++ backend with a QML frontend, handle user input, communicate between C++ and QML, and structure a small interactive game using Qt.

Features

* Player-controlled spaceship
* Keyboard-based movement
* QML-based game interface
* C++ backend integration
* Qt signals and slots
* C++ properties exposed to QML
* QML event handling
* Object initialization using Component.onCompleted
* CMake-based project configuration

Technologies Used

* C++
* Qt 6
* QML
* Qt Quick
* Qt Quick Controls
* CMake

Project Structure

Space_Invaders_QT/
├── CMakeLists.txt
├── qml/
│   └── Main.qml
├── src/
│   └── ...
└── README.md

The exact structure may change as the project develops.

How It Works

The project uses QML for the graphical interface and C++ for the game logic.

QML

QML is responsible for:

* Creating the game window
* Displaying game objects
* Positioning UI elements
* Handling keyboard/mouse input
* Connecting UI events to application logic

C++

C++ is used for:

* Game logic
* Player state
* Properties and setters/getters
* Signals and slots
* Communication between the application logic and QML

The general architecture is:

        ┌────────────────────┐
        │        QML         │
        │   User Interface   │
        └─────────┬──────────┘
                  │
            Signals / Calls
                  │
                  ▼
        ┌────────────────────┐
        │        C++         │
        │    Game Logic      │
        └─────────┬──────────┘
                  │
             Properties
                  │
                  ▼
        ┌────────────────────┐
        │        QML         │
        │  Updated Display   │
        └────────────────────┘

Building the Project

Make sure Qt 6 and CMake are installed.

Clone the repository:

git clone git@github.com:awaisashraf00/Space_Invaders_QT.git
cd Space_Invaders_QT

Create a build directory:

mkdir build
cd build

Configure the project:

cmake ..

Build:

cmake --build .

Run the generated application.

Learning Goals

This project is also a learning exercise for understanding Qt/QML development.

Some of the main concepts explored are:

* QObject
* QML objects and components
* C++ classes exposed to QML
* Q_PROPERTY
* Getters and setters
* Signals and slots
* QML signal handlers
* Component.onCompleted
* Keyboard focus
* CMake and Qt’s QML modules
* Communication between C++ and QML

Future Improvements

Planned improvements include:

* Enemy spaceship generation
* Shooting mechanics
* Collision detection
* Score system
* Lives/health system
* Increasing difficulty
* Multiple levels
* Sound effects
* Animations
* Game-over and restart functionality

Purpose

The main purpose of this project is to build a small game while developing a deeper understanding of Qt, QML, C++, CMake, and C++/QML communication.

It is being developed incrementally, with new game mechanics and Qt/QML concepts added as the project progresses.

Author

AwAis goat

GitHub: awaisashraf00
