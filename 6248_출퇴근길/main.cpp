#include <iostream>
#include <queue>

using namespace std;

int n, m, st, en;
vector<int> adj[2][100001];
bool vis[4][100001] = {};

void BFS(int start, int end, int adjType, int visitType);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    cin >> st >> en;
    BFS(st, en, 0, 0);
    BFS(en, st, 0, 1);
    BFS(st, -1, 1, 2);
    BFS(en, -1, 1, 3);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == st || i == en) continue;
        if (vis[0][i] == true
            && vis[1][i] == true
            && vis[2][i] == true
            && vis[3][i] == true)
            cnt++;
    }

    cout << cnt;

    return 0;
}

void BFS(int start, int end, int adjType, int visitType)
{
    queue<int> q;
    int cur;
    vis[visitType][start] = true;
    q.push(start);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        //cout << "[BFS] adjType: " << adjType << ", visitType: " << visitType << "cur: " << cur << "\n";
        if (cur == end) continue;
        for (int nx : adj[adjType][cur])
        {
            if (vis[visitType][nx]) continue;
            vis[visitType][nx] = true;
            q.push(nx);
        }
    }
}
