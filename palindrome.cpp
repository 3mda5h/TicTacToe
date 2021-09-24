#include <iostream>
#include <cstring>
#include <cctype>
#include <ctype.h>

using namespace std;

int main()
{
  char input[80];
  char lettersonly[80];
  char backwards[80];

  cin.get(input, 81);
  cin.get();
  int count = 0;

  for (int i = 0; i < 80; i++)
    {
      if(isalpha(input[i])) //if letter
        {
          lettersonly[count] = tolower(input[i]); //makes lowercase
          count++;
        }
    }
  lettersonly[count] = '\0';
  
  //puts in letters backwards
  count = 0;
  for (int i = (strlen(lettersonly) - 1); i >  -1; i = i-1)
    {
     	backwards[count] = lettersonly[i];
	count++;
    }
  backwards[count] = '\0';

  if(strcmp(lettersonly, backwards) == 0) //if strings are equal
    {
      cout << "is a palindrome" << endl;
    }
  else
    {
      cout << "is not a palindrome" << endl;
    }  
}
