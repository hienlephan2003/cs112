/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

// ###INSERT CODE HERE -
#include <algorithm>
void sortVector(vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		for (size_t j = i + 1; j < vec.size(); ++j)
		{
			if (vec[i] > vec[j])
			{
				int temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}
}
void inputGraph(vector<vector<int>> &G, int v, int e)
{
	G.resize(v + 1);
	for (int idx = 0; idx < e; idx++)
	{
		int u, i;
		cin >> u >> i;
		G[u].push_back(i);
	}
}
void process(vector<vector<int>> G, int v, int n)
{
	int x;
	int u, i;
	for (int idx = 0; idx < n; idx++)
	{
		cin >> x;

		// if x == 1, we will check that u and i are connected or not.
		if (x == 1)
		{
			cin >> u >> i;
			bool flag = false;
			for (auto it : G[u])
			{
				if (it == i)
				{
					cout << "TRUE";
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "FALSE";
			}
			cout << endl;
		}
		// if x == 2, we will list all of relative verticles with u
		else if (x == 2)
		{
			cin >> u;
			cout << endl;
			sortVector(G[u]);
			if (G[u].size())
			{
				for (auto it : G[u])
					cout << it << " ";
				cout << endl;
			}
			else
				cout << "NONE" << endl;
		}
		else
			break;
	}
}
int main()
{

	int v, e, n;
	cin >> v >> e >> n; // v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int>> G;

	inputGraph(G, v, e);
	process(G, v, n);

	return 0;
}
