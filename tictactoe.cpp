#include <iostream>

void printgrid(int grid[3][3]);

using namespace std;

int main()
{
  int grid[3][3] = {0};
  printgrid(grid);
  grid[3][1] = 2;
  cout << grid[3][1] << endl;
  printgrid(grid);
}

void printgrid(int grid[3][3])
{
  cout << grid[3][1] << endl;
  cout << "   a  b  c" << endl;
  int num = 1;
  for(int y = 0; y < 3; y++)
    {
      cout << num;
      num++;
      for(int x = 0; x < 3; x++)
        {
	  if(grid[y][x] == 0) //empty
	    {
	      cout << "   ";
	    }
	  else if(grid[y][x] == 1) //x
	    {
	      cout << "  X";
	    }
	  else if(grid[y][x] == 2)
	    {
	      cout << "  Y";
	    } 
	 }
      cout << endl;
    }
  
}
