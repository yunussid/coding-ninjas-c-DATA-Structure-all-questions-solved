/*
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
*/
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> getOneComponent(bool **graph,int startingVertex,int v,bool *visited){
    vector<int> component;
    queue<int> pendingNodes;
    pendingNodes.push(startingVertex);
    visited[startingVertex]=true;

    while(!pendingNodes.empty()){
        int current=pendingNodes.front();
        pendingNodes.pop();
        component.push_back(current);
        for(int i=0;i<v;i++){
            if(graph[current][i]&&!visited[i]){
                pendingNodes.push(i);
                visited[i]=true;
            }
        }
    }
    return component;
}
vector<vector<int>> getAllComponents(bool **graph,int v){
    vector<vector<int>> result;
    bool *visited=new bool[v]();

    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> component=getOneComponent(graph,i,v,visited);
            result.push_back(component);
        }
    }
    delete []visited;
    return result;
}
int main(){
    int v,e;
    cin>>v>>e;

    bool** graph=new bool*[v];

    for(int i=0;i<v;i++){
        graph[i]=new bool[v]();
    }

    for(int i=0,a,b;i<e;i++){
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }

    vector<vector<int>> connectedComponents=getAllComponents(graph,v);

    for(int i=0;i<connectedComponents.size();i++){
        sort(connectedComponents[i].begin(),connectedComponents[i].end());
        for(int j=0;j<connectedComponents[i].size();i++){
            cout<<connectedComponents[i][j]<<" ";
        }
        cout<<"\n";
    }
}
