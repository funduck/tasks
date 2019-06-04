#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#include "func.h"

const int BUFFSIZE = 2048;


int main() {

    std::queue<int> plan;
    int X = 0, Y = 0;
    int x_start = 0, y_start = 0, x_end = 0, y_end = 0;
    std::vector<std::string> v;
    char *filename = "test.txt";
    func foo;

    foo.GetMap(filename, v);
//    for(int i = 0; i != v.size(); i++){
//        std::cout << v[i] << std::endl;
//    }

    std::string yLen = v[0];
    int mazeSizeY = v.size();
    int mazeSizeX = yLen.size();

    char maze[mazeSizeX][mazeSizeY];//our map
    int visited[mazeSizeX][mazeSizeY];//points
    double path[mazeSizeX][mazeSizeY];//our map of ways


    for (int y = 0; y < mazeSizeY - 1; y++) {
        std::string buff = v[y];

        for (int x = 0; x != mazeSizeX; x++) {
            maze[x][y] = buff[x];
//            std::cout << maze[x][y];

        }
//        std::cout << std::endl;
    }

    //поиск нач и конеч точек
    for (int y = 0; y < mazeSizeY - 1; y++) {

        for (int x = 0; x != mazeSizeX; x++) {
            visited[x][y] = 0;
            path[x][y] = -1;

            if (maze[x][y] == 's') {
                x_start = x;
                y_start = y;
                plan.push(x);
                plan.push(y);
            } else if (maze[0][y] == ' ') {
                x_end = 0;
                y_end = y;
            } else if (maze[x][0] == ' ') {
                x_end = x;
                y_end = 0;
            } else if (maze[mazeSizeX - 1][y] == ' ') {
                x_end = yLen.size() - 1;
                y_end = y;
            } else if (maze[x][mazeSizeY - 2] == ' ') {
                x_end = x;
                y_end = v.size() - 2;
            }
        }
    }
//    for (int i = 0; i < mazeSizeX; i++) {
//        for (int j = 0; j < mazeSizeY - 1; j++) {
//            std::cout << visited[i][j];
//        }
//        std::cout << std::endl;
//    }
//    for (int i = 0; i < mazeSizeX; i++) {
//        for (int j = 0; j < mazeSizeY - 1; j++) {
//            std::cout << path[i][j];
//        }
//        std::cout << std::endl;
//    }

    maze[x_end][y_end] = 'X';
    std::cout << std::endl;
    for (int y = 0; y < mazeSizeY - 1; y++) {
        for (int x = 0; x != mazeSizeX; x++) {
            std::cout << maze[x][y];

        }
        std::cout << std::endl;
    }
//    std:: cout << "x " << "y" << std::endl;
//    std::cout << x_end << " " << y_end << std::endl <<  x_start << " " << y_start << std::endl;


    while (!plan.empty()) {
        X = plan.front();
        plan.pop();
        Y = plan.front();
        plan.pop();
        {
            if(visited[X][Y]){
                if ((X + 1) < mazeSizeX && (X + 1) >= 0 && !visited[X + 1][Y] &&
                    (maze[X + 1][Y] == ' ' || maze[X + 1][Y] == 'X') && (path[X + 1][Y] < path[X][Y] + 1) ) {
                    path[X + 1][Y] = path[X][Y] + 1;
                    plan.push(X + 1);
                    plan.push(Y);
                }
                if ((X - 1) < mazeSizeX && (X - 1) >= 0 && !visited[X - 1][Y] &&
                    (maze[X - 1][Y] == ' ' || maze[X - 1][Y] == 'X')&& (path[X - 1][Y] < path[X][Y] + 1)) {
                    path[X - 1][Y] = path[X][Y] + 1;
                    plan.push(X - 1);
                    plan.push(Y);
                }
                if ((Y + 1) < mazeSizeY && (Y + 1) >= 0 && !visited[X][Y + 1] &&
                    (maze[X][Y + 1] == ' ' || maze[X][Y + 1] == 'X')&& (path[X][Y + 1] < path[X][Y] + 1)) {
                    path[X][Y + 1] = path[X][Y] + 1;
                    plan.push(X);
                    plan.push(Y + 1);
                }
                if ((Y - 1) < mazeSizeY && (Y - 1) >= 0 && !visited[X][Y - 1] &&
                    (maze[X][Y - 1] == ' ' || maze[X][Y - 1] == 'X')&& (path[X][Y - 1] < path[X][Y] + 1)) {
                    path[X][Y - 1] = path[X][Y] + 1;
                    plan.push(X);
                    plan.push(Y - 1);
                }
                if ((X + 1) < mazeSizeX && (X + 1) >= 0 && !visited[X + 1][Y] &&
                    (maze[X + 1][Y] == '.' )&& (path[X + 1][Y] < path[X][Y] + 1)) {
                    path[X + 1][Y] = path[X][Y] + 0.5;
                    plan.push(X + 1);
                    plan.push(Y);
                }
                if ((X - 1) < mazeSizeX && (X - 1) >= 0 && !visited[X - 1][Y] &&
                    (maze[X - 1][Y] == '.')&& (path[X - 1][Y] < path[X][Y] + 1)) {
                    path[X - 1][Y] = path[X][Y] + 0.5;
                    plan.push(X - 1);
                    plan.push(Y);
                }
                if ((Y + 1) < mazeSizeY && (Y + 1) >= 0 && !visited[X][Y + 1] &&
                    (maze[X][Y + 1] == '.')&& (path[X][Y + 1] < path[X][Y] + 1)) {
                    path[X][Y + 1] = path[X][Y] + 0.5;
                    plan.push(X);
                    plan.push(Y + 1);
                }
                if ((Y - 1) < mazeSizeY && (Y - 1) >= 0 && !visited[X][Y - 1] &&
                    (maze[X][Y - 1] == '.')&& (path[X][Y + 1] < path[X][Y] + 1)) {
                    path[X][Y - 1] = path[X][Y] + 0.5;
                    plan.push(X);
                    plan.push(Y - 1);
                }
            }
            if (!visited[X][Y]) {
                if ((X + 1) < mazeSizeX && (X + 1) >= 0 && !visited[X + 1][Y] &&
                    (maze[X + 1][Y] == ' ' || maze[X + 1][Y] == 'X') && (path[X + 1][Y] < path[X][Y] + 1) ) {
                    path[X + 1][Y] = path[X][Y] + 1;
                    plan.push(X + 1);
                    plan.push(Y);
                }
                if ((X - 1) < mazeSizeX && (X - 1) >= 0 && !visited[X - 1][Y] &&
                    (maze[X - 1][Y] == ' ' || maze[X - 1][Y] == 'X')&& (path[X - 1][Y] < path[X][Y] + 1)) {
                    path[X - 1][Y] = path[X][Y] + 1;
                    plan.push(X - 1);
                    plan.push(Y);
                }
                if ((Y + 1) < mazeSizeY && (Y + 1) >= 0 && !visited[X][Y + 1] &&
                    (maze[X][Y + 1] == ' ' || maze[X][Y + 1] == 'X')&& (path[X][Y + 1] < path[X][Y] + 1)) {
                    path[X][Y + 1] = path[X][Y] + 1;
                    plan.push(X);
                    plan.push(Y + 1);
                }
                if ((Y - 1) < mazeSizeY && (Y - 1) >= 0 && !visited[X][Y - 1] &&
                    (maze[X][Y - 1] == ' ' || maze[X][Y - 1] == 'X')&& (path[X][Y - 1] < path[X][Y] + 1)) {
                    path[X][Y - 1] = path[X][Y] + 1;
                    plan.push(X);
                    plan.push(Y - 1);
                }
                if ((X + 1) < mazeSizeX && (X + 1) >= 0 && !visited[X + 1][Y] &&
                    (maze[X + 1][Y] == '.' )&& (path[X + 1][Y] < path[X][Y] + 1)) {
                    path[X + 1][Y] = path[X][Y] + 0.5;
                    plan.push(X + 1);
                    plan.push(Y);
                }
                if ((X - 1) < mazeSizeX && (X - 1) >= 0 && !visited[X - 1][Y] &&
                    (maze[X - 1][Y] == '.')&& (path[X - 1][Y] < path[X][Y] + 1)) {
                    path[X - 1][Y] = path[X][Y] + 0.5;
                    plan.push(X - 1);
                    plan.push(Y);
                }
                if ((Y + 1) < mazeSizeY && (Y + 1) >= 0 && !visited[X][Y + 1] &&
                    (maze[X][Y + 1] == '.')&& (path[X][Y + 1] < path[X][Y] + 1)) {
                    path[X][Y + 1] = path[X][Y] + 0.5;
                    plan.push(X);
                    plan.push(Y + 1);
                }
                if ((Y - 1) < mazeSizeY && (Y - 1) >= 0 && !visited[X][Y - 1] &&
                    (maze[X][Y - 1] == '.')&& (path[X][Y + 1] < path[X][Y] + 1)) {
                    path[X][Y - 1] = path[X][Y] + 0.5;
                    plan.push(X);
                    plan.push(Y - 1);
                }
                if (maze[X][Y] == '.') {
                    visited[X][Y] = 1;
                } else {
                    visited[X][Y] = 2;
                }
            }
        }

    }
    for (int i = 0; i < mazeSizeX; i++) {
        for (int j = 0; j < mazeSizeY - 1; j++) {
            std::cout << visited[j][i];
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < mazeSizeX; i++) {
        for (int j = 0; j < mazeSizeY - 1; j++) {
            std::cout << path[j][i];
        }
        std::cout << std::endl;
    }


    //create a way
    if (!visited[x_end][y_end]) {
        return 1;
    } else {
        X = x_end;
        Y = y_end;
        maze[X][Y] = '*';
        while (path[X][Y] != 0) {
            if ((X - 1) >= 0 && (X - 1) < mazeSizeX && (path[X - 1][Y] == path[X][Y] - 1)) {
                X = X - 1;
                maze[X][Y] = '*';
            } else if ((X + 1) >= 0 && (X + 1) < mazeSizeX && (path[X + 1][Y] == path[X][Y] - 1)) {
                X = X + 1;
                maze[X][Y] = '*';
            } else if ((Y - 1) >= 0 && (Y - 1) < mazeSizeY && (path[X][Y - 1] == path[X][Y] - 1)) {
                Y = Y - 1;
                maze[X][Y] = '*';
            } else if ((Y + 1) >= 0 && (Y + 1) < mazeSizeY && (path[X][Y + 1] == path[X][Y] - 1)) {
                Y = Y + 1;
                maze[X][Y] = '*';
            }
            if ((X - 1) >= 0 && (X - 1) < mazeSizeX && (path[X - 1][Y] == path[X][Y] - 0.5)) {
                X = X - 1;
                maze[X][Y] = '*';
            } else if ((X + 1) >= 0 && (X + 1) < mazeSizeX && (path[X + 1][Y] == path[X][Y] - 0.5)) {
                X = X + 1;
                maze[X][Y] = '*';
            } else if ((Y - 1) >= 0 && (Y - 1) < mazeSizeY && (path[X][Y - 1] == path[X][Y] - 0.5)) {
                Y = Y - 1;
                maze[X][Y] = '*';
            } else if ((Y + 1) >= 0 && (Y + 1) < mazeSizeY && (path[X][Y + 1] == path[X][Y] - 0.5)) {
                Y = Y + 1;
                maze[X][Y] = '*';
            }
        }
        for (int i = 0; i < mazeSizeX; i++) {
            for (int j = 0; j < mazeSizeY - 1; j++) {
                std::cout << maze[j][i];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}