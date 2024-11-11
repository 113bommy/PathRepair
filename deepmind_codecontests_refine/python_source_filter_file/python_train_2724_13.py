import sys
# from math import log2,floor,ceil,sqrt
# import bisect
# from collections import deque

from types import GeneratorType
def bootstrap(func, stack=[]):
    def wrapped_function(*args, **kwargs):
        if stack:
            return func(*args, **kwargs)
        else:
            call = func(*args, **kwargs)
            while True:
                if type(call) is GeneratorType:
                    stack.append(call)
                    call = next(call)
                else:
                    stack.pop()
                    if not stack:
                        break
                    call = stack[-1].send(call)
            return call
    return wrapped_function

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
MOD = 10**9+7


def solve(n1,n2,cur1,cur2):
    if cur1 > k1 or cur2 > k2 or n1 < 0 or n2 < 0:
        return 0
    if dp[n1][n2][cur1][cur2] != -1:
        return dp[n1][n2][cur1][cur2]
    dp[n1][n2][cur1][cur2] = solve(n1-1,n2,cur1+1,0) + solve(n1,n2-1,0,cur2+1)
    return dp[n1][n2][cur1][cur2]


n1,n2,k1,k2 = Ri()
dp = list4d(n1+1,n2+1,k1+1,k2+1,-1)
for i in range(k1+1):
    for j in range(k2+1):
        dp[0][0][i][j] = 1
print(solve(n1,n2,0,0))


    

