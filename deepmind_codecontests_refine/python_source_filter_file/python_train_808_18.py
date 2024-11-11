n = int(input())
A = list(map(int, input().split()))

MOD = 1e9+7
ans = 0

for i in range(60):
    cnt = 0
    for a in A:
        cnt += a>>i&1
    ans += cnt*(n-cnt)*2**i
    ans %= MOD

print(ans)
