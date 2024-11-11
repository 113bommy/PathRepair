# xの逆元は、x*y = 1 mod pとなるようなy
N, K = map(int, input().split())
mod = 10**9 + 7
a = N - K + 1
print(a)
for i in range(K-1):
    a = a * (N - K - i) * (K - (i + 1)) // ((i+2) * (i+1))
    print(a % mod)

