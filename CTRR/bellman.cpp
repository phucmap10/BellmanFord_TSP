#include "bellman.h"

void BF(int G[20][20], int n, char start, int BFValue[20], int BFPrev[20]) {
    int startIdx = vertexIndex(start);
	
    vector<int> tmpval(n);
    vector<int> tmpprev(n);
    for(int i = 0; i < n; i++){
        if(BFValue[i] == -1)BFValue[i] = INF;
    }
    if(BFPrev[startIdx] == -1){
    BFValue[startIdx] = 0; //handle the testcase that change the start vertex, only change when its prev
    }                      //is -1
    for(int i = 0; i < n; i++){
        tmpval[i] = BFValue[i];
        tmpprev[i] = BFPrev[i];
    }

    for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (G[u][v] != 0 && BFValue[u] != INF && BFValue[u] + G[u][v] < BFValue[v]){
                    if(BFValue[u] + G[u][v] < tmpval[v]){
                    tmpval[v] = BFValue[u] + G[u][v];
                    tmpprev[v] = u;
                    
                }
                }
            }
        }
    for(int i = 0; i < n; i++){
    if(tmpval[i] == INF)tmpval[i] = -1;
    BFValue[i] = tmpval[i];
    BFPrev[i] = tmpprev[i]; //Update BFValue and BFPrev with each step of iteration
    }
}

string BF_Path(int G[20][20], int n, char start, char goal) {
    int startIdx = vertexIndex(start);
    int goalIdx = vertexIndex(goal);

    vector<int> BFValue(n, INF);//Initialize a vector BFValue with a size of n, and assign all of them = INF
    vector<int> BFPrev(n, -1);//Initialize a vector BFValue with a size of n, and assign all of them = -1
    BFValue[startIdx] = 0;

    vector<int> tmpval(n); //this is a tmp value to check the correctness of BF 
    // For example: if B < A, it becomes A, then C without tmp will becomes B instead of A, which is wrong
    vector<int> tmpprev(n);
    // Copy BFValue and BFPrev to tmpval and tmpprev
        for (int i = 0; i < n; i++) {
            tmpval[i] = BFValue[i];
            tmpprev[i] = BFPrev[i];
        }
    for (int k = 0; k < n - 1; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (G[u][v] != 0 && BFValue[u] != INF && BFValue[u] + G[u][v] < BFValue[v]){
                    if(BFValue[u] + G[u][v] < tmpval[v]){
                    tmpval[v] = BFValue[u] + G[u][v];
                    tmpprev[v] = u;
                    
                }
                }
            }
        }
        for(int i = 0; i < n; i++){
        BFValue[i] = tmpval[i];
        BFPrev[i] = tmpprev[i]; //Update BFValue and BFPrev with each step of iteration
    }
    }


    //Path reconstruction
    stack<char> pathStack;
    int current = goalIdx;
    while (current != -1) {
        pathStack.push(indexVertex(current));
        current = BFPrev[current];
    }

    if (pathStack.top() != start) {
        return "No path found";
    }

    string path;
    while (!pathStack.empty()) {
        path += pathStack.top();
        pathStack.pop();
        if(!pathStack.empty())path += " ";
    }

    return path;
}