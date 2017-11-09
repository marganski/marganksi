// Wyszukiwanie max i min
// Data:   28.04.2008
// (C)2012 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 15;

int main()
{
  int Z[N],i,maxZ,minZ;

  srand((unsigned)time(NULL));
  for(i = 0; i < N; i++) Z[i] = rand() % 10000;
  maxZ = minZ = Z[0];
  for(i = 1; i < N; i++)
  {
    if(Z[i] > maxZ) maxZ = Z[i];
    if(Z[i] < minZ) minZ = Z[i];
  }
  for(i = 0; i < N; i++) cout << setw(5) << Z[i] << endl;
  cout << endl << setw(5) << minZ << setw(5) << maxZ << endl << endl;
  return 0;
} 