#include <iostream>

void printgrid(int grid[3][3]);
bool checkwin(int, int grid[3][3]);
void resetgrid(int (&grid)[3][3]);

int Xwins = 0;
int Owins = 0;
char turn = 'X';


using namespace std;

int main()
{
  int grid[3][3] = {0};
  bool running = true;
  char coords[2];
    
  printgrid(grid);
  while(running == true)
    {
      cout << "value at a1: " << grid[0][0] << endl; 
      cout << turn << "'s turn. Enter coords (letter first):" << endl;
      cout << "value at a1: " << grid[0][0] << endl;
      cin.get(coords, 3);
      cout << "value at a1: " << grid[0][0] << endl;
      cin.get();
      cout << "value at a1: " << grid[0][0] << endl;
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
  printgrid(grid);
  if(checkwin(1, grid) == true)
    {
      cout << "Player X has won!" << endl;
      Xwins++;
      resetgrid(grid);
    }
  if(checkwin(2, grid) == true)
    {
      cout << "Player O has won!" << endl;
      Owins++;
      resetgrid(grid);
    }
  //running = false;
    }
}

//prints visual tictactoe grid
void printgrid(int grid[3][3])
{
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

  //checks if a player has gotten 3 in a row
  bool checkwin(int player, int grid[3][3])
  {
    if(grid[0][0] == player && grid[0][1] == player && grid[0][2] == player)
      {
	return true;
      }
    if(grid[1][0] == player && grid[1][1] == player && grid[1][2] == player)
      {
	return true;
      }
    if(grid[2][0] == player && grid[2][1] == player && grid[2][2] == player)
      {
	return true;
      }
    if(grid[0][0] == player && grid[1][0] == player && grid[2][0] == player)
      {
	return true;
      }
    if(grid[0][1] == player && grid[1][1] == player && grid[2][1] == player)
      {
	return true;
      }
    if(grid[0][2] == player && grid[1][2] == player && grid[2][2] == player)
      {
	return true;
      }
    if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
      {
	return true;
      }
    if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
      {
	return true;
      }
      return false;
  }

void resetgrid(int (&grid)[3][3])
{
  cout << "X total wins: " << Xwins << endl;
  cout << "O total wins: " << Owins << endl;
  for(int y = 0; y < 3; y++)
    {
      for(int x = 0; x < 3; x++)
	{
	  grid[y][x] = 0;
	}
    }
  turn = 'X';
  printgrid(grid);
}


