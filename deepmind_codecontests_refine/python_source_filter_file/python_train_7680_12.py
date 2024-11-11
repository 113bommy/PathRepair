n, k = map(int, input().split())
mod = 10**9+7

k = min([k, n-1])


ans = 0
key = 1

for i in range(k):
    ans += key
    ans %= mod
    key = (((key*(n-i)%mod)*(n-i-1)%mod)*pow(pow(i+1, mod-2, mod), 2, mod))%mod
print(ans)