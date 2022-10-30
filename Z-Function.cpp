#include<bits/stdc++.h>
using namespace std;
vector<int> buildZ(string p) {
  int n = p.size(), l = 0, r = 0;
  vector<int> z(n, 0);
  for (int i = 1; i < n; ++i) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && p[z[i]] == p[i + z[i]]) ++z[i]; 
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }    
  }
  return vector<int>(begin(z), end(z));
}
void check(string zz, string yy) {
  vector<int> p = buildZ(zz);
  int m = yy.size(), n = zz.size();
  for (int i = m + 1; i < n; ++i) {
    if (p[i] >= m) cout << i - m << ' ';
  }
}
int main() {
  string s, y, p;
  cin >> s >> y;
  p = y + '#' + s;
  check(p, y);
}
