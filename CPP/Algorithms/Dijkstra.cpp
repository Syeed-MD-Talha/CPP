/******************************************************************************
                        Bismillahir-Rahmanir-Rahim

                        Author :  Syeed MD Talha


*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(6);
ll inf = 1e18;

ll mod = 1e9 + 7;


map < ll, vector<pair<ll, ll>>>graph;
ll node[100006], dis[1000006]; // here node array is used to store the path
priority_queue<ll>s;

void printPath(ll n)
{
    if (n != 1)printPath(node[n]);
    cout << n << " ";
}

int main()
{
    ll n, m, u, v, w; cin >> n >> m;

    while (m--)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    s.push(1);

    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        node[i] = i;
    }

    dis[1] = 0;

    while (!s.empty())
    {
        u = s.top();
        s.pop();

        for (auto x : graph[u])
        {
            v = x.first;
            w = x.second;

            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                s.push(v);
                node[v] = u;
            }
        }
    }


    if (dis[n] == inf)cout << -1 << endl;
    else printPath(n);




}