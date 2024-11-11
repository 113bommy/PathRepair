import sys
from math import log2,floor,ceil,sqrt
# import bisect
# from collections import deque
sys.setrecursionlimit(7*10**4)

Ri = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()
 
def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def list4d(a, b, c, d, e): return [[[[e] * d for j in range(c)] for j in range(b)] for i in range(a)]
def ceil(x, y=1): return int(-(-x // y))
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10 ** 18
MOD =  998244353

for _ in range(int(ri())):
    x,y = Ri()
    a,b = Ri()
    ans = 0
    if b  <= 2*a:
        if x < y:
            ans = ans + x*b
            y-=x
            x-=x
            
            # print(x,y,ans)
            ans+=(y*a)
            # print("fsf")  
        else:
            ans = ans + x*b

            x-=y
            y = 0
            ans+=(x*a)
    else:
        ans = x*a + y*a
    print(ans)

