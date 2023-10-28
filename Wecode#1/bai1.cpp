/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

void inputGraph(bool *[], int);
void process(bool *[], int, int);

int main()
{
	int v, e, n; // v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;
	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được

	// ###INSERT CODE HERE -
	// Declaring the 2-dimension array G
	G = new bool *[v];
	for (int col = 0; col < v; col++)
		G[col] = new bool[v];

	// Assigning default value of each element in G equals to 0
	for (int row = 0; row < v; row++)
		for (int col = 0; col < v; col++)
			G[row][col] = 0;

	inputGraph(G, e);
	process(G, v, n);

	delete[] G;
}
void inputGraph(bool *G[], int e)
{
	// if u and i edges are connected, G[u-1][i-1] will be assigned to 1 to diverge with another pairs which are irrelevant.
	int u, i;
	for (int index = 0; index < e; index++)
	{
		cin >> u >> i;
		G[u - 1][i - 1] = 1;
	}
}

void process(bool *G[], int v, int n)
{
	// x variable used to diverge command of input.
	int x;
	int u, i;
	for (int index = 0; index < n; index++)
	{
		cin >> x;
		// if x == 1, we will check that u and i is connected or not.
		if (x == 1)
		{
			cin >> u >> i;
			cout << ((G[u - 1][i - 1]) ? "TRUE" : "FALSE") << endl;
		}
		// if x == 2, we will list all of relative verticles with u
		else if (x == 2)
		{
			cin >> u;
			bool flag = false;
			for (int idx = 0; idx < v; idx++)
				if (G[u - 1][idx])
				{
					cout << idx + 1 << " ";
					flag = true;
				}
			cout << endl;
			if (!flag)
				cout << "NONE" << endl;
		}
		else
			break;
	}
}
