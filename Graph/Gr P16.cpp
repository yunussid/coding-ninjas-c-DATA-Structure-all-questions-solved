/*
Code : Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
*/
#include<iostream>
using namespace std;


int findMinVertex(int *distance,bool *visited,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex==-1 || distance[i] < distance[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}
void dijkstra(int **edges,int n){
    int *distance=new int[n];
    bool *visited=new bool[n];

    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;
    for(int i=0;i<n-1;i++){
        int minVertex=findMinVertex(distance,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j]!=0 && !visited[j]){
                int dist=distance[minVertex]+edges[minVertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }

    for(int i=0;i,n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete []visited;
    delete []distance;
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
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    cout<<endl;
    dijkstra(edges,n);

    for(int i=0;i<n;i++){
        delete []edges[i];
    }
    delete []edges;
}
