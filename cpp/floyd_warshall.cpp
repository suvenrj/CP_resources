#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include<string>
#include<vector>
#include<queue>
#define INF 100000000000000


void floyd(int n, long long dp[][501]){
    for (int k=1; k<n+1; k++){
        for (int i=1; i<n+1; i++){
            for (int j=1; j<n+1; j++){
                if (dp[i][k]!=INF && dp[k][j]!=INF){
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
    }
}


int main(){
    int n, m , q;
    cin >> n >> m >> q;
    long long dp[501][501];
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            if (i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=INF;
            }   
        }
    }
    for (int i=0; i<m; i++){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        dp[a][b]=min(dp[a][b],c);
        dp[b][a]=min(dp[b][a],c);
    }
    floyd(n, dp);
    for (int i=0; i<q; i++){
        int q1,q2;
        cin >> q1 >> q2;
        if (dp[q1][q2]==INF){
            cout << -1 << '\n';
        }
        else{
            cout << dp[q1][q2] << '\n';
        }
    }
}