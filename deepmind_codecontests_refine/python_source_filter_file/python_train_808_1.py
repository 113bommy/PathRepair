n = int(input())
a = list(map(int,input().split()))
mod = 10e9+7
ans = 0
for i in range(60):
    x = 1<< i
    l = len([1 for j in a if j & x])
    ans += x * l * (n-l) % mod
    ans %= mod
print(ans)