#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#define INF 1000000007
#define ll long long
#define pb push_back

vector<int> find_factors(int n){
    int temp=n;
    vector<int> factors;
    for (int i=2; i*i<=n; i++){
        if (temp%i==0){
            factors.pb(i);
        }
        while(temp%i==0){
            temp/=i;
        }
    }
    if (temp>1){
        factors.pb(temp);
    }
    return factors;
}

int main(){
    int n;
    cin >> n;
    for(int x: find_factors(n)){
        cout << x << " ";
    }
}