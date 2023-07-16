#include <bits/stdc++.h>
using namespace std;

#define V 7

int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" <<" ==> "<< graph[i][parent[i]] << " \n";
}
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
    int key[V];
    bool mstSet[V];

   
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

   
    for (int count = 0; count < V - 1; count++)
    {
      
        int u = minKey(key, mstSet);

        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, graph);
}

// Driver code
int main()
{
    
    int graph[V][V] = 
    {   /*v1*/ { 0, 2, 4, 1, 0, 0, 0 } ,
        /*v2*/ { 2, 0, 0, 3, 10, 0, 0 } ,
        /*v3*/ { 4, 0, 0, 2, 0, 5, 0 } ,
        /*v4*/ { 1, 3, 2, 0, 7, 8, 4 } ,
        /*v5*/ { 0, 10, 0, 7, 0, 0, 6 } ,
        /*v6*/ { 0, 0, 5, 8, 0, 0, 1 } ,
        /*v7*/ { 0, 0, 0, 4, 6, 1, 0 }
    };
    
    // Print the solution
    primMST(graph);

    return 0;
}