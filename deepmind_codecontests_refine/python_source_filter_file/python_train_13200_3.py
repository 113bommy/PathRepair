import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from functools import lru_cache

L,A,B,MOD = map(int,read().split())

@lru_cache(None)
def F(r,n,MOD):
    # 1+r+...+r^{n-1} をダブリングで求める
    if n == 0:
        return 0
    q = n//2
    x = F(r,q,MOD)
    # 1+r^qをかける
    x *= 1 + pow(r,q,MOD); x %= MOD
    if n&1:
        x *= r; x += 1; x %= MOD
    return x

@lru_cache(None)
def G(r,n,MOD):
    # sum ir^i をダブリングで求める
    if n == 0:
        return 0
    q = n//2
    x = G(r,q,MOD)
    # 1+r^qをかける
    x *= 1 + pow(r,q,MOD); x %= MOD
    # q(r^q+...+r^{2q-1})を加える
    x += F(r,q,MOD) * pow(r,q,MOD) * q % MOD
    if n&1:
        x *= r; x += F(r,n,MOD); x -= 1; x %= MOD
    return x

S = 0
for d in range(1,20):
    # d桁の最初、最後、項数
    lower = 10**(d-1)
    upper = 10**d
    # lower <= A+nB <= upper
    nlower = (lower-A+B-1)//B
    nupper = (upper-A)//B
    if nlower < 0:
        nlower = 0
    if nupper >=L:
        nupper = L-1
    if nlower > nupper:
        continue
    items = nupper - nlower + 1
    r = (10**d) % MOD
    last = A+B*nupper
    x = last * F(r,items,MOD)
    x -= B * G(r,items,MOD)
    length = d*items
    S *= pow(10,length,MOD); S += x
    S %= MOD

print(S)