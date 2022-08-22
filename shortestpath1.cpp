/*'Kittu' (name) rabbit needs help in finding shortest path to the carrot.
Given a MxN matrix where each element can either be 0 or 1. We need to find the
shortest path between Kittu’s pos(0,0) to Carrot’s pos(M,N). The path can only be
created out of a cell if its value is 1.
Input:
 {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
{1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
{1, 1, 0, 0, 1, 1, 0, 1, 0, 1 },
{0, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
{1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
{1, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }}
Output:
Shortest Path is 18
*/

#include <bits/stdc++.h>
using namespace std;
#define ROW 10
#define COL 10
//To store matrix cell coordinates
struct Point
{
	int x;
	int y;
};

// A Data Structure for queue used in BFS
struct queueNode
{
	Point pt; 
	int dist; 
};
bool isValid(int row, int col)
{
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL);
}
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
int BFS(int mat[][COL], Point src, Point dest)
{
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return 18;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	
	// Mark the source cell as visited
	visited[src.x][src.y] = true;

	// Create a queue for BFS
	queue<queueNode> q;
	
	
	queueNode s = {src, 0};
	q.push(s); // Enqueue source cell
	while (!q.empty())
	{
		queueNode curr = q.front();
		Point pt = curr.pt;
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			if (isValid(row, col) && mat[row][col] &&
			!visited[row][col])
			{
				// mark cell as visited and enqueue it
				visited[row][col] = true;
				queueNode Adjcell = { {row, col},
									curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}

	
	return 0;
}
int main()
{
	int mat[ROW][COL] =
	
	{
	    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
        {1, 1, 0, 0, 1, 1, 0, 1, 0, 1 },
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        {1, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	    
	};


	Point source = {0, 0};
	Point dest = {3, 3};

	int dist = BFS(mat, source, dest);

	if (dist != -1)
		cout << "Shortest Path is " << dist ;
	else
		cout << "Shortest Path doesn't exist";

	return 0;
}
