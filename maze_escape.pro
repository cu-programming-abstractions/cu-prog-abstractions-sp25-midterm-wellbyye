TEMPLATE = app
QT       += core
CONFIG   += console c++17 silent
CONFIG   -= app_bundle

# Source files
SOURCES += \
    src/main.cpp \
    src/maze.cpp \
    src/maze_solver.cpp

# Header files
HEADERS += \
    src/maze.h \
    src/maze_solver.h

# Add maze_samples folder to the project
OTHER_FILES += \
    maze_samples/medium.txt

# Set working directory to project root
QMAKE_CXXFLAGS += -std=c++17
QMAKE_CXXFLAGS += -Wall -Wextra

# Set the working directory to the project root
QMAKE_POST_LINK += $$quote(cd $$PWD)

# Make sure the maze_samples directory exists
!exists(maze_samples) {
    message("Creating maze_samples directory...")
    mkpath(maze_samples)
}

# Set default command line arguments
QMAKE_RUN_ARGS = maze_samples/medium.txt

# Add command line arguments for running the program
QMAKE_EXTRA_TARGETS += run
run.commands = $$OUT_PWD/$$TARGET maze_samples/medium.txt
run.depends = $$TARGET
run.target = run
run.CONFIG += recursive
run.recursive = true

# Add the run target to the build process
QMAKE_EXTRA_TARGETS += run
QMAKE_EXTRA_TARGETS += run
