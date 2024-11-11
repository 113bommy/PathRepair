import sys
from math import sqrt, gcd, ceil, log
from bisect import bisect
from collections import defaultdict
inp = sys.stdin.readline
read = lambda: list(map(int, inp().strip().split()))

# sys.setrecursionlimit(10**6)



def solve():
	n = int(inp()); t = n

	arr = []; sett = set(); m_c = 1;

	for i in range(2, int(sqrt(n)+1)):
		c = 0
		if n%i == 0:
			arr.append(i)
			while n%i == 0:
				c += 1
				n //= i
			sett.add(c)
		m_c = max(m_c, c)
	if n > 1:
		arr.append(n)
		sett.add(1)

	if m_c == 1:print(t, 0);exit()

	m_c = ceil(log(m_c, 2))
	print(m_c, sett, arr)
	if not(len(sett) == 1 and 2**m_c in sett):
		m_c += 1

	ans = 1
	for i in arr: ans *= i
	print(ans, m_c)



if __name__ == "__main__":
	solve()