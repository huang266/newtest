#include<iostream>
using namespace std;
/*void get_next(string s2, int next[]) {
	int i = 0, j = 0;
		next[1] = 0;
	while (i < s2.size()) {
		if (j == 0 || s2[i] == s2[j]) { i++;j++;next[i] = j; }
		else j = next[j];
	}
}*/
int fact(string s1, string s2, int pos,int next[]) {
	int i = pos, j = 0;
	while (i <s1.size()&& j <s2.size() ){
		if (j==0||s1[i] == s2[j]) {
			i++;
			j++;}
		else  j = next[j];
	}
	int m = s2.size();
	if (j >=s2.size() )return i - m;
	else return 0;
}
int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int next[] = {0};
	int i = 1, j = 0;
	next[1] = 0;
	while (i < s2.size()) {
		if (j == 0 || s2[i] == s2[j]) { i++;j++;next[i] = j; }
		else j = next[j];
	}
	int pos = 0;
	int result = fact(s1, s2, pos,next);
	cout << result;
	return 0;
}
