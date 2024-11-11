from math import factorial as fac

def solve():
	n = int(input())
	m = 2 * n - 2
	i = 2
	ans = 0
	while (i + n - 1 <= m - 1):
		p = max(0, m - n - 2)
		ans += 4 * 3 * 4 ** p
		i += 1
	ans += 2 * 4 * 3 * 4 ** max(0, m - n - 1)

	print(ans)

if __name__ == '__main__':
	solve()