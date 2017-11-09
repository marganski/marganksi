// Sumy prefiksowe
// Data: 26.09.2015
// (C)2015 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 15;                   // Liczba elementów
const int M = 10;                   // Liczba sum czêœciowych

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************

int main()
{
  int T[N],S[N+1],i,j,k;

  srand(time(NULL));       // Inicjujemy generator pseudolosowy
  for(k = 0; k < N; k++)            // Ustawiamy tablicê T
    T[k] = (rand() % N) - (rand() % N);
  S[0] = 0;
  for(k = 0; k < N; k++)            // Wyliczamy sumy prefiksowe
    S[k+1] = S[k] + T[k];
  cout << "T = ";                   // Wyœwietlamy obie tablice
  for(k = 0; k < N; k++) cout << setw(4) <<T[k];
  cout << endl << "S = ";
  for(k = 0; k <= N; k++) cout << setw(4) << S[k];
  cout << endl << endl;
  for(k = 0; k < M; k++)            // Wyliczamy sumy czêœciowe
  {
    i = rand() % N;  // Losujemy indeksy
    j = rand() % N;
    if(i > j) swap(i,j);
    cout << "Suma od T[" << setw(2) << i
         << "] do T["    << setw(2) << j
         << "] wynosi "  << S[j+1]-S[i] << endl;
  }
  return 0;
} 