# cook your dish here
import sys
import math
#  if (ans[i-1]+1)%3 == 0 else (ans[i-1]+1)%3

RI = lambda : [int(x) for x in sys.stdin.readline().split()]
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
MOD = 10 ** 9 + 7

def seive():
    global ite
    ans[2] = ite
    for i in range(4,n+1,2):
        prime[i] = False
        ans[i] = ite
    ite+=1
    p = 3
    while(p*p <= n+1):
        if prime[p]:
            ans[p] = ite
            for j in range(p*p,n+1,p):
                prime[i] = False
                ans[j] = ite
            ite+=1
        p+=2
    # ans[p] = te

n = int(ri())
ite = 1
ans = [0]*(n+1)
prime = [True]*(n+1)
seive()
ans = ans[2:]
for i in range(len(ans)):
    if ans[i] == 0:
        ans[i] =ite
        ite+=1

print(*ans)