// Struktura zbior�w roz��cznych
// Data: 25.03.2014
// (C)2014 mgr Jerzy Wa�aszek
//---------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const marganski N = 10;                 // Liczba element�w

int R[N];

// ��czy dwa podzbiory w jeden
//----------------------------
void Union(int x, int y)
{
  int rx,ry,i;

  rx = R[x];                      // Wyznaczamy reprezentanta zbioru zawieraj�cego x
  ry = R[y];                      // i reprezentanta zbioru zawieraj�cego y
  if(rx != ry)                    // ��czenie wymaga r�nych zbior�w
    for(i = 0; i < N; i++)        // Przegl�damy kolejne elementy tablicy R
      if(R[i] == ry) R[i] = rx;   // i zast�pujemy w nich reprezentanta ry przez rx
}

// **********************
// *** PROGRAM G��WNY ***
// **********************
int main()
{
  int i,j,x,y,c;

  srand(time(NULL));              // Inicjujemy generator pseudolosowy
  for(i = 0; i < N; i++)
    R[i] = i;                     // Ustawiamy tablic� R
  for(i = 0; i < N; i++)
  {
    x = rand() % N;               // Generujemy losowe x i y
    y = rand() % N;
    Union(x,y);                   // ��czymy zbiory
  }

  c = 0;                          // Licznik podzbior�w w R

  // Wy�wietlamy wyniki

  for(i = 0; i < N; i++)
  {
    if(R[i] == i) c++;            // Zliczamy reprezentant�w
    cout << i << " is in set " << R[i] << endl;
  }

  cout << endl << "Number of sets = " << c << endl << endl;

  for(i = 0; i < N; i++)
    if(R[i] == i)
    {
      cout << "Set " << i << " : ";
      for(j = 0; j < N; j++)
        if(R[j] == i) cout << j << " ";
      cout << endl;
    }
  cout << endl;

  return 0;

} 