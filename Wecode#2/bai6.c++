
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, M;

vector<vector<int>> findAdjacentCell(int, int);
void printResult(vector<vector<int>> &B)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }
}
// bool isAllValid(vector<vector<int>> B, vector<vector<int>> &A)
// {
//     // cout << "Validating:\n";
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             if (A[i][j])
//             {
//                 int s = 0;
//                 // cout << "Validating for A[i][j]:\n";
//                 vector<vector<int>> adj_cell = findAdjacentCell(i, j);
//                 // for (auto c : adj_cell)
//                 //     cout
//                 //         << "(" << c[0] << ", " << c[1] << ")" << endl;
//                 for (auto c : adj_cell)
//                 {
//                     // cout << "IF error";
//                     if (B[c[0]][c[1]])
//                         s++;
//                 }
//                 if (s != A[i][j])
//                 {
//                     return false;
//                 }
//             }
//         }
//     }

//     return true;
// }
bool isValid(vector<vector<int>> adj_cell, int num_of_mine, vector<vector<int>> B)
{
    int s = 0;
    for (auto &c : adj_cell)
    {
        if (B[c[0]][c[1]])
            s++;
    }
    if (s != num_of_mine)
        return false;
    return true;
}
bool isAllValid(vector<vector<int>> &mines, vector<vector<int>> &B, int cur)
{
    for (int k = 0; k <= cur; k++)
    {
        int i = mines[k][0];
        int j = mines[k][1];
        int mine = mines[k][2];
        vector<vector<int>> adj_cell = findAdjacentCell(i, j);
        if (!isValid(adj_cell, mine, B))
            return false;
    }
    return true;
}
vector<vector<int>> findAdjacentCell(int i, int j)
{
    vector<vector<int>> adj_cell;
    if (i - 1 >= 0)
        adj_cell.push_back(vector<int>{i - 1, j});
    if (j + 1 < M)
        adj_cell.push_back(vector<int>{i, j + 1});
    if (i + 1 < N)
        adj_cell.push_back(vector<int>{i + 1, j});
    if (j - 1 >= 0)
        adj_cell.push_back(vector<int>{i, j - 1});
    return adj_cell;
}
bool weep(int idx, vector<vector<int>> &mines, vector<vector<int>> &B, vector<vector<int>> &A)
{
    if (idx == mines.size())
    {
        printResult(B);
        return true;
    }
    // cout << "weep: idx=" << idx << "\tsize of mines = " << mines.size() << endl;
    int i = mines[idx][0];
    int j = mines[idx][1];
    int mine = mines[idx][2];
    vector<vector<int>> adj_cell = findAdjacentCell(i, j);
    // cout << "Here is adj_cell:\n";
    // for (auto c : adj_cell)
    //     cout
    //         << "(" << c[0] << ", " << c[1] << ")" << endl;
    if (mine == 1)
    {
        for (auto c : adj_cell)
        {
            // Create a new board
            vector<vector<int>> newB = B;
            newB[c[0]][c[1]] = 1;
            // printResult(newB);
            if (isAllValid(mines, newB, idx))
                if (weep(idx + 1, mines, newB, A))
                    return true;
        }
    }
    else if (mine == 2)
    {
        // cout << "in mine: idx=" << idx << ", mine=(" << mines[idx][0] << "," << mines[idx][1] << ")"
        //      << " = " << mines[idx][2] << endl;
        // Iterate through all adjacent cells
        for (auto c1 : adj_cell)
        {
            for (auto c2 : adj_cell)
            {
                // If c1 and c2 are the same or are not on the diagonal, continue to next pair
                if (c1 == c2)
                {
                    continue;
                }

                // Create a new board
                vector<vector<int>> newB = B;
                newB[c1[0]][c1[1]] = 1;
                newB[c2[0]][c2[1]] = 1;
                // cout << "\tHere is new B:\n";
                // printResult(newB);
                if (isAllValid(mines, newB, idx))
                    if (weep(idx + 1, mines, newB, A))
                        return true;
            }
        }
    }
    else if (mine == 3)
    {
        // Iterate through all adjacent cells
        for (auto c1 : adj_cell)
        {
            for (auto c2 : adj_cell)
            {
                for (auto c3 : adj_cell)
                {
                    // If c1, c2, and c3 are the same or not on the diagonal, continue to next triplet
                    if (c1 == c2 || c2 == c3 || c3 == c1)
                    {
                        continue;
                    }

                    // Create a new board
                    vector<vector<int>> newB = B;
                    newB[c1[0]][c1[1]] = 1;
                    newB[c2[0]][c2[1]] = 1;
                    newB[c3[0]][c3[1]] = 1;

                    // Check if the board is valid and continue the recursion
                    if (isAllValid(mines, newB, idx))
                        if (weep(idx + 1, mines, newB, A))
                            return true;
                }
            }
        }
    }
    else if (mine == 4)
    {
        // Create a new board
        vector<vector<int>> newB = B;
        newB[adj_cell[0][0]][adj_cell[0][1]] = 1;
        newB[adj_cell[1][0]][adj_cell[1][1]] = 1;
        newB[adj_cell[2][0]][adj_cell[2][1]] = 1;
        newB[adj_cell[3][0]][adj_cell[3][1]] = 1;
        // Check if the board is valid and continue the recursion
        if (isAllValid(mines, newB, idx))
            if (weep(idx + 1, mines, newB, A))
                return true;
    }
    return false;
}
void solve(vector<vector<int>> &A)
{
    vector<vector<int>> mines;
    vector<vector<int>> B(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j])
                mines.push_back(vector<int>{i, j, A[i][j]});
        }
    }
    weep(0, mines, B, A);
    // cout << "Output:\n";
}
int main()
{
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    solve(A);
    return 0;
}