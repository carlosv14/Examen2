#include "Test.h"
#include <iostream>

using namespace std;

//Counts the number of posibles paths from origin to destination in the given DAG (Directed Acyclic Graph)
//Use Dynamic Programing to optimize the process
int ** memo;

int countPathsRecursive(int** DAG, int size, int origin, int destination) {
    if(origin == destination)
        return 1;

    int possiblePaths = 0;
    for(int i = 0; i < size; ++i) {
        if(DAG[origin][i] != -1) {
            if(memo[origin][i] == -1)
            {
                int paths = countPathsRecursive(DAG, size, i, destination);
                memo[origin][i] = paths;
                possiblePaths += paths;
            }
            else
            {
                possiblePaths += memo[origin][i];;
            }
        }
    }
    return possiblePaths;
}
int countPaths(int** DAG, int size, int origin, int destination)
{
    memo = new int* [size];
    for(int i=0;i<size;i++)
    {
        memo[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            memo[i][j]=-1;
        }
    }
    return countPathsRecursive(DAG, size, origin, destination);
}



//Returns a vector that maps each vertex to a color (or number)
//Two adjacent vertex cannot have the same color
//The less colors used, the better
//Use a Greedy Paradigm to optimize the process
//The best solution is not required
vector<int> getVertexColors(int** graph, int size)
{
    vector<int> answer;
    for(int i =0; i<size; i++)
    {
        answer.push_back(i);
    }
    return answer;
}

int main ()
{
    test();
    return 0;
}
