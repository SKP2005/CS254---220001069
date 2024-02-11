//T.C->O(V^3)
//S.C->O(V^2)

#include <bits/stdc++.h>
using namespace std;

const int vertices = 5;

bool isBipartUtil(int graph[][vertices], int src, int arr[]) {
	arr[src] = 1;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < vertices; ++v) {
			if (graph[u][v] && arr[v] == -1) {
				arr[v] = 1 - arr[u];
				q.push(v);
			}
			else if (graph[u][v] && arr[v] == arr[u])
				return false;
		}
	}
	return true;
}

bool isBipart(int graph[][vertices]) {
	int arr[vertices];
	for (int i = 0; i < vertices; ++i)
		arr[i] = -1;
	for (int i = 0; i < vertices; i++)
		if (arr[i] == -1)
			if (isBipartUtil(graph, i, arr) == false)
				return false;
	return true;
}

bool twoCliques(int graph[][vertices]) {
	int compGraph[vertices][vertices];
	for (int i = 0; i < vertices; i++)
		for (int j = 0; j < vertices; j++)
			compGraph[i][j] = (i != j) ? !graph[i][j] : 0;
	return isBipart(compGraph);
}

int main() {
	int graph[vertices][vertices] = {
		{0, 1, 1, 1, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0}
	};
	twoCliques(graph) ? cout << "Yes" : cout << "No";
	return 0;
}