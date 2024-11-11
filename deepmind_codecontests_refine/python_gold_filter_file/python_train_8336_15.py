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
a = I()
d = {}
a.sort()
for i in a:
    d[i] = d.get(i, 0) + 1
ans = 0
p = [2**i for i in range(40)]
for i in range(n):
    x = a[i]
    for j in p:
        if j - x in d and (j - x != x or d[x] >= 2):
            break
    else:
        ans += 1
print(ans)