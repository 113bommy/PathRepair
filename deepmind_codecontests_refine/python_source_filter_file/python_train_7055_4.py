import sys

def S(): return sys.stdin.readline().rstrip()

N,M = map(int,S().split())
mod = 10**9+7

a = M  # (M_P_N)**2
for i in range(1,N):
    a *= M-i
    a %= mod

# 包除原理
# 2つめの条件は常に成り立った状況で考える
# {1,…,N}の部分集合Sの元iに対してA_i=B_iが成り立つようなA_1,…,B_1,…の組の個数を考える
ans = a**2 % mod
r = ans
for i in range(1,N+1):
    r *= (N-i+1)*pow(i,-1,mod)*pow(M-i+1,-1,mod)*(-1)
    r %= mod
    ans += r
    ans %= mod

print(ans)