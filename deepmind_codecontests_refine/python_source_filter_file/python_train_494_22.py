import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import defaultdict
P = 13 ** 8 + 18
mod = 10 ** 9 + 7
N = int(input())
D = defaultdict(int)
C00 = 0
for i in range(N):
    a, b = map(int, input().split())
    if a == b == 0:
        C00 += 1
    elif a == 0:
        D[-1] += 1
    elif b == 0:
        D[-2] += 1
    else:
        x = a * pow(b, P - 2, P) % P
        D[x] += 1
ans = 1
for x in D:
    y = pow(-x, P - 2, P) if x > 0 else -3 - x
    if y in D and x > y: continue
    ans *= 1 + pow(2, D[x], mod) - 1 + pow(2, (D[y] if y in D else 0), mod) - 1
    ans %= mod
print((ans + C00 - 1) % mod)