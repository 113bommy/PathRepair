import sys
from heapq import heapify, heappush, heappop

def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c for j in range(b)] for i in range(a)]
def list3d(a, b, c, d): return [[[d for k in range(c)] for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e for l in range(d)] for k in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10**19
MOD = 10**9 + 7
EPS = 10**-10

N, K = MAP()
A = LIST()

def calc(a, cnt):
    d, m = divmod(a, cnt)
    return d**2 * (cnt-m) + (d+1)**2 * m

que = []
for a in A:
    if a // 2 == 0:
        que.append((0, 1, a))
    else:
        que.append((calc(a, 2) - calc(a, 1), 1, a))
heapify(que)

for _ in range(K-N):
    val, cnt, a = heappop(que)
    if a // (cnt+2) == 0:
        heappush(que, (0, cnt, a))
    else:
        heappush(que, (calc(a, cnt+2) - calc(a, cnt+1), cnt+1, a))

ans = 0
for _, cnt, a in que:
    ans += calc(a, cnt)
print(ans)
