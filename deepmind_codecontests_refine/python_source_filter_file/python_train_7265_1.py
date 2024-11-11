import sys
import math
from collections import defaultdict

sys.setrecursionlimit(10**7)
def input():
    return sys.stdin.readline()[:-1]

mod = 998244353

def I(): return int(input())
def II(): return map(int, input().split())
def III(): return list(map(int, input().split()))
def Line(N,num):
    if N<=0:
        return [[]]*num
    elif num==1:
        return [I() for _ in range(N)]
    else:
        read_all = [tuple(II()) for _ in range(N)]
        return map(list, zip(*read_all))

#################

#時間計測

def use_divisors(n):
    l_divisors, r_divisors = [], []
    for i in range(1, int(n**0.5)+1):
        if n%i == 0:
            if (n//i)%2:
                l_divisors.append(i)
            if i != n//i:
                if (n//(n//i))%2:
                    r_divisors.append(n//i)
    return l_divisors + r_divisors[::-1]
 
N = I()
X = str(input())
Xr = ''.join('1' if c=='0' else '0' for c in X)

divisors = use_divisors(2*N)
C = dict.fromkeys(divisors,0)

for d in divisors:
    T = X[:d//2]
    Tr = Xr[:d//2]
    Tc = T+Tr
    count = int(T,2)
    if Tc*(N//d)+Tc[:N-d*(N//d)] <= X:
    #    count += 1
    C[d] = count
    for d1 in divisors:
        if d%d1==0 and d!=d1:
            C[d] -= C[d1]

ans = 0
for d in divisors:
    ans += d*C[d]
    ans %= mod

print(ans)