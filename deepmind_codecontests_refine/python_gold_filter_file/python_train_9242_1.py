def cmb(a,b,c):
    b = min(b,a-b)
    num = 1
    for i in range(b):
        num = num*(a-i) % c
    den = 1
    for i in range(b):
        den = den*(i+1) % c
    return num * pow(den,c-2,c) % c

mod = 10**9+7
n,k = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
ans = 0
c = cmb(n-1,k-1,mod)
if k == 1:
    print(0)
    exit()
for i in range(n-k+1):
    ans -= a[i] * c
    ans += a[-i-1] * c
    ans %= mod
    c = (c * (n-k-i) * pow(n-i-1,mod-2,mod)) % mod
if ans < 0:
    ans += mod
print(ans)
