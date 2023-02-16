#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAZE_WIDTH = 11;
const int MAZE_HEIGHT = 11;
const char WALL = '#';
const char PATH = ' ';
const char DOOR = 'D';
const char TREASURE = 'T';

vector<vector<char>> generate_maze(int x, int y, int door[], int treasure[]);


vector<vector<char>> generate_maze(int x, int y, int door[], int treasure[]) {
    // Initialize the maze with walls
    vector<vector<char>> maze(MAZE_HEIGHT, vector<char>(MAZE_WIDTH, WALL));

    // Set the starting position
    maze[y][x] = PATH;

    // Define possible directions
    int directions[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};

    // Shuffle the directions
    srand(time(nullptr));
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp1 = directions[i][0];
        int temp2 = directions[i][1];
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = temp1;
        directions[j][1] = temp2;
    }

    // Generate the maze using a depth-first search algorithm
    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int new_x = x + dx;
        int new_y = y + dy;

        // Check if the new position is valid
        if (new_x >= 1 && new_x < MAZE_WIDTH - 1 &&
            new_y >= 1 && new_y < MAZE_HEIGHT - 1 &&
            maze[new_y][new_x] == WALL) {
            // Remove the wall and the path between the old and new positions
            maze[y + dy/2][x + dx/2] = PATH;
            maze[new_y][new_x] = PATH;

            // Recursively call the function for the new position
            generate_maze(new_x, new_y, door, treasure);
        }
    }

    // Place the door and treasure chest in the maze
    maze[door[1]][door[0]] = DOOR;
    maze[treasure[1]][treasure[0]] = TREASURE;

    return maze;
}


int maze_test_main(int argc, char* argv[], char* env[]) {
    // Generate the maze
    int door[2] = {MAZE_WIDTH - 2, MAZE_HEIGHT - 2};
    int treasure[2] = {1, 1};
    vector<vector<char>> maze = generate_maze(1, 1, door, treasure);

    // Print the maze
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}