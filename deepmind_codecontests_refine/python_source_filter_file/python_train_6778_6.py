import sys
from math import sqrt, gcd
from bisect import bisect
from collections import defaultdict
inp = sys.stdin.readline
read = lambda: list(map(int, inp().strip().split()))

# sys.setrecursionlimit(10**6)



def solve():
	n, m = read(); dic = defaultdict(int)#{i:0 for i in range(m)}
	for i in range(m):
		dic[i**2 % m] += 1
	for i in dic:
		dic[i] *= n//m
	for i in range(1, n%m+1):
		dic[i**2%m] += 1
	ans = 0
	print(dic)
	for i in dic:
		if (m-i)%m in dic:
			ans += dic[i] * dic[(m-i)%m]
	print(ans)


if __name__ == "__main__":
	solve()