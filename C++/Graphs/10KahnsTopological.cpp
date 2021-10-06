// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return list containing vertices in Topological order.\


    //main gist of the question  -----
    vector<int> topoSort(int V, vector<int> adj[])
    {

        vector<int> indeg(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int x : adj[i])
            {
                indeg[x]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (int x : adj[u])
            {
                if (--indeg[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
} // } Driver Code Ends