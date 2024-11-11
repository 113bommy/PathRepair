n, m = map(int, input().split())
mod = 10 ** 9 + 7
ans = (pow(2, m, mod) - 1 + mod) * n % mod
print(ans)
