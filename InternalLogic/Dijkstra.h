//
// Created by jonathan on 08/11/18.
//

#ifndef LOG_DIJKSTRA_H
#define LOG_DIJKSTRA_H


#include <vector>

#define V 9


class Dijkstra {

public:
    std::vector<int> paths;
public:

    void printFromPaths(std::vector<std::vector<int>> &a);

    int test();

    void dijkstra(int graph[V][V], int src, int finish);

    int printSolution(int *dist, int n, int *parent, int finish);

    void printPath(int *parent, int dest);

    int minDistance(int *dist, bool *sptSet);
};


#endif //LOG_DIJKSTRA_H
