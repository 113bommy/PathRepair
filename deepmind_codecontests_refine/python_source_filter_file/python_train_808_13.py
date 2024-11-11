n = int(input())
a = [int(i) for i in input().split()]
mod = 10 ** 9 + 7
ans = 0
for i in range(60):
    b = sum(map(lambda x: (x >> i)&1, a))
    c = n - b
    ans += b * c * (1<<i) % mod
print(ans%mod)
