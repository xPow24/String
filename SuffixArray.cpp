#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
const int MAXN = 1 << 21;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j) {
  if (pos[i] != pos[j]) return pos[i] < pos[j];
  i += gap;
  j += gap;
  return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(string SS) {
  N = SS.size();
  REP(i, N) {
    sa[i] = i; 
    pos[i] = SS[i];
  }
  for (gap = 1;; gap *= 2) {             
    sort(sa, sa + N, sufCmp);
    REP(i, N - 1) {
      tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
    }
    REP(i, N) pos[sa[i]] = tmp[i];
    if (tmp[N - 1] == N - 1) break; 
  }
}

void buildLCP(string SS) {
  lcp[0] = 0;
  for (int i = 0, k = 0; i < N; ++i) {
    if (pos[i]) {
      for (int j = sa[pos[i] - 1]; SS[i + k] == SS[j + k];)
      ++k;
      lcp[pos[i]] = k;
      if (k) --k;
    }
  }
}

int main() {
  string s;
  cin >> s;
  buildSA(s); buildLCP(s);
  REP(i, N) cout << lcp[i] << ' ';
  return 0;
}
