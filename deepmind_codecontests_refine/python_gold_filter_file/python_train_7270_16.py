from fractions import gcd
N = int(input())
ans = 1
for _ in range(N):
    T = int(input())
    ans = ans * T // gcd(ans, T)
print(ans)