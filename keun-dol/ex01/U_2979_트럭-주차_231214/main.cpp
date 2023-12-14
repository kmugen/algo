#include <iostream>

using namespace std;

int A, B, C;
int avail[3][100] = {};
int ans = 0;

void Solve();

int main(void) {
	Solve();
	return 0;
}

void Solve() {
	// input
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		int b, e;
		cin >> b >> e;
		for (int j = b; j < e; j++) {
			avail[i][j - 1] = 1;
		}
	}

	// 열을 기준으로 탐색
	// 해당 열에 1이 몇 행있는지 카운트
	// 개수에 따라 요금 부과
	int ans = 0;
	for (int j = 0; j < 100; j++) {
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			cnt += avail[i][j];
		}
		switch(cnt) {
		case 0:
			break;
		case 1:
			ans += A;
			break;
		case 2:
			ans += (B * 2);
			break;
		case 3:
			ans += (C * 3);
			break;
		default:
			;
		}
	}

	// output
	cout << ans << endl;
}
