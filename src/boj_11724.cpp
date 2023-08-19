#include <iostream>
#include <vector>

using namespace std;

int vertexCnt, edgeCnt, connectionCount;
vector< vector< int > > graph;
vector< int > visitedVertexes;

void dfs(int vertexNumber)
{
    for (int i = 0; i < graph[vertexNumber].size(); i++)
    {
        if (find(visitedVertexes.begin(), visitedVertexes.end(), graph[vertexNumber][i]) != visitedVertexes.end())
            continue;

        visitedVertexes.push_back(graph[vertexNumber][i]);
        dfs(graph[vertexNumber][i]);
    }
}

int main(void)
{
    cin >> vertexCnt >> edgeCnt;

    graph.resize(vertexCnt);

    for (int i = 0; i < edgeCnt; i++)
    {
        int u, v;

        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < vertexCnt; i++)
    {
        if (find(visitedVertexes.begin(), visitedVertexes.end(), i) != visitedVertexes.end())
            continue;

        visitedVertexes.push_back(i);
        dfs(i);
        connectionCount++;
    }

    cout << connectionCount << endl;

    return 0;
}