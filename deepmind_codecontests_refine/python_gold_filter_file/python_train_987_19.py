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

n, d = I()
a = [(0, 0)]
for i in range(n):
    x, y = I()
    a.append((x, y))
a.sort()
j = 0
ans = 0
cur = 0
for i in range(1, n + 1):
    cur += a[i][1]
    while a[i][0] - a[j][0] >= d:
        cur -= a[j][1]
        j += 1
    ans = max(ans, cur)
print(ans)