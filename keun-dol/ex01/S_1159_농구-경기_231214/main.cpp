#include <iostream>
#include <string>

using namespace std;

void Solve();

int N;
int cnt[26] = {'\0'};
string ans = "";

int main(void) {
	Solve();
	return 0;
}

void Solve() {
	// inpiut
	// 문자열 입력 후 첫 문자에 해당하는 아스키의 인덱스 값 증가
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		cnt[s[0] - 'a']++;
	}

	// 5회이상 나왔으면 정답 문자열에 추가
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			ans += ('a' + i);
		}
	}

	// 빈무자열이면 항복 선언
	// 아니면 정답문자열 출력
	if (ans != "") {
		cout << ans << endl;;
	} else {
		cout << "PREDAJA" << endl;
	}
}