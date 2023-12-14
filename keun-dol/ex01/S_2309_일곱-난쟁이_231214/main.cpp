#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

array<int, 9> cand = {};
array<int, 9> tall = {};

bool is_end = false;

void DFS(int prev, int size) {
	// DFS 전체 종료 조건
	if (is_end) {
		return;
	}

	// DFS 다음 깊이 진행 금지 조건
	// 7명을 모은 뒤, 키의 총 합을 구한다.
	// 100이 넘는다면 각 난쟁이의 키를 정렬한 뒤 출력하고
	// 전체 종료 조건 true
	if (size == 7) {
		int sum = 0;
		vector<int> ans;

		for (int i = 0; i < 9;i++) {
			if (cand[i] == 1) {
				sum += tall[i];
				ans.push_back(tall[i]);
			}
		}

		if (sum == 100) {
			sort(ans.begin(), ans.end());
			for (auto i : ans) {
				cout << i << endl;
			}
			is_end = true;
		}
		
		return;
	}

	// 다음 조합
	// 이전에 추가한 것들 제외
	for (int i = prev + 1; i < 9; i++) {
		cand[i] = 1;
		DFS(i, size + 1);
		cand[i] = 0;
	}
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		cin >> tall[i];
	}

	for (int i = 0; i < 9; i++) {
		cand[i] = 1;
		DFS(i, 1);
		cand[i] = 0;
	}
	return 0;
}