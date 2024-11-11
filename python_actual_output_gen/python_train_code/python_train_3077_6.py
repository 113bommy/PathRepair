n, a, b, k = [int(i) for i in input().split()]
p = 998244353

def fact(n, p):
    n_ = 1
    yield n_
    for i in range(1, n+1):
         n_ = (n_*i) % p
         yield n_

def invfact(n, f, p):
    m = pow(f[n], p-2, p)
    yield m
    for i in range(n, 0, -1):
        m = m * i % p
        yield m

f = list(fact(n+1, p))
rf = list(invfact(n+1, f, p))
rf.reverse()
ans = 0

for x in range(n+1):
    y = (k-x*a)/b
    if not y.is_integer() or y > n:
        continue
    y = int(y)

    ans += (f[n] * rf[x] % p * rf[n-x] % p) * (f[n] * rf[y] % p * rf[n-y] % p) % p

print(ans%p)