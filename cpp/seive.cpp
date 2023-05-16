#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#define INF 1000000007
#define ll long long
#define pb push_back

vector<int> seive(int n){
    bool arr[n+1];
    for (int i=1; i<=n; i++){
        arr[i]=true;
    }
    
    for (int i=2; i*i<=n; i++){
        if (arr[i]==false){continue;}
        else{
            int temp=i*i;
            while(temp<=n){
                arr[temp]=false;
                temp+=i;
            }
        }
    }
    
    vector<int> primes;
    for (int i=2; i<=n; i++){
        if(arr[i]==true){
            primes.pb(i);
        }
    }

    return primes;
}

int main(){
    int n;
    cin >> n;
    vector<int> answer;
    answer = seive(n);
    for (int num: answer){
        cout << num << " ";
    }
}