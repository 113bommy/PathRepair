from collections import Counter

U = 10**5
MOD = 10**9+7
 
fact = [1]*(U+1)
fact_inv = [1]*(U+1)
 
for i in range(1,U+1):
    fact[i] = (fact[i-1]*i)%MOD
fact_inv[U] = pow(fact[U], MOD-2, MOD)
 
for i in range(U,0,-1):
    fact_inv[i-1] = (fact_inv[i]*i)%MOD
    
def comb(n, k):
    if k < 0 or k > n:
        return 0
    z = fact[n]
    z *= fact_inv[k]
    z %= MOD
    z *= fact_inv[n-k]
    z %= MOD
    return z
  
n = int(input())
A = list(map(int, input().split()))
x = Counter(A).most_common()[0][0]
left = A.index(x)
right = A[::-1].index(x)
print(n)
for k in range(2, n+2):
  ans = comb(n+1, k) - comb(left+right, k-1)
  ans %= MOD
  print(ans)