n = int(input())
c = list(map(int,input().split()))
mod = 10**9+7
c.sort()
ans = 0
for i in range(n):
    ans += c[i]*(2+n-1-i)*4**(n-1)
    ans %= mod

ans %= mod
print(ans)