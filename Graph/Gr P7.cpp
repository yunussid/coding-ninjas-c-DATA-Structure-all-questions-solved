/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
*/
#include<iostream>
using namespace std;

void DFS(bool **graph,int v,bool *visited,int currentVertex){
    visited[currentVertex]=true;

    for(int i=0;i<v;i++){
        if(graph[currentVertex][i]&&!visited[i]){
            DFS(graph,v,visited,i);
        }
    }
}
bool isConnected(bool **graph,int v){
    bool* visited=new bool[v]();
    DFS(graph,v,visited,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int v,e;
    cin>>v>>e;

      bool **graph=new bool*[v];
    for(int i=0;i<v;i++){
        graph[i]=new bool[v]();
    }
    for(int i=0,a,b;i<e;i++){
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }


    cout<<(isConnected(graph,v)?"true":"false");
    for(int i=0;i<v;i++){
        delete []graph[i];
    }
    delete []graph;
}
