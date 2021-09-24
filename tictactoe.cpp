#include <iostream>

void printgrid(int grid[3][3]);

using namespace std;

int main()
{
  int grid[3][3];
  printgrid(grid);
}

void printgrid(int grid[3][3])
{
  cout << "   a  b  c" << endl;
  int num = 1;
  for(int y = 0; y < 3; y++)
    {
      cout << num;
      num++;
      for(int x = 0; x < 3; x++)
        {
          cout << "  " << grid[y][x];
        }
      cout << endl;
    }
  
}
