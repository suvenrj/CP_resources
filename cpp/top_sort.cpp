#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#define INF 1000000007
#define ll long long
#define pb push_back

void dfs(int x, vector<int>*Adj, int* visited, int*parent, vector<int>& answer){
    visited[x]=1;
    for (int child: Adj[x]){
        if (visited[x]==0){
            parent[child]=x;
            dfs(child, Adj, visited, parent, answer);
        }
    }
    answer.pb(x);
}

vector<int> top_sort(vector<int>*Adj, int n){
    vector<int>answer;
    int visited[n+1];
    int parent[n+1];
    for (int i=0; i<=n; i++){
        visited[i]=0;
        parent[i]=-1;
    }
    for (int i=1; i<=n; i++){
        if (visited[i]==0){
            dfs(i, Adj, visited, parent, answer);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>Adj[n+1];
    for (int i=0;i<m;i++){
        int a ,b;
        cin >> a >> b;
        Adj[a].pb(b);
    }
    vector<int> top_sort_vertex;
    top_sort_vertex=top_sort(Adj, n);
    for (int vertex: top_sort_vertex){
        cout << vertex << " ";
    }
}