def inv(a):
    return pow(a, mod - 2, mod)
n, m, k = map(int, input().split())
if (2 * k > min(n, m)):
    print(0)
    exit()
fact = [1]
mod = 1000000007
for i in range(1, 2001):
    fact.append(fact[-1] * i % mod)
print(fact[n - 1] * inv(fact[2 * k]) * inv(fact[n - 2 * k - 1]) * fact[m - 1] * inv(fact[2 * k]) * inv(fact[m - 2 * k - 1]) % mod)