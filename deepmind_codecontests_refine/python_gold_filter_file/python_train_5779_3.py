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
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

n, = I()
ans = [3]
n -= 3
primes = []
M = 10001
p = [1] * M
for  i in range(2, M):
    if p[i]:
        primes.append(i)
        for j in range(2 * i, M, i):
            p[j] = 0
def is_prime(x):
    for i in range(2, int(x ** 0.5) + 1):
        if not x % i:
            return False
    return True
if n:
    for i in primes:
        if n - i == 0:
            ans.append(i)
            break
        if is_prime(n - i):
            ans.append(i)
            ans.append(n - i)
            break
print(len(ans))
print(*ans)