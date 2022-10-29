#include <bits/stdc++.h>
using namespace std;
const char DUMMY = '.';

void manacher(string s) 
{
  int n = s.size()*2 - 1;
  vector<int> f(n, 0);
  string a(n, DUMMY);
  for (int i = 0; i < n; i += 2) a[i] = s[i/2];
  int l = 0, r = -1, center, res = 0;
  for (int i = 0, j = 0; i < n; i++) 
  {
    j = max(0, min(f[l + r - i], r - i)) + 1;
    
    //Ly do ta chon min la vi 2 truong hop sau day r - i > f[l + r - i] (1) hoac r - i < f[l + r - i] (2)
    
    /*Voi (1) thi ta phai chon f[l + r - i] vi khi i toa ra 2 phia r - i phan tu thi chua chac da la palindrome, nhung 
    	tu i toa ra 2 phia f[l + r - i] phan tu thi doan do chac chan van la palindrome (vi s[l...r] da la palindrome)*/
    
    /*Voi (2) thi ta phai chon r - i vi neu nhu i toa ra 2 phia f[l + r - i] phan tu thi r da phai lon hon roi, hay kich co cua chuoi palindrome
    	s[l...r] phai lon hon va tu i toa ra 2 phia r - i phan tu thi doan do chac chan van la palindrome (vi r - i < f[l + r - i] && r - i <= r)*/ 
    	
    while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
    f[i] = --j;
    if (i + j > r) {
      r = i + j;
      l = i - j;
    }	   	
    int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2; 
    if (len > res) {
      res = len;
      center = i; //luu lai tam cua chuoi palindrome do neu muon lam gi do
    }   
  }
  cout << res << endl;
}


int main() 
{
  int n;
  string s;
  cin >> n >> s;
  manacher(s);
  return 0;
}
