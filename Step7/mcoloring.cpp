#include "bits/stdc++.h"
using namespace std;

bool possible(vector<vector<int>> graph,int m,vector<int> &colors,int index,vector<bool> &visited){
    if(index>=graph.size()){
        return true;
    }
    if(visited[index]){
        return true;
    }

    for(int i=0;i<m;i++){
        bool found = false;
        for(int j=0;j<graph[index].size();j++){
            if(colors[graph[index][j]]==i){
                found = true;
                break;
            }
        }
        if(!found){
            colors[index] = i;
            visited[index] = true;
            if(possible(graph,m,colors,index+1,visited)){
                return true;
            }
            colors[index] = -1;
            visited[index] = false;
        }
    }
    return false;
}

signed main(){ 
    int n,m,e;
    cin>>n>>m>>e;
    vector<pair<int,int>> edges(e);
    for(int i=0;i<e;i++){
        cin>>edges[i].first>>edges[i].second;
    }

    vector<int> colors(n,-1);
    vector<bool>visited(n,false);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<e;i++){
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
    }
    cout<<"sdcscsdcsd"<<endl;
    cout<<possible(graph,m,colors,1,visited);
    return 0;
}