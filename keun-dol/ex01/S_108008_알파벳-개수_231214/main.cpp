#include <iostream>
#include <string>

using namespace std;

int cnt[26] = { 0 };
string str;

void Solve() {
	// input
	cin >> str;

	// str의 각 문자 알파벳을 아스키 계산을 통해 0~25의 인덱스로 변환
	// 해당 알파벳 인덱스의 카운트 증가
	for (auto i : str) {
		cnt[i - 'a']++;
	}

	// output
	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << ' ';
	}
	cout << endl;
}

int main(void) {
	Solve();
}