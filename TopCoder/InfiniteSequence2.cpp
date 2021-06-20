#include <cstring>
#include <cmath>

class InfiniteSequence2 {
	long long cache[1000000];
	int p, q, x, y;
public:
	long long calc(long n, int p, int q, int x, int y) {
		memset(cache, -1, sizeof(cache));
		this->p = p;
		this->q = q;
		this->x = x;
		this->y = y;
		return solve(n);
	}
	long long solve(long n) {
		if (n <= 0) return 1;

		long first = (long)floor(n / p) - x;
		long second = (long)floor(n / q) - y;
		if (n > 1000000) {
			return solve(first) + solve(second);
		}
		else {
			long long& ret = cache[n];
			if (ret != -1) return ret;
			return ret = solve(first) + solve(second);
		}
	}
};