<h1> Sudoku Solver </h1>
<hr>
<p> Sudoku Solver is one of the classic problems. It is widely asked in technical interviews. Usually a sudoku puzzle is a 9x9 grid matrix containing integers from 1 to 9 jumbled in such a way that every row, every column and every 3x3 matrix, each integer appears only once. We can solve this traditional problem using backtracking. </p>
<hr>
<h3> <b> Problem Statement</b> </h3>
<br>
<p>You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
To learn more about sudoku, go to this link Sudoku-Wikipedia.
<br><br>
  <b>Input Format</b><br>
First line contains a single integer N. Next N lines contains N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid. This value is 0, if the cell is empty.
<br><br>
  <b>Constraints</b><br>
N=9 Solution exists for input matrix.
<br><br>
  <b>Output Format</b><br>
Print N lines containing N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid, such that all cells are filled.
<br><br>
  <b>Sample Input</b><br>
9 <br>
5 3 0 0 7 0 0 0 0 <br>
6 0 0 1 9 5 0 0 0 <br>
0 9 8 0 0 0 0 6 0 <br>
8 0 0 0 6 0 0 0 3 <br>
4 0 0 8 0 3 0 0 1 <br>
7 0 0 0 2 0 0 0 6 <br>
0 6 0 0 0 0 2 8 0 <br>
0 0 0 4 1 9 0 0 5 <br>
0 0 0 0 8 0 0 7 9 <br><br>
  <b>Sample Output</b><br>
5 3 4 6 7 8 9 1 2 <br> 
6 7 2 1 9 5 3 4 8 <br>
1 9 8 3 4 2 5 6 7 <br>
8 5 9 7 6 1 4 2 3 <br>
4 2 6 8 5 3 7 9 1 <br>
7 1 3 9 2 4 8 5 6 <br>
9 6 1 5 3 7 2 8 4 <br>
2 8 7 4 1 9 6 3 5 <br>
3 4 5 2 8 6 1 7 9 </p>
<br>
<h2> Approach: </h2>
<p>
<ol>
	<li> Create a function 'issafe' to check whether the current element is safe to be assigned to the current index. 
	<ol>
		<li> Check if the element already exists in the current column
		<li> Check if the element already exists in the current row
		<li> Check if the element already exists in the current 3x3 grid
		<li> If the element is safe till now, then return true 
	</ol>
	<li> Create a function 'solve' to recursively solve the grid
	<ol>
		<li> Firstly, check if we've reached at the end of the 2D matrix. If yes, then print the final matrix
		<li> Secondly, check if we've reached at the end of the current row. If yes, then move to the next row
		<li> Check if the current index is filled or not. 
			<ol>
				<li> If yes, move ahead by recursively calling 'solve' function. 
				<li> If no, call the 'issafe' function for every integer from 1-9
					<ol>
						<li> If the current element return true, save it and continue, else move ahead
					</ol>
		<li> If no element fits, backtrack and return false
	</ol>
</ol>
</ol>
<br> <br>
<h2> Using Recursion in Cpp </h2>

```cpp
#include<bits/stdc++.h>
using namespace std;

bool issafe(int s[100][100], int N, int i, int j, int ele)
{
	//check if the element is present in same column
	for(int k=0;k<N;k++)
	 if(s[i][k]==ele)
	  return false;
	//check if ele is present in same row
	for(int k=0;k<N;k++)
	 if(s[k][j]==ele)
	  return false;
	//check if ele is present in the grid box
	int rn=sqrt(N);
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;
	for(int x=sx;x<sx+rn;x++)
	 for(int y=sy;y<sy+rn;y++)
	  if(s[x][y]==ele)
	   return false;

	//if not found element till now then good to go
	return true;
}

void print(int s[100][100], int N)
{
	//print the final answer
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
	      cout<<s[i][j]<<" ";
		cout<<endl;
	}
}

bool solve(int s[100][100], int N, int i, int j, int max)
{
	//base case
	//if we reach till the last box at the end then print
	if(i==N)
	{
		//print the grid
		print(s, N);
		return true;
	}
	//after traversing through one row change the row
	if(j==N)
	 return solve(s, N, i+1, 0, max);

	//recursive function
	//if place is already filled, move on
	if(s[i][j]!=0)
	 return solve(s, N, i,j+1, max);
	//if current pos is empty
	else
	{
		//loop to choose the correct number to put in current pos
		for(int k=1;k<=max;k++)
		{
			//if the chosen element fits right in, then fix it and continue
			if(issafe(s, N, i, j, k))
			{
				s[i][j]=k;
				if (solve(s, N, i, j+1, max))
				  return true;
			}
		}
		//if wrong element gets chosen, backtrack and return false
		s[i][j]=0;
		return false; 
	}
}

int main() {
	int N;
	cin>>N;
	int s[100][100];

	//taking input
	for(int i=0;i<N;i++)
	 for(int j=0;j<N;j++)
	   cin>>s[i][j];

	if(!solve(s,N,0,0,9))
	 cout<<"CANNOT SOLVE!";
	return 0;
}
```
<br>
<h3> Complexity Analysis </h3>
<p><h> Time Complexity: </h>
<br>
O(9^k) where k is the number of unfilled elements. <br>
<h>Space Complexity: </h>
<br>
O(n*n) where n is the number of rows and columns of the sudoku 2D matrix

