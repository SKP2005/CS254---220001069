//T.C->O(N) N->is the total no. of boxes 
//S.C->O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int posn;
	int dist;
};

int getMinDiceThrows(int m[], int N) {
	bool* visited = new bool[N]();
	queue<Node> q;
	visited[0] = true;
	Node start = { 0, 0 };
	q.push(start);

	Node current;
	while (!q.empty()) {
		current = q.front();
		int v = current.posn;
		if (v == N - 1)
			break;
		q.pop();
		for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
			if (!visited[j]) {
				Node next;
				next.dist = (current.dist + 1);
				visited[j] = true;
				next.posn = (m[j] != -1) ? m[j] : j;
				q.push(next);
			}
		}
	}
	return current.dist;
}

int main() {
	int totalBoxes = 30;
	int m[totalBoxes] = { -1 };

    // Ladders
	m[2] = 20;
	m[4] = 7;
	m[10] = 15;
	m[19] = 28;

    // Snakes
	m[26] = 0;
	m[20] = 8;
	m[16] = 13;
	m[18] = 6;
	cout << "Minimum number of dice throws needed is " << getMinDiceThrows(m, totalBoxes);
	return 0;
}
