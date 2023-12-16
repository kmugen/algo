#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void Solve();

int main(void) {
	Solve();
	return 0;
}

void Solve() {
	string s;
	// input
	// 공백포함 입력
	getline(cin, s);

	// 알파벳일 경우만 처리
	// c + 13이 char의 범위를 넘는 경우를 위해 잠시 int로 연산 후 char에 대입
	// +13 후 알파벳을 벗어나면 다시 a/A부터
	for (auto & c : s) {
		int tmp = (int)c;
		if (tmp >= 'a' && tmp <= 'z') {
			tmp += 13;
			if (tmp > 'z') {
				tmp = (tmp - 'z' - 1 + 'a');
			}
		} else if (tmp >= 'A' && tmp <= 'Z') {
			tmp += 13;
			if (tmp > 'Z') {
				tmp = (tmp - 'Z' - 1 + 'A');
			}
		}
		c = tmp;
	}

	// output
	cout << s << endl;
}
