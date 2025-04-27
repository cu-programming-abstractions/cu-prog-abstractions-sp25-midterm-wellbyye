#include "maze.h"
#include "maze_solver.h"
#include <iostream>
#include <filesystem>

using namespace std;

int main(int argc, char* argv[]) {
    filesystem::path projectRoot = filesystem::current_path();
    while (!filesystem::exists(projectRoot / "maze_escape.pro")) {
        projectRoot = projectRoot.parent_path();
        if (projectRoot.empty()) {
            cerr << "Error: Could not find project root directory.\n";
            return 1;
        }
    }

    const char* default_maze = "maze_samples/medium.txt";
    const char* maze_file = (argc > 1) ? argv[1] : default_maze;
    filesystem::path maze_path = projectRoot / maze_file;

    Maze maze;
    if (!maze.loadFromFile(maze_path.string())) {
        cerr << "Could not load maze file.\n";
        return 1;
    }

    MazeSolver solver;
    if (solver.solveDFS(maze)) {
        maze.printWithPath(cout);
    } else {
        cout << "No path!\n";
    }
    return 0;
}
