from collections import defaultdict
from math import gcd
N = int(input())
MOD = 10**9 + 7
L = defaultdict(lambda: [0,0])
zero = 0
for _ in range(N):
    A, B = map(int, input().split())
    if A==0: d=B
    elif B==0: d=A
    else: d=gcd(A,B)
    if d != 0:
        A, B = A//d, B//d
        if A<0: A, B = -A, -B
        if B>0: L[(A,B)][0] += 1
        else: L[(-B,A)][1] += 1
    else: zero += 1
print(L)
res = 1

for x,y in L.values():
    res *= pow(2,x,MOD) + pow(2,y,MOD) -1
    res %= MOD
print((res+zero-1)%MOD)

