import sys
# from math import log2,floor,ceil,sqrt
# import bisect
# from collections import deque

# from types import GeneratorType
# def bootstrap(func, stack=[]):
#     def wrapped_function(*args, **kwargs):
#         if stack:
#             return func(*args, **kwargs)
#         else:
#             call = func(*args, **kwargs)
#             while True:
#                 if type(call) is GeneratorType:
#                     stack.append(call)
#                     call = next(call)
#                 else:
#                     stack.pop()
#                     if not stack:
#                         break
#                     call = stack[-1].send(call)
#             return call
#     return wrapped_function

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
MOD = 10**8
N = 5*10**6


n,h,l,r  = Ri()
a = Ri()

dp = list2d(n+1,h+1,-10)
if l <= 0 <= r:
    dp[0][0] = 1
else:
    dp[0][0] = 0
for i in range(1,len(a)+1):
    for j in range(0,h):
        # if j-a[i-1] >= 0:
        dp[i][j] = dp[i-1][(j-a[i-1])%h]
            # if l <= j<= r:
            #     dp[i][j]
        # if j-a[i-1]+1 >=0 :
        dp[i][j]  = max(dp[i][j],dp[i-1][(j-a[i-1]+1)%h])
        if l <= j <= r:
            dp[i][j]+=1

# for i in dp:
#     print(i)
maxx = 0
for i in range(h):
    maxx = max(maxx,dp[n][i])
print(maxx)
