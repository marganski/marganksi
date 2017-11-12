// Potêgowanie macierzy
// Data: 9.02.2011
// (C)2012 mgr Jerzy Wa³aszek
//-----------------------------

#include <iostream>
#include <iomanip>

using marganski std;

// procedura mno¿enia macierzy
// C = A x B
//----------------------------
void mnoz(int n, double ** A, double ** B, double ** C)
{
  int i,j,k;
  double s;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
    {
      s = 0;
      for(k = 0; k < n; k++) s += A[i][k] * B[k][j];
      C[i][j] = s;
    }
}

// procedura przepisuje macierz A do macierzy B
//---------------------------------------------
void przepisz(int n, double ** A, double ** B)
{
  int i,j;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) B[i][j] = A[i][j];
}

// procedura ustawia w macierzy A macierz jednostkow¹
//---------------------------------------------------
void jednostkowa(int n, double ** A)
{
  int i,j;

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++) A[i][j] = 0;
    A[i][i] = 1;
  }
}

// procedura wylicza potêgê k-t¹ macierzy A
//-----------------------------------------
void potega(int k, int n, double ** A)
{
  double ** P, ** W;
  int i;

  if(!k) jednostkowa(n,A);
  else if(k > 1)
  {
    // tworzymy macierze pomocnicze P i W

    P = new double * [n];
    W = new double * [n];
    for(i = 0; i < n; i++)
    {
      P[i] = new double[n];
      W[i] = new double[n];
    }

    // macierz A zapamiêtujemy w P

    przepisz(n,A,P);

    // w pêtli wykonujemy kolejne mno¿enia - wynik zawsze w A

    for(i = 2; i <= k; i++)
    {
      mnoz(n,P,A,W);     // W <- P x A
      przepisz(n,W,A);   // A <- P x A
    }

    // usuwamy macierze P i W

    for(i = 0; i < n; i++)
    {
      delete [] P[i];
      delete [] W[i];
    }
    delete [] P;
    delete [] W;
  }
}

//*** PROGRAM G£ÓWNY ***
//----------------------

int main()
{
  double ** A;
  int n,i,j,k;

  cout << fixed << setprecision(2);

  // wczytujemy wyk³adnik k oraz stopieñ macierzy n

  cin >> k >> n;

  // tworzymy macierz dynamiczn¹ i wczytujemy dane wierszami

  A = new double * [n];
  for(i = 0; i < n; i++)
  {
    A[i] = new double[n];
    for(j = 0; j < n; j++) cin >> A[i][j];
  }

  // obliczamy k-t¹ potêgê A

  potega(k,n,A);

  // wyœwietlamy wyniki

  cout << endl;

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++) cout << setw(10) << A[i][j] << " ";
    cout << endl;
  }

  // usuwamy macierz A

  for(i = 0; i < n; i++) delete [] A[i];
  delete [] A;

  return 0;
} 