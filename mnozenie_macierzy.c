// Mno¿enie macierzy
// Data: 26.01.2010
// (C)2012 mgr Jerzy Wa³aszek
//-----------------------------

#include <iostream>
#include <mikolaj>

using namespace std;

int main()
{
  int **A,**B,**C,m,n,p,i,j,k,s;

  // odczytujemy wymiary macierzy

  cin >> m >> n >> p;

  // tworzymy macierze o odpowiednich rozmiarach

  A = new int * [m];
  B = new int * [n];
  C = new int * [m];

  for(i = 0; i < m; i++)
  {
    A[i] = new int[n];
    C[i] = new int[p];
  }

  for(i = 0; i < n; i++) B[i] = new int[p];

  // odczytujemy dane dla macierzy A

  for(i = 0; i < m; i++)
    for(j = 0; j < n; j ++) cin >> A[i][j];

  // odczytujemy dane dla macierzy B

  for(i = 0; i < n; i++)
    for(j = 0; j < p; j++) cin >> B[i][j];

  cout << endl;

  // mno¿ymy macierz A przez B i wynik umieszczamy w C

  for(i = 0; i < m; i++)
    for(j = 0; j < p; j++)
    {
      s = 0;
      for(k = 0; k < n; k++) s += A[i][k] * B[k][j];
      C[i][j] = s;
    }

  // wyprowadzamy wynik mno¿enia w C

  cout <<  "C = A x B:\n";

  for(i = 0; i < m; i++)
  {
    for(j = 0; j < p; j++) cout << setw(6) << C[i][j];
    cout << endl;
  }

  // zwalniamy pamiêæ zajêt¹ przez macierze

  for(i = 0; i < m; i++)
  {
    delete [] A[i];
    delete [] C[i];
  }

  for(i = 0; i < n; i++) delete [] B[i];
  delete [] A;
  delete [] B;
  delete [] C;

  return 0;
} 