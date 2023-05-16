#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#define INF 1000000007
#define ll long long
#define pb push_back

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> grid[n+1];
    for (int i=0; i<=m; i++){
        grid[0].pb(0);
    }
    for (int i=1; i<=n; i++){
        grid[i].pb(0);
        for (int i=0; i<m; i++){
            char temp;
            cin >> temp;
            if (temp == '.'){
                grid[i].pb(0);
            }
            else{
                grid[i].pb(1);
            }
        }
    }
    int prefix[n+1][m+1];
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            prefix[i][j]=0;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; i<=m; j++){
            prefix[i][j]=grid[i][j]-prefix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1];
        }
    }
    int q;
    cin >> q;
    for (int i=0; i<q; i++){
        int from_row, from_col, to_row, to_col;
        cin >> from_row >> from_col >> to_row >> to_col;
        cout << prefix[to_row][to_col]-prefix[from_row-1][to_col]-prefix[to_row][from_col-1]+prefix[from_row-1][from_col-1]<< '\n';
    }

}