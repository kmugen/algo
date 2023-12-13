#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

// 현재 후보 난쟁이들 (stack<int>) : 난쟁이들은 번호 0~8로 부여, 각 난쟁이의 몸무게는 ary[i]
// 난쟁이들의 키를 담는 배열
// 종료 플래그 T/F
// 어떤 난쟁이가 후보에 들었는지 flag 배열 bool[9]
stack<int> cand;
int height[9] = {};
int is_end = 0;
int flag[9] = {};

void Solve();
void DFS(int sum);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Solve();

	return 0;
}

void Solve() {
	/*
	input
	100 미만의 정수 9개 입력, 입력 개수 고정
	*/
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}

	/*
	난쟁이들의 키를 저장하는 int ary[9]
	배열 크기 9개로 작으므로 완전탐색 가능
	DFS로 구현
	*/

	/*
	DFS 파라미터
		현재 난쟁이들의 키 총합 (int)
		DFS 종료 플래그
		현재 

	종료조건 : 키 총합이 100 이상인 경우 || 난쟁이 후보가 7명이 된 경우
		
		if 종료조건 true:
			if 키 총합 100 && 후보 7명:
				종료 플래그 true
			return
		else:
			0~8번 난쟁이 확인(for 반복)
				if i번 난쟁이 후보면 
					pass
				else
					난쟁이 Flag true
					없으면 난쟁이 push
					다음 재귀 (현재 키합 + 난쟁이 키)
					난쟁이 flag false
					pop

	*/
	for (int i = 0; (i < 9) && (is_end == 0); i++) {
		flag[i] = 1;
		cand.push(i);
		DFS(height[i]);
		cand.pop();
		flag[i] = 0;
	}
	/*
	output
	합이 100인 정수 7개를 오름차순 정렬한 뒤 출력
	경우의 수가 여러가지인 경우, 아무거나 출력
	합이 100인 경우가 무조건 존재
	DFS 종료조건에 배치
	*/

}

void DFS(int sum) {
	if (is_end == 1) {
		return;
	}
	if ((sum >= 100) || (cand.size() >= 7)) {
		if (sum == 100) {
			vector<int> ans;
			while (!cand.empty()) {
				ans.push_back(height[cand.top()]);
				cand.pop();
			}
			sort(ans.begin(), ans.end());
			for (auto i : ans) {
				cout << i << endl;
			}
			is_end = 1;
		}
		return;
	}

	for (int i = 0; (i < 9) && (is_end == 0); i++) {
		if (flag[i] == 0) {
			flag[i] = 1;
			cand.push(i);
			DFS(sum + height[i]);
			cand.pop();
			flag[i] = 0;
		}
	}
}