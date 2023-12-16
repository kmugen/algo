#include <iostream>
#include <string>

using namespace std;

void Solve();

int main(void) {
	Solve();
	return 0;
}

void Solve() {
	// input string
	string s;

	// input
	cin >> s;

	// 양끝에서 가운데로 이동하며 같은지 비교
	// 서로 다른 값이거나 가운데에 도착하면 종료
	auto itr_1 = s.begin();
	auto itr_2 = s.end() - 1;
	while ((itr_1 < itr_2) && (*itr_1 == *itr_2)) {
		itr_1++;
		itr_2--;
	}


	// output
	// 중도 종료면 0 아니면 1
	if (itr_1 < itr_2) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
}