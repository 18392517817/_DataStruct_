

#define N 10
//int MazeArray[][N] = {1};

struct Pos
{
	size_t _row;
	size_t _col;

};
inline void InitMaze(int maze[N][N])
{
	FILE * fOut = fopen("MazeMap.txt", "r");

	if (fOut == NULL)
	{
		cout << "Open MazeMap.txt Fail!" << endl;
		exit(-1);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N;)
		{
			char ch = fgetc(fOut);
			if (ch == '1' || ch == '0')
			{
				if (ch == EOF)
				{
					cout << "Maze Map Error��" << endl;
					exit(-1);
				}
				if (ch == '1' || ch == '0')
				{
					maze[i][j] = ch - '0';
					++j;
				}

			}
		}
	}
	fclose(fOut);
}

inline void PrintMaze(int maze[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

#include<stack>
bool CheckIsAccess(int maze[][N],Pos cur)
{
	if (cur._row >= 0 && cur._row < N
		&&cur._col >= 0 && cur._col < N
		&&maze[cur._row][cur._col] == 0)
	{
		return true;
	}
	return false;
}

stack<Pos> minStack;

bool GetMazePath(int maze[][N],Pos entry,stack<Pos>& paths)
{
	paths.push(entry);
	maze[entry._row][entry._col] = 2;
	while (!paths.empty())
	{
		Pos cur = paths.top();
		if (cur._row==N-1)
		{
			//
			return true;
			/* //���ž���
			if (paths.size() < minStack.size())
			{
				minStack = paths;
				maze[cur._row][cur._col] = 2;
			}*/
		}
		//̽����
		Pos next = cur;
		next._row -= 1;
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row][next._col] = 2;
			continue;
		}
		//̽����
		next = cur;
		next._col += 1;
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row][next._col] = 2;
			continue;
		}
		//̽����
		next = cur;
		next._row += 1;
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row][next._col] = 2;
			continue;
		}
		//̽����
		next = cur;
		next._col -= 1;
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row][next._col] = 2;
			continue;
		}
		//��ջջ����λ�ã�����
		Pos tmp = paths.top();
		maze[tmp._row][tmp._col] = 3;
		paths.pop();
	}
	return false;
}


//����һ����ά����
int ** f(int X)
{
	int **p = new int *[X];
	for (int i = 0; i < X;++i)
	{
		p[i] = new int[X];
	}

	return p;
}


//�Թ�

void Maze_Test()
{
	int mazeArray[N][N] = { 0 };
	InitMaze(mazeArray);
	PrintMaze(mazeArray);

	stack<Pos> paths;
	Pos entey = {2,0};
	bool ret = GetMazePath(mazeArray,entey,paths);
	if (ret)
	{
		cout <<"�ɹ��߳��Թ���"<< endl;
		PrintMaze(mazeArray);
	}

}