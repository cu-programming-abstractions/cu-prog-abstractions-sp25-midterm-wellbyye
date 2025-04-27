# CS106B Take-Home Midterm Project – Maze Escape

## Project Overview
In this project, you will implement a recursive backtracking solver that finds a path from **S** (start) to **F** (finish) in an ASCII maze. The maze is represented by ASCII characters where:
- `#` represents walls
- ` ` (space) represents open paths
- `S` represents the start position
- `F` represents the finish position

## What You Need to Implement
You only need to modify the `dfs` function in `src/maze_solver.cpp`. The function should:
1. Use recursive backtracking to explore the maze
2. Mark visited cells to avoid cycles
3. Find a path from S to F
4. Build the path when the finish is found

## Files to Edit
- `src/maze_solver.cpp` - Implement the `dfs` function
- You do NOT need to modify any other files

## Implementation Steps
1. Open `src/maze_solver.cpp`
2. Find the `dfs` function
3. Follow the TODO comments in the function to implement the recursive backtracking algorithm
4. The function should return `true` if a path is found, `false` otherwise
5. When a path is found, add the current cell to `maze.path`

## Building and Running
1. Open the project in Qt Creator
2. Build the project (Ctrl+B or Build > Build Project)
3. Run the project (Ctrl+R or Build > Run)
4. The program will automatically use the sample maze file

## Testing
The program comes with a sample maze in `maze_samples/medium.txt`. When you run the program:
- If successful, it will print the maze with `.` characters marking your path
- If no path is found, it will print "No path!"
- If there's an error loading the maze, it will show an error message

## Tips
1. Start by understanding the maze representation
2. Make sure to mark cells as visited to avoid cycles
3. Try all four directions (up, right, down, left) at each step
4. Remember to build the path when you find the finish
5. Use the debug information printed by the program to help with debugging

## Grading
Your solution will be graded on:
1. Correctness - Does it find a valid path from S to F?
2. Efficiency - Does it avoid unnecessary exploration?
3. Code quality - Is your code clean and well-commented?

Good luck!
