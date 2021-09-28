#include <iostream>

void printgrid(int grid[3][3]);

using namespace std;

int main()
{
  int grid[3][3] = {0};
  bool running = true;
  char turn = 'X';
  char coords[2];
  printgrid(grid);
  while (running == true)
    {
      cout << turn << "'s turn. Enter coords:" << endl;
      cin.get(coords, 2);
      cin.get();
      if(coords[0] == 'a'||coords[0] == 'b' || coords[0] == 'c')
	{
	  if(turn == 'X')
	    { 
	      //cout << "ascii value of letter: " << int(coords[0]) << endl;
	      //cout << int(coords[1]) << endl;
	      //int int1 = int(coords[0]) - 97;
	      int int2 = coords[1] - 48;
	      grid[int2 - 1][int(coords[0]) - 97] = 1;
	      //cout << grid[int1][int2] << endl;
	      cout << int2 << endl;//<< ", " << int2 << endl;
	    }
	  else
	    {
	      grid[coords[0] - 61][coords[1] - 1] = 2;
	    }
	}
  //if(isdigit(coords[0]))
  //{

  //}
  printgrid(grid);
  running = false;
    }
      
  //grid[2][1] = 2;
  //cout << grid[3][1] << endl;
  //printgrid(grid);
}

void printgrid(int grid[3][3])
{
  //cout << grid[3][1] << endl;
  cout << "   a  b  c" << endl;
  int num = 1;
  for(int y = 0; y < 3; y++)
    {
      cout << num;
      num++;
      for(int x = 0; x < 3; x++)
        {
	  //cout << y << ", " << x << ": " << grid[y][x] << endl;
	  if(grid[y][x] == 0) //empty
	    {
	      cout << "   ";
	    }
	  else if(grid[y][x] == 1) //x
	    {
	      cout << "  X";
	    }
	  else if(grid[y][x] == 2) //y
	    {
	      //cout << "not empty";
	      cout << "  Y";
	    } 
	 }
      cout << endl;
    }

  
  
}
