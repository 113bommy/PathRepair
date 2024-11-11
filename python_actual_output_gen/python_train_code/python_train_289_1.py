n = int(input())
a = list(map(int,input().split()))
mod = 10e9+7
ans = 0
for i in range(60):
    x = 1 << i
    n = len([1 for j in a if j & X])
    ans += x * n * (N-n) % mod
    ans %= mod
print(ans)