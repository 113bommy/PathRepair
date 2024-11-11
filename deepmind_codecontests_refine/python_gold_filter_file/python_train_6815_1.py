import sys
from math import log2,floor,ceil,sqrt
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
MOD = 10**9+7

s = ri()
n = len(s)
dp1 = [0]*(n+1)
dp2  = [0]*(n+1)
a,b = Ri()
for i in range(n):
    dp1[i+1] = ((dp1[i]*10)%a + int(s[i]))%a

p = 1
for i in range(n-1,-1,-1):
    dp2[i] = (dp2[i+1] + (p * int(s[i]) ) %b ) %b
    p = (p * 10)%b

flag = -1
for i in range(0,n-1):
    if  s[i+1] != '0' and dp1[i+1] == 0 and dp2[i+1] == 0:
        flag = i
        break

if flag != -1:
     
    YES()
    print(s[:flag+1])
    print(s[flag+1: ])
else:
    NO()
