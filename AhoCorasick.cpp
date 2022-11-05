#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 2;
int trie[MAXN][26], link[MAXN], dic[MAXN], endp[MAXN];
void buildAho() {
  fill(trie[0], trie[0] + 26, 1);
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    dic[v] = endp[link[v]] >= 0 ? link[v] : dic[link[v]];
    for (int i = 0; i < 26; ++i) {
      if (trie[v][i] == 0) trie[v][i] = trie[link[v]][i]; //create "fake" node is it's longest suffix contains that letter
      else {
        link[trie[v][i]] = trie[link[v]][i];
        q.push(trie[v][i]);
      }
    }
  }
}
int main() {
  int n, node = 2;
  cin >> n;
  memset(endp, -1, sizeof(endp));
  for (int i = 0; i < n; ++i) {
    int p = 1;
    string s;
    cin >> s; 
    for (char c : s) {
      if (trie[p][c - 'a'] == 0) trie[p][c - 'a'] = node++;
      p = trie[p][c - 'a'];
    }
    endp[p] = 0;  
  }
  buildAho();
  return 0;
}
