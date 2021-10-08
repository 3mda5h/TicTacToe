#include <iostream>

void printgrid(char grid[3][3]);
bool checkwin(char, char grid[3][3]);
void newgame(char (&grid)[3][3]);

int Xwins = 0;
int Owins = 0;
char turn = 'X';
int movecount = 0;

using namespace std;

int main()
{
  char grid[3][3];
  bool running = true;
  char coords[3];

  newgame(grid);
  while(running == true)
    { 
      cout << turn << "'s turn. Enter coords (letter first):" << endl;
      cin.get(coords, 3);
      cin.get();
      bool validcoords = false;
      while(validcoords == false)
	{
	  //if coords are valid
	  if((coords[0] == 'a'||coords[0] == 'b' || coords[0] == 'c') && (coords[1] == '1' ||
								    coords[1] == '2' || coords[1] == '3'))
	    {
	      //if the coords are empty
	      if(grid[int(coords[0]) - 97][(int)coords[1] - 49] == ' ')
		{
		  movecount++;
		  if(turn == 'X')
		    { 
		      grid[int(coords[0]) - 97][(int)coords[1] - 49] = 'X';
		      turn = 'O';
		      validcoords = true;
		    }
 		  else
		    {
		      
		      grid[int(coords[0]) - 97][(int)coords[1] - 49] = 'O';
		      turn = 'X';
		      validcoords = true;
		    }
		} 
	      //if coords have already been played
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
      if(checkwin('X', grid) == true)//x has won
	{
	  cout << "Player X has won!" << endl;
	  Xwins++;
	  newgame(grid);
	}
      else if(checkwin('O', grid) == true)//o has won
	{
	  cout << "Player O has won!" << endl;
	  Owins++;
	  newgame(grid);
	}
      else if(movecount == 9) //if board is full and no one has won, it's a tie 
	{
	  cout << "There has been a tie" << endl;
	  newgame(grid);
	}
    }
}

//prints visual tictactoe grid
void printgrid(char grid[3][3])
{
  cout << endl;
  cout << "    1   2   3" << endl;
  cout << endl;
  int letter = 97;
  for(int y = 0; y < 3; y++)
    {
      cout << (char)letter;
      letter++;
      for(int x = 0; x < 3; x++)
        {
	  cout << "   " << grid[y][x];
	}
      cout << endl;
      cout << endl;
    }
}

  //checks if a player has gotten 3 in a row
  bool checkwin(char player, char grid[3][3])
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

//makes grid empty and starts a new game
void newgame(char (&grid)[3][3])
{
  cout << endl;
  cout << "X total wins: " << Xwins << endl;
  cout << "O total wins: " << Owins << endl;
  for(int y = 0; y < 3; y++)
    {
      for(int x = 0; x < 3; x++)
	{
	  grid[y][x] = ' ';
	}
    }
  movecount = 0;
  turn = 'X';
  printgrid(grid);
}
