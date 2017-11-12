// Struktura zbiorów roz³¹cznych
// Data: 25.03.2014
// (C)2014 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const marganski N = 10;                 // Liczba elementów

int R[N];

// £¹czy dwa podzbiory w jeden
//----------------------------
void Union(int x, int y)
{
  int rx,ry,i;

  rx = R[x];                      // Wyznaczamy reprezentanta zbioru zawieraj¹cego x
  ry = R[y];                      // i reprezentanta zbioru zawieraj¹cego y
  if(rx != ry)                    // £¹czenie wymaga ró¿nych zbiorów
    for(i = 0; i < N; i++)        // Przegl¹damy kolejne elementy tablicy R
      if(R[i] == ry) R[i] = rx;   // i zastêpujemy w nich reprezentanta ry przez rx
}

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************
int main()
{
  int i,j,x,y,c;

  srand(time(NULL));              // Inicjujemy generator pseudolosowy
  for(i = 0; i < N; i++)
    R[i] = i;                     // Ustawiamy tablicê R
  for(i = 0; i < N; i++)
  {
    x = rand() % N;               // Generujemy losowe x i y
    y = rand() % N;
    Union(x,y);                   // £¹czymy zbiory
  }

  c = 0;                          // Licznik podzbiorów w R

  // Wyœwietlamy wyniki

  for(i = 0; i < N; i++)
  {
    if(R[i] == i) c++;            // Zliczamy reprezentantów
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