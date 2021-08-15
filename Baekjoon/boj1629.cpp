/**
* @date: 2021-08-15
* @version: 1.0.0
* @access:
	for문으로 B의 수 만큼 A를 곱하게 하면 B의 값이 클 수록 시간 제한에 걸리기 때문에
	짝수이면 B를 반으로 나누어 재귀 호출하여 계산하고 아니면 B를 짝수로 만들고 재귀 호출하여 풀었다.
* @weaknesses & learned:
	자료형을 잘 선택하고 써야한다. 맨 처음 solve함수의 리턴 자료형을 int로 잡고 풀었는데
	생각해보니 리턴하자마자 바로 곱하기를 하기 때문에 int 자료형 보다 큰 자료형으로 잡아야했다.
	그래서 long으로 바꿔서 제출하니 통과였다. 하지만 c언어의 자료형을 찾아보니 int 자료형과 long 자료형 둘 다 4byte였다.
	그래서 찾아보니 운영체제의 환경에 맞는 크기로 자료형의 길이가 바뀌는 것으로 확인하였다.
	따라서 자료형을 long long으로 바꿔 확실한 범위를 가지게 하였다.
*/
#include <iostream>
using namespace std;

long long solve(int A, int B, int C) {
	if (B == 1) return A % C;

	// B가 홀수이면
	if (B % 2 == 1) {
		return (A * solve(A, B - 1, C)) % C;
	}
	// 짝수이면
	long long half = solve(A, B / 2, C);
	return (half * half) % C;
}

int main(void) {
	int A, B, C;
	cin >> A >> B >> C;
	
	cout << solve(A, B, C) << endl;
}