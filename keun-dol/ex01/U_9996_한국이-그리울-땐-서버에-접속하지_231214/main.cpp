#include <iostream>

using namespace std;

void Solve();

int main(void) {
	Solve();
	return 0;
}

void Solve() {
	int N;
	string pattern;
	string arr_str[100];
	string pat_front, pat_end;

	// input
	cin >> N;
	cin >> pattern;
	for (int i = 0; i < N; i++) {
		cin >> arr_str[i];
	}

	// 패턴1 : [0, 별표)
	// 패턴2 : (별표, last]
	int which = 0;
	for (auto c : pattern) {
		if (c == '*') {
			which = 1;
			continue;
		}
		if (which == 0) {
			pat_front += c;
		} else {
			pat_end +=  c;
		}
	}
	cout << pat_front << ' ' << pat_end << endl;

	int is_match;
	for (int i = 0; i < N; i++) {
		string s = arr_str[i];
		is_match = 1;

		// 앞에서부터 별표 전까지 모두 일치하는지 확인
		int j;
		for (j = 0; j < pat_front.size(); j++) {
			if (s[j] != pat_front[j]) {
				is_match = 0;
				break;
			}
		}

		// 뒤에서부터 별표 앞까지 모두 일치하는지 확인
		for (int k = 0; k < pat_end.size() && pat_end.size() - k - 1 >= j; j++) {
			if (s[s.size() - j - 1] != pat_end[pat_end.size() - j - 1]) {
				is_match = 0;
				break;
			}
		}

		// output
		if (is_match == 1) {
			cout << "DA" << endl;
		} else {
			cout << "NE" << endl;
		}
	}
}