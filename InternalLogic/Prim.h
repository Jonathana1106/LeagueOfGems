//
// Created by jonathan on 08/11/18.
//

#ifndef LOG_PRIM_H
#define LOG_PRIM_H


#define V 5


class Prim {

public:
    int MSTmatrix[V][V];
//This algorithm is designed to work only with adjacency matrix
public:

    void primMST(int graph[V][V]);

    int printMST(int parent[], int n, int graph[V][V]);

    int minKey(int key[], bool mstSet[]);


    int test();
};

#endif //LOG_PRIM_H
