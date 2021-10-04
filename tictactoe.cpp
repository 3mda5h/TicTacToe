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
      cout << turn << "'s turn. Enter coords (letter first):" << endl;
      cin.get(coords, 3);
      cin.get();
      bool validcoords = false;
      while(validcoords == false)
	{
	  if((coords[0] == 'a'||coords[0] == 'b' || coords[0] == 'c') && (coords[1] == '1' ||
								    coords[1] == '2' || coords[1] == '3'))
	    {
	      //if the coords are empty
	      if(grid[int(coords[0]) - 97][(int)coords[1] - 49] == 0)
		{
		  if(turn == 'X')
		    { 
		      cout << "called" << endl;
		      grid[int(coords[0]) - 97][(int)coords[1] - 49] = 1;
		      turn = 'O';
		      validcoords = true;
		    }
		  else
		    {
		      grid[int(coords[0]) - 97][(int)coords[1] - 49] = 2;
		      turn = 'X';
		      validcoords = true;
		    }
		} 
	      //if coords have been played
	      else
		{
		  cout << "These coords have already been played. Try again:" << endl;
		  cin.get(coords, 3);
		  cin.get();
		}
	    }
	  else
	    {
	      cout << "Invalid coords. Try again:" << endl;
	      cin.get(coords, 3);
	      cin.get();
	    }
	}
      cout << "Value at a1: " << grid[0][0] << endl;   
  printgrid(grid);
  //check for win
  //running = false;
    }
}

void printgrid(int grid[3][3])
{
  //cout << grid[1][0] << endl;
  cout << "    1   2   3" << endl;
  cout << endl;
  int letter = 97;
  for(int y = 0; y < 3; y++)
    {
      cout << (char)letter;
      letter++;
      for(int x = 0; x < 3; x++)
        {
	  //cout << y << ", " << x << ": " << grid[y][x] << endl;
	  if(grid[y][x] == 0) //empty
	    {
	      cout << "    ";
	    }
	  else if(grid[y][x] == 1) //x
	    {
	      cout << "   X";
	    }
	  else if(grid[y][x] == 2) //o
	    {
	      cout << "   O";
	    }
	 }
      cout << endl;
      cout << endl;
    }
  
}
