#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100001

int n, m;
vector<int> adj[MAX];
bool used[MAX];
int color[MAX];
void inp() {
    cin >> n >>m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(used, 0, sizeof(used));
}

bool dfs(int u,  int par) {
    color[u] = 3 - color[par];
    for(int v : adj[u]) {
        if(color[v]==0) {
            if(!dfs(v, u)) return false;
        }else if(color[v] == color[u])return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
         inp();
    bool ok = true;
    color[0] = 2;
    for(int i = 1; i <= n; i++) {
        if(color[i]==0) {
            if(!dfs(i, 0)) {
                ok = false;
                break;
            }
        }
    }
    if(ok == true) cout << "1";
    else cout << "0";

}