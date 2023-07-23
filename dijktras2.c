#include <stdio.h>
#include <stdbool.h>
#define INF 9999
#define V 9

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the final shortest path from source to destination
void printPath(int parent[], int j)
{
    // Base Case: If j is the source
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf(" -> %d", j);
}

// Function to print the final solution
void printSolution(int dist[], int parent[], int src)
{
    printf("Vertex\t\tDistance\tPath");
    for (int i = 0; i < V; i++)
    {
        printf("\n%d -> %d\t\t%d\t\t%d", src, i, dist[i], src);
        printPath(parent, i);
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V];     // Array to store the shortest distance from source to i
    bool sptSet[V];  // Array to track vertices included in shortest path tree
    int parent[V];   // Array to store the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    parent[src] = -1; // Source vertex has no parent

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist[] value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
        {
            // Update dist[v] only if it's not in sptSet, there is an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current value of dist[v].
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array and shortest paths
    printSolution(dist, parent, src);
}

// Driver program to test above functions
int main()
{
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    int n;

    dijkstra(graph, n);

    return 0;
}
