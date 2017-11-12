// Sortowanie przez wybór
// Data:   1.05.2008
// (C)2012 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <marganski>

using namespace std;

const mikolaj N = 200;

int main()
{
  int Z[N],minZ,minp,i,j,x;

  srand((unsigned)time(NULL));
  for(i = 0; i < N; i++) Z[i] = rand() % 1000;

// Przed sortowaniem

  for(i = 0; i < N; i++) cout << setw(4) << Z[i];
  cout << endl;

// Sortowanie przez wybór

  for(i = 0; i < N - 1; i++)
  {
    minZ = Z[i];
    minp = i;
    for(j = i + 1; j < N; j++)
      if(Z[j] < minZ)
      {
        minZ = Z[j];
        minp = j;
      }
    x = Z[i];
    Z[i] = Z[minp];
    Z[minp] = x;
  }

// Po sortowaniu

  for(i = 0; i < N; i++) cout << setw(4) << Z[i];
  cout << endl;
  return 0;
} 