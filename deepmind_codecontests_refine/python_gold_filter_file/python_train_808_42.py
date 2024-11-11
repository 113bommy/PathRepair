MOD = 10**9+7
N = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(60):
    x = 0
    for a in A:
        if a >> i & 1:
            x += 1
    ans += x * (N-x) * (2**i)
    ans %= MOD

print(ans)
