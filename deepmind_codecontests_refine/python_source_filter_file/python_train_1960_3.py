import sys
input = sys.stdin.readline

# K+1 - x でうつす -> i と 2K+2-i は同じ

MOD = 998244353
U = 10000
fact = [1] * (U+1)
fact_inv = [1] * (U+1)
for n in range(1,U+1):
    fact[n] = fact[n-1] * n % MOD
fact_inv[n] = pow(fact[n], MOD-2, MOD)
for n in range(U,0,-1):
    fact_inv[n-1] = fact_inv[n] * n % MOD

def comb(n,k):
    if not (0 <= k <= n):
        return 0
    return fact[n] * fact_inv[k] * fact_inv[n-k] % MOD

K,N = map(int,input().split())

def F(x,y,N):
    n = min(x, N)
    return sum(comb(x,i) * pow(2,i,MOD) * comb(N+y-1,i+y-1) for i in range(n+1)) % MOD

answer = []
for S in range(2,K+2):
    if S & 1:
        x = F((S-1)//2, K - S + 1, N)
    else:
        x = F((S-1)//2, K - S + 1, N) + F((S-1)//2, K - S + 1, N - 1)
    answer.append(x % MOD)

answer += answer[:-1][::-1]

print('\n'.join(map(str,answer)))

