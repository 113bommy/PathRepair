N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7

ans = 0
for i in range(60):
    X = sum([1 for x in A if (x >> 1) & 1])
    ans += (1 << i) * X * (N - X)
    ans %= mod

print(ans)
