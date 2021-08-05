/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a
cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
*/
#include <iostream>
using namespace std;

int helper(int** edges , int n) {
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (edges[i][j] && edges[j][k] && edges[k][i]) {
                    count++;
                }
            }
        }
    }
    return count;
}
int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] == 0;
        }
    }
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout<<helper(edges, n);

}
