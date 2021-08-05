/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E
connections or edges between islands. Can you count the number of connected groups of islands.
*/
#include<iostream>
using namespace std;

void helper(int **edges,int n,int sv,bool *visited){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            helper(edges,n,i,visited);
        }
    }
}
int dfs(int **edges,int n){
    int count=0;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            helper(edges,n,i,visited);
            count++;
        }
    }
    delete[] visited;
    return count;
}
int main(){
        int n,e;
        cin>>n>>e;
        int **edges=new int*[n];
        for(int i=0;i<n;i++){
            edges[i]=new int[n];
            for(int j=0;j<n;j++){
                edges[i][j]=0;
            }
        }
        for(int i=0;i<e;i++){
            int f,s;
            cin>>f>>s;
            edges[f][s]=1;
            edges[s][f]=1;
        }
        int ans=dfs(edges,n);
        cout<<ans<<" ";
}
