#include <bits/stdc++.h>
/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double pi = acos(-1.0);
typedef long long ll;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
using namespace std;
bool isPrime(ll n)
{
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	else if (n % 2 == 0)
		return false;
	else
	{
		ll op = sqrt(n);
		FOR(i, 3, op + 1, 2)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}
}
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists
public:
	Graph(int V);  // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	bool isReachable(int s, int d);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d)
{
	// Base case
	if (s == d)
		return true;

	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// it will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			// If this adjacent node is the destination node, then
			// return true
			if (*i == d)
				return true;

			// Else, continue to do BFS
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	// If BFS is complete without visiting d
	return false;
}

void solve(){
    ll n;
    cin >>n;
    ll ans = 0;
    for(ll i=1;i<n;i++){// loop for c
        for(ll j=2*i;j<=n;j+=i){ // loop for b
            ans += n/j;
            if(n%j >= i){
                ans++;
            }
        }
    }
    cout << ans<<"\n";

}

int32_t main()
{
	// auto start = chrono::high_resolution_clock::now();
	FastIO
//    #ifdef _DEBUG
	// freopen("input.txt", "r", stdin);
//    //  freopen("output.txt", "w", stdout);
	// #endif
	int t;
	cin >> t;
	while (t--)
	{
		solve();
    }
	return 0;


}

// auto end = chrono::high_resolution_clock::now();
// double time_taken =
//     chrono::duration_cast<chrono::nanoseconds>(end - start).count();
// time_taken *= 1e-9;
// cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
// cout << " sec" << endl;
