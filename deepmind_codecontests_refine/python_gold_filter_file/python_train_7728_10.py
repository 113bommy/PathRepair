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
 
INF = 10**20
MOD = 998244353
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br
 
n, = I()
p = [0] * (n + 1)
for i in range(n + 1):
    p[i] = pow(10, i, MOD)

for i in range(n):
    i += 1
    ans = 0
    if n - i - 1 >= 0:
        ans = (10 * 9 * p[(n - i - 1)]) * 2
        ans %= MOD
    if n - i - 2 >= 0:
        ans += (10 * 9 * 9) * p[n - i - 2] * (n - i - 2 + 1)
    if i == n:
        ans = 10
    print(ans % MOD, end = ' ')