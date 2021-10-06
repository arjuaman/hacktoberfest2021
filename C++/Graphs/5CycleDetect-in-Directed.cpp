//cycle detection in directed graph
//dfs solution
//practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?track=DSASP-Graph&batchId=140
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    bool cycleDetection(vector<int> adj[], int i, bool vis[], bool recursionStack[])
    {
        vis[i] = true;
        recursionStack[i] = true;
        for (int u : adj[i])
        {
            if (vis[u] == false && cycleDetection(adj, u, vis, recursionStack))
                return true;
            else if (recursionStack[u] == true)
            {
                return true;
            }
        }
        recursionStack[i] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        bool vis[V];
        bool recursionStack[V];
        memset(vis, false, sizeof(vis));
        memset(recursionStack, false, sizeof(recursionStack));
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                if (cycleDetection(adj, i, vis, recursionStack) == true)
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends