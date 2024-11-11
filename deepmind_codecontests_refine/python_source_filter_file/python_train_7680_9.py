MOD = 10**9 + 7
inpl = lambda: list(map(int,input().split()))
def inv_mod(a, p=10**9+7):
    p = abs(p)
    a %= p
    stack = []
    p0 = p
    while a > 1:
        d, a, p = p//a, p%a, a
        stack.append(d)
    x, y = 1, 0
    while stack:
        d = stack.pop()
        x, y = y-d*x, x
    return x % p0
n, k = inpl()
if k >= n:
    k = n-1
ans = 1
t = 1
print(k)
for i in range(k):
    t *= (n-1-i)*(n-i)
    t %= MOD
    j = inv_mod(i+1)
    t *= j*j % MOD
    ans += t
    ans %= MOD
print(ans)