N,A,B,K = map(int,input().split())
n = 0
MOD = 998244353
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m


memo = [0]*(N+1)
memo[0] = memo[N] = 1
for k in range(1,N//2+1):
  v = memo[k-1]*(N-k+1)*modinv(k,MOD)
  v %= MOD
  memo[k] = memo[N-k] = v
for i in range(N+1):
    j = K-A*i
    if j < 0:
        break
    if j%B==0 and j/B <= N:
        j //= B
        n+=memo[i]*memo[j]
        n%=998244353
print(n%998244353)