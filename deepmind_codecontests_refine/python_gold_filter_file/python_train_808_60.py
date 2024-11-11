n = int(input())
a = list(map(int, input().split()))
MOD = 10 ** 9 + 7

ans = 0
for i in range(60):
    x = [(bool)(ai & 1 << i) for ai in a]
    sx = sum(x)
    count = sx * (n - sx)
    ans += count << i
    ans %= MOD

print(ans)