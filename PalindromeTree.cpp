#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105000;
struct node {
  int next[26];
  int len;
  int sufflink;
  int num;
};
string s;
node tree[MAXN]; 
int num;  // total number of nodes already have, node 1 has root with len -1, node 2 has root with len 0
int suff; // index of the longest suffix palindrome from the previous prefix
long long ans;
void initTree() {
  num = 2; suff = 2;
  tree[1].len = -1; tree[1].sufflink = 1;
  tree[2].len = 0; tree[2].sufflink = 1;
}
void addLetter(int pos) {
  int cur = suff, curlen;
  int cc = s[pos] - 'a';
  while (true) {
    curlen = tree[cur].len;
    if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) break;
    cur = tree[cur].sufflink;
  }
  if (tree[cur].next[cc]) {
    suff = tree[cur].next[cc];
    return;
  }
  suff = ++num;
  tree[num].len = tree[cur].len + 2;
  tree[cur].next[cc] = num;
  if (tree[num].len == 1) {
    tree[num].sufflink = 2;
    tree[num].num = 1;
    return;
  }
  while (true) {
    cur = tree[cur].sufflink;
    curlen = tree[cur].len;
    if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
      tree[num].sufflink = tree[cur].next[cc];
      break;
    }
  }
  tree[num].num = tree[tree[num].sufflink].num + 1;
}
int main() {
  int n;
  //cin >> s;
  s = "eertree";
  n = s.size();
  initTree();
  for (int i = 0; i < n; i++) {
    addLetter(i);
    ans += tree[suff].num;
  }
  cout << ans << endl;
  return 0;
}
