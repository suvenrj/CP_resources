void Solve(){
    int n,m;
    cin >> n >> m;
    vector<int> Adj[n+1];
    for (int i=0; i<m;i++){
        int a,b;
        cin >> a >> b;
        Adj[a].push_back(b);
    }
}