#pragma once
#include <vector>
#include <string>
#include <ostream>

using namespace std;

struct Cell {
    int row;
    int col;
    bool operator==(const Cell& other) const {
        return row == other.row && col == other.col;
    }
};

class Maze {
public:
    bool loadFromFile(const string& filename);
    bool inBounds(int r, int c) const;
    bool isWall(int r, int c) const;
    void printWithPath(ostream& out) const;

    vector<string> grid;
    Cell start { -1, -1 };
    Cell finish { -1, -1 };
    vector<Cell> path;

private:
    bool parseChar(char ch, int r, int c);
};
