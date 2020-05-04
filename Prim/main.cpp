#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  int L[10000], T[10000], D[10000];
  int W[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 2, 9999, 10, 9999},
    {0, 9999, 0, 9, 9999, 5},
    {0, 12, 9999, 0, 6, 9999},
    {0, 9999, 9999, 9999, 0, 7},
    {0, 9999, 9999, 3, 9999, 0}
  };
  int n = 5;
  vector< pair<int, int> > S;

  for(int i = 1; i <= n; i++)
  {
    L[i] = W[1][i];
    D[i] = W[1][i];
    T[i] = 1;
  }

  int vmin;
  for(int k = 0; k < n - 1; k++)
  {
    int min = 9999;

    for(int i = 2; i <= n; i++)
    {
      if(0 <= L[i] && L[i] <= min) 
      {
        min = L[i];
        vmin = i;
      }
    }

    pair<int, int> e = make_pair(T[vmin], vmin);
    S.push_back(e);

    for(int i = 2; i <= n; i++)
    {
      if(W[vmin][i] < L[i])
      {
        D[i] = L[i];
        L[i] = W[vmin][i];
        T[i] = vmin;
      }
    }
    L[vmin] = -1;
  }

  for(int i = 0; i < S.size(); i++)
  {
    cout << "(" << S[i].first << ", " << S[i].second << ")" << endl;
  }

  int res = 0;
  for(int i = 1; i <= n; i++)
  {
    res += D[i];
  }
  cout << res;
}