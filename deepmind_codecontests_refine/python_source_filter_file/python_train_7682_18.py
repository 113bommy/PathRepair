import sys
from collections import deque
from collections import defaultdict
import math
sys.setrecursionlimit(20000000)
input = sys.stdin.readline
n,m,k = map(int,input().split())
mod = 10**9 + 7
fact = [1]*(n*m+10000+1)
rfact = [1]*(n*m+10000+1)
for i in range(n+10000):
    fact[i+1] = rr = ((i+1) * fact[i]) % mod
def comb(N, K,mod):
    return fact[N] * pow(fact[K], mod-2, mod) * pow(fact[N-K], mod-2, mod) % mod
ans = 0
ni = comb(n*m-2,k-2,mod)
for i in range(n):
    for j in range(m):
        ko = (1+j)*j*n//2
        ko += (m-j)*(m-1-j)*n//2
        ko += (1+i)*i*m//2
        ko += (n-i)*(n-1-i)*m//2
        ans += ni*ko
        ans %= mod
print(ans*pow(2,mod-2,mod)%mod)