// Najczêstsza wartoœæ
// Data:   4.05.2008
<<<<<<< HEAD
// (C)2012 mgr marganski Wa³aszek
=======
// (C)2012 mgr mikolaj Wa³aszek
>>>>>>> tak
//---------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  const int N = 400;
  int Z[N],i,j,L,W,maxL,maxW;

// Generujemy zawartoœæ Z[]

  srand((unsigned)time(NULL));
  for(i = 0; i < N; i++) Z[i] = rand() % 100;

// Wyszukujemy najczêstsz¹ wartoœæ

  maxL = 0;
  for(i = 0; i < N; i++)
  {
    W = Z[i]; L = 0;
    for(j = 0; j < N; j++) if(Z[j] == W) L++;
    if(L > maxL)
    {
      maxL = L; maxW = W;
    }
  }//Mikołaj tutaj edytowałem sobie rzeczy :))))))))))))

// Wypisujemy tablicê

  for(i = 0; i < N; i++)
    if(Z[i] == maxW) cout << " >" << setw(2) << Z[i];
    else             cout << setw(4) << Z[i];

// Wypisujemy najczêstszy element
// oraz liczbê wyst¹pieñ

  cout << endl << maxW << " : " << maxL << endl << endl;
  return 0;
}
