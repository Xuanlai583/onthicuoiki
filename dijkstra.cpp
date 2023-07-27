#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000000

int n,m, s, t;
vector<pair<int , int>> adj[MAX];
int d[MAX];
typedef pair<int, int> pi;
void inp() {
    cin >> n >>m;
    for(int i = 0; i < m; i++) {
        int x , y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    cin >> s>> t;
}
void slove(int s) {
    for(int i = 1; i <= n; i++)d[i] = 1e9;
    d[s]= 0;
    priority_queue<pi, vector<pi>, greater<pi>> Q;
    Q.push({0, s});
    while(!Q.empty()) {
        pi top = Q.top();Q.pop();
        int u = top.second;
        int len = top.first;
        if(len > d[u])continue;
        for(pi it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    cout << d[t];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    inp();
    slove(s);
}
