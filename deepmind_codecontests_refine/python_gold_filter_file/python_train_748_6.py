import sys
def fastio():
	from io import StringIO
	from atexit import register
	global input
	sys.stdin = StringIO(sys.stdin.read())
	input = lambda : sys.stdin.readline().rstrip('\r\n')
	sys.stdout = StringIO()
	register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

def debug(*var, sep = ' ', end = '\n'):
	print(*var, file=sys.stderr, end = end, sep = sep)

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

n, = I()
p = I()
s = set(p)
par = [0, 0]
for i in range(1, n + 1):
	if i in s:
		continue
	par[i % 2] += 1

def check(x, y):
	a = [x] + p + [y]
	res = 0
	parity = [[], [], []]
	last = x % 2
	idx = 0
	cur_par = [par[0], 0,  par[1]]
	for i in range(1, n + 2):
		if a[i] == 0:
			continue
		if last == -1:
			parity
		if last != -1:
			now = a[i] % 2
			cur = i - idx - 1
			if cur != 0:
				parity[last + now].append(cur)
		last = a[i] % 2
		idx = i
	
	com = [0, 0, 0]
	for i in range(2, n + 2):
		if a[i] != 0 and a[i-1] != 0 and a[i-1] % 2 ^ a[i] % 2 == 1:
			res += 1
	# print(res)
	for i in range(0, 3, 2):
		parity[i].sort()
		for j in parity[i]:
			if j <= cur_par[i]:
				cur_par[i] -= j
				com[i] += 1
			else:
				break
	res += 2 * ((len(parity[0]) - com[0] + len(parity[2]) - com[2]))
	res += len(parity[1])
	# print(parity, res, com)
	return res
ans = INF
ans = check(4, 1)
ans = min(ans, check(1, 1))
ans = min(ans, check(4, 4))
ans = min(ans, check(1, 4))
print(ans)