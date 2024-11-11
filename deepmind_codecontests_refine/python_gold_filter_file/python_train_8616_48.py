k = int(input())
s = input()
mod = 10**9+7
n = len(s)
fact =[1]*(k+n)
factinv = [1]*(k+n)
inv = [0,1]
 
 
for i in range(2,k+n):
    fact[i] = (fact[i-1] * i) % mod
    inv.append((-inv[mod % i] * (mod // i)) % mod)
    factinv[i] = (factinv[i-1] * inv[i]) % mod

def nCr(n,r):
  r = min(r,n-r)
  return (fact[n] * factinv[r] * factinv[n-r])%mod
ans = 0
for i in range(k+1):
  a = pow(25, i, mod)
  a *= nCr(i+n-1, n-1)
  a *= pow(26,k-i, mod)
  ans += a
  ans %= mod
print (ans)