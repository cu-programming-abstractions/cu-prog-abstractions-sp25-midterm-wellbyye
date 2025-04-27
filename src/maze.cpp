#include "maze.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

bool Maze::loadFromFile(const string& filename) {
    try {
        if (!filesystem::exists(filename)) {
            cerr << "Error: File '" << filename << "' does not exist.\n";
            cerr << "Current working directory: " << filesystem::current_path() << "\n";
            return false;
        }

        ifstream infile(filename);
        if (!infile) {
            cerr << "Error: Could not open file '" << filename << "' for reading.\n";
            return false;
        }

        grid.clear();
        string line;
        int r = 0;
        while (getline(infile, line)) {
            grid.push_back(line);
            for (int c = 0; c < static_cast<int>(line.size()); ++c) {
                if (!parseChar(line[c], r, c)) {
                    cerr << "Error parsing character at position (" << r << "," << c << ")\n";
                    return false;
                }
            }
            ++r;
        }

        if (start.row == -1) {
            cerr << "Error: No start position 'S' found in maze.\n";
            return false;
        }
        if (finish.row == -1) {
            cerr << "Error: No finish position 'F' found in maze.\n";
            return false;
        }

        cerr << "Successfully loaded maze:\n";
        cerr << "  Size: " << grid.size() << "x" << (grid.empty() ? 0 : grid[0].size()) << "\n";
        cerr << "  Start: (" << start.row << "," << start.col << ")\n";
        cerr << "  Finish: (" << finish.row << "," << finish.col << ")\n";

        return true;
    } catch (const exception& e) {
        cerr << "Error loading maze: " << e.what() << "\n";
        return false;
    }
}

bool Maze::parseChar(char ch, int r, int c) {
    switch (ch) {
        case 'S': start = { r, c }; break;
        case 'F': finish = { r, c }; break;
        case '#': case ' ': case '.': break;
        default:
            cerr << "Invalid character '" << ch << "' in maze file.\n";
            return false;
    }
    return true;
}

bool Maze::inBounds(int r, int c) const {
    return r >= 0 && r < static_cast<int>(grid.size())
        && c >= 0 && c < static_cast<int>(grid[r].size());
}

bool Maze::isWall(int r, int c) const {
    return grid[r][c] == '#';
}

void Maze::printWithPath(ostream& out) const {
    vector<string> copy = grid;
    for (const Cell& cell : path) {
        if (!(cell == start) && !(cell == finish)) {
            copy[cell.row][cell.col] = '.';
        }
    }
    for (const string& line : copy) {
        out << line << '\n';
    }
}
