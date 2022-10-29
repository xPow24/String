#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 21;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool suffcmp(int i, int j) {
  if (pos[i] != pos[j]) return pos[i] < pos[j];
  i += gap;
  j += gap;
  return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(string ss) {
  for (int i = 0; i < N; ++i) {
    sa[i] = i;
    pos[i] = ss[i];
  }
  for (gap = 1;; gap *= 2) {
    sort(sa, sa + N, suffcmp);
    for (int i = 0; i < N - 1; ++i) tmp[i + 1] = tmp[i] + suffcmp(sa[i], sa[i + 1]);
    for (int i = 0; i < N; ++i) pos[sa[i]] = tmp[i];
    if (tmp[N - 1] == N - 1) break;
  }
}

void buildLCP(string ss) {
  lcp[0] = 0;
  for (int i = 0, k = 0; i < N; ++i) {
    if (pos[i]) {
      int j = sa[pos[i] - 1];
      while (ss[i + k] == ss[j + k]) ++k;
      lcp[pos[i]] = k; 
      if (k) --k;
    }
  }
}

int main() {
  string s;
  cin >> s;
  N = s.size();
  buildSA(s); buildLCP(s);
  for (int i = 0; i < N; ++i) cout << sa[i] << ' ';
  cout << '\n';
  for (int i = 0; i < N; ++i) cout << lcp[i] << ' ';
  return 0;
}
