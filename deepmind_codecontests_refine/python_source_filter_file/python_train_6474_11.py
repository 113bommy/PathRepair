n, m = list(map(int, input().split()))

mod = int(10e9) + 7

ans = 1

a1 = ((pow(2, m, mod) - 1) + mod) % mod
ans = pow(a1, n, mod)

print(ans)