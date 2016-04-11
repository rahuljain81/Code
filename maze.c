#include <stdio.h>

#define MAX 20
int arr[MAX][MAX];
int start, end;
int mat[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int start_x, start_y, end_x, end_y;
char visited[MAX][MAX];
int flag=0;
int M, N;

int do_process (int x, int y)
{
	//printf ("[%d, %d] ", x, y);
	if (x == end_x && y == end_y)
	{
		flag = 1;
		return 1;
	}
	if (visited[x][y])
		return 0;

	int i, j;
	visited[x][y]=1;
	for (i=0; i < 4 && !flag; i++)
	{
		if ((x+mat[i][0])>=0 && (y+mat[i][1])>=0 && arr[x+mat[i][0]][y+mat[i][1]])
			do_process(x+mat[i][0], y+mat[i][1]);
	}
	if (flag)
		return 1;

	visited[x][y]=0;

	return 0;
}
void dump_maze(int m, int n)
{
	int i, j;
	for (i=0; i < m; i++)
	{
		for (j=0; j < n; j++)
			printf ("%c", arr[i][j]?'.':'#');
		printf("\n");
	}
}
int main()
{
	int t, T;
	int i, j, m, n;
	int num_entry;
	char ch;
	scanf ("%d\n", &T);
	for (t=0; t<T; t++)
	{
		num_entry = 0;
		start=end=flag=0;
		start_x=start_y=end_x=end_y=0;
		scanf ("%d%d\n", &m, &n);
		M=m, N=n;
		for (i=0; i < m; i++)
		{
			for (j=0; j < n; j++)
			{
				scanf ("%c", &ch);
				//printf ("%c", ch);
				if (ch == '#')
					arr[i][j] = 0;
				else
				{
					arr[i][j] = 1;
					if (i==0 || (i+1 == m))
						num_entry++;
					else if (j==0 || (j+1 == n))
						num_entry++;
					if (num_entry == 1 && !start)
						start_x=i,start_y=j, start=1; 
					if (num_entry == 2 && !end)
						end_x=i,end_y=j, end=1; 
				}
				
			}
			scanf ("\n");
			//printf ("\n");
		}
		//dump_maze(m, n);
		if (!(num_entry == 2))
			printf ("invalid\n");
		else
		{
	//		printf ("[%d,%d]->[%d,%d]\n", start_x, start_y, end_x, end_y);
			if (do_process(start_x, start_y))
				printf ("valid\n");
			else
				printf ("invalid\n");
		}
		//reset
		{
		int i, j;
		for (i=0; i < m; i++)
			for (j=0; j < n; j++)
			{
				visited[i][j]=0;
				arr[i][j]=0;
			}
		}
	}
	return 0;
}
