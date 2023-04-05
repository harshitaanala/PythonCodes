#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 9
int minimumDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (sptSet[i] == false && dist[i] <= min)
        {
            min = dist[i], min_index = i;
        }
    }
    return min_index;
}

void Display(int dist[])
{
    printf("Vertex \t\t Minimum Distance from source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void Dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minimumDistance(dist, sptSet);
        sptSet[u] = true;
        for (int i = 0; i < V; i++)
        {
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    Display(dist);
}
int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    Dijkstra(graph,0);

    return 0;
}
