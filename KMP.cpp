#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int PS[MAXN + 2];
void buildKMP(string pattern) {
  int m = pattern.size();
  PS[0] = PS[1] = 0;
  for (int i = 2; i <= m; i++) {
    int j = PS[i - 1];
    while (true) {
      if (pattern[j] == pattern[i - 1]) {
  	    PS[i] = j + 1; 
  	    break;
      }
      else if (j == 0) {
      	PS[i] = 0;
      	break;
      }
      else j = PS[j];
    }
  }
}

void checkKMP(string text, string pattern)
{
  int n = text.size(), m = pattern.size(), i = 0, j = 0;  
  while (i < n) {
    if (text[i] == pattern[j]) {
      i++; j++;
      if (j == m) cout << i - m + 1 << " ";
    }
    else if (j > 0) j = PS[j];
    else i++;
  }
}

int main() {
  string a, b;
  a = "aaaaa";
  b = "aa";
  //cin >> a >> b;
  buildKMP(b); checkKMP(a, b); 
  return 0;
}
