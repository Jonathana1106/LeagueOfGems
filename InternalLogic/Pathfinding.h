//
// Created by elias on 04/11/18.
//

#ifndef LOG_PATHFINDING_H
#define LOG_PATHFINDING_H

#include <utility>
#include<bits/stdc++.h>
#include <cfloat>
#include <iostream>
#include "../SetUp/Map.h"

#define ROW 15
#define COL 36

// Creating a shortcut for int, int pair type
typedef std::pair<int, int> Pair;

// A structure to hold the neccesary parameters
struct cell
{
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

class Pathfinding {
public:

    Pathfinding();

    Map* map;
    std::stack<Pair> path_destiny;

    bool isValid(int, int);
    bool isUnBlocked(int grid[][COL], int row, int col);
    bool isDestination(int row, int col, Pair dest);
    double calculateHValue(int row, int col, Pair dest);
    std::stack<Pair> tracePath(cell cellDetails[][COL], Pair dest);
    std::stack<Pair> aStarSearch(int grid[][COL], Pair src, Pair dest);
    void update_grid(int _grid[ROW][COL]);
    void walk(std::stack<Pair> path, int soldier);
    bool ended;
    void start();

private:

    Pair src;
    Pair soldeir1;
    Pair soldeir2;
    Pair soldeir3;
    Pair soldeir4;
    Pair soldeir5;
    Pair soldeir6;
    Pair soldeir7;
    Pair soldeir8;
    Pair soldeir9;
    Pair soldeir10;
    Pair soldeir11;
    Pair soldeir12;
    Pair soldeir13;
    Pair soldeir14;
    Pair soldeir15;

    // Destination is the left-most top-most corner
    Pair dest;

};


#endif //LOG_PATHFINDING_H
