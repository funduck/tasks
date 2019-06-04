#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


int main() {

    std::queue<double> plan;
    int mazeSizeX, mazeSizeY;
    int X = 0, Y = 0;
    int x_end = 0, y_end = 0;
    std::vector<std::string> v;
    std::string first;
    std::getline(std::cin, first);
    mazeSizeX = first.length();

    v.push_back(first);

    for(int i = 1; i <mazeSizeX; i++){
        std::getline(std::cin, first);
        v.push_back(first);
    }

    mazeSizeY = mazeSizeX;

    char maze[mazeSizeX][mazeSizeY];//our map
    char mazeOut[mazeSizeX][mazeSizeY];//our map
    int visited[mazeSizeX][mazeSizeY];//points
    double path[mazeSizeX][mazeSizeY];//our way


    for (int y = 0; y < mazeSizeY; y++) {

        std::string buff = v[y];
        for (int x = 0; x != mazeSizeX; x++) {
            maze[x][y] = buff[x];
        }
    }

    //find start and end points
    for (int y = 0; y < mazeSizeY; y++) {

        for (int x = 0; x != mazeSizeX; x++) {
            visited[x][y] = 0;
            path[x][y] = -1;

            if (maze[x][y] == 's') {
                plan.push(x);
                plan.push(y);

            } else if (maze[0][y] == ' ') {
                x_end = 0;
                y_end = y;

            } else if (maze[x][0] == ' ') {
                x_end = x;
                y_end = 0;

            } else if (maze[mazeSizeX][y] == ' ') {
                x_end = mazeSizeX - 1;
                y_end = y;

            } else if (maze[x][mazeSizeY - 1] == ' ') {
                x_end = x;
                y_end = v.size() - 2;
            }
        }
    }
    maze[x_end][y_end] = 'X';
    for (int i = 0; i < mazeSizeX; i++) {
        for (int j = 0; j < mazeSizeY; j++) {
            mazeOut[j][i] = maze[j][i];
        }
    }




    while (!plan.empty()) {

        X = plan.front();
        plan.pop();
        Y = plan.front();
        plan.pop();

        if ((X + 1) < mazeSizeX && (X + 1) >= 0 && !visited[X + 1][Y] &&
            (maze[X + 1][Y] == ' ' || maze[X + 1][Y] == 'X')) {
            path[X + 1][Y] = path[X][Y] + 1;
            plan.push(X + 1);
            plan.push(Y);
        }
        if ((X - 1) < mazeSizeX && (X - 1) >= 0 && !visited[X - 1][Y] &&
            (maze[X - 1][Y] == ' ' || maze[X - 1][Y] == 'X')) {
            path[X - 1][Y] = path[X][Y] + 1;
            plan.push(X - 1);
            plan.push(Y);
        }
        if ((Y + 1) < mazeSizeY && (Y + 1) >= 0 && !visited[X][Y + 1] &&
            (maze[X][Y + 1] == ' ' || maze[X][Y + 1] == 'X')) {
            path[X][Y + 1] = path[X][Y] + 1;
            plan.push(X);
            plan.push(Y + 1);
        }
        if ((Y - 1) < mazeSizeY && (Y - 1) >= 0 && !visited[X][Y - 1] &&
            (maze[X][Y - 1] == ' ' || maze[X][Y - 1] == 'X')) {
            path[X][Y - 1] = path[X][Y] + 1;
            plan.push(X);
            plan.push(Y - 1);
        }
        ////////////////////////IF SAND////////////////////////////////////
        if ((X + 1) < mazeSizeX && (X + 1) >= 0 && !visited[X + 1][Y] &&
            (maze[X + 1][Y] == '.')) {
            maze[X + 1][Y] = ' ';
            plan.push(X);
            plan.push(Y);
        }
        if ((X - 1) < mazeSizeX && (X - 1) >= 0 && !visited[X - 1][Y] &&
            (maze[X - 1][Y] == '.')) {
            maze[X - 1][Y] = ' ';
            plan.push(X);
            plan.push(Y);
        }
        if ((Y + 1) < mazeSizeY && (Y + 1) >= 0 && !visited[X][Y + 1] &&
            (maze[X][Y + 1] == '.')) {
            maze[X][Y + 1] = ' ';
            plan.push(X);
            plan.push(Y);
        }
        if ((Y - 1) < mazeSizeY && (Y - 1) >= 0 && !visited[X][Y - 1] &&
            (maze[X][Y - 1] == '.')) {
            maze[X][Y - 1] = ' ';
            plan.push(X);
            plan.push(Y);
        }

        if (maze[X][Y] == '.') {
            visited[X][Y] = 2;
        } else {
            visited[X][Y] = 1;
        }

    }


    //create a way
    if (!visited[x_end][y_end]) {
        return 1;
    } else {
        X = x_end;
        Y = y_end;
        mazeOut[X][Y] = '*';
        while (path[X][Y] != 0) {
            if ((X - 1) >= 0 && (X - 1) < mazeSizeX && (path[X - 1][Y] == path[X][Y] - 1)) {
                X = X - 1;
                mazeOut[X][Y] = '*';
            } else if ((X + 1) >= 0 && (X + 1) < mazeSizeX && (path[X + 1][Y] == path[X][Y] - 1)) {
                X = X + 1;
                mazeOut[X][Y] = '*';
            } else if ((Y - 1) >= 0 && (Y - 1) < mazeSizeY && (path[X][Y - 1] == path[X][Y] - 1)) {
                Y = Y - 1;
                mazeOut[X][Y] = '*';
            } else if ((Y + 1) >= 0 && (Y + 1) < mazeSizeY && (path[X][Y + 1] == path[X][Y] - 1)) {
                Y = Y + 1;
                mazeOut[X][Y] = '*';
            }
        }

        for (int i = 0; i < mazeSizeX; i++) {
            for (int j = 0; j < mazeSizeY; j++) {
                std::cout << mazeOut[j][i];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}