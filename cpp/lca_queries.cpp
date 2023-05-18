#include <bits/stdc++.h>
using namespace std;

template <typename T> using V2D = vector<vector<T>>;
typedef long long ll;
#define loop(i,b) for (int i = 0; i < b; i++)
#define Loop(i,a,b) for (int i = a; i < b; i++)
#define Loopskip(i,a,b,s) for (int i = a; i != b; i+=s)
#define Loopneg(i,a,b) for (int i = a; i >= b; i--)

template <typename T> vector<T> input_vector(int n)
{
    vector<T> vec(n);

    loop(i, n)
        cin >> vec[i];

    return vec;
}

#define LB(vec,x) lower_bound(vec.begin(), vec.end(), x)//First no. at least x
#define UB(vec,x) upper_bound(vec.begin(), vec.end(), x)

template<typename T> bool sortcol(const vector<T> &veca, const vector<T> &vecb)
{
    return veca[1] < vecb[1];
}

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int INF = 1000000000;
vector<int> Adj[100000+10];
int parent[100000+10];
int visited[100000+10];
int answer[100000+10];


void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int dfs(int v){
    //do the following
    visited[v]=1;
    for (pair<int, int> node: q_set[v]){
        if (visited[node.first]==1){
            answer[node.second]=find_set(node.first);
        }
    }
    make_set(v);
    for (int child: Adj[v]){
        if (visited[child]==0){
            dfs(child);
            union_sets(v, child);
        }
    }
}


void Solve()
{
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<pair<int, int>> q_set[n+1];
    for (int i=1; i<q+1; i++){
        int q1, q2;
        cin >> q1 >> q2;
        q_set[q1].push_back(make_pair(q2, i));
        q_set[q2].push_back(make_pair(q1, i));
    }
    dfs(1);
    for (int i=0; i<q; i++){
        cout << answer[i] << '\n';
    }
}

int main(int argc, char ** argv) 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int t=1; 
    //cin >> t;

    loop(T, t)
        Solve();
}