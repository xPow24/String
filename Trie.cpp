#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5*1e5;
int trie[MAXN][26], finish[MAXN], node;
void buildTrie(string s) {
  int cur = 0, n = s.size();
  for (int i = 0; i < n; ++i) {
    int tt = s[i] - 'a';
    if (trie[cur][tt] == 0) trie[cur][tt] = ++node;
    cur = trie[cur][tt];
  }
  finish[cur]++;
}
int main() {
  int n;
  string ss;
  cin >> n;
  while (n--) {
    cin >> ss;
    buildTrie(ss);
  }
}
