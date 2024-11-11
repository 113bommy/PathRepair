K = int(input())
S = input()
L = len(S)

MOD = 10 ** 9 + 7
modinv = lambda a, mod=MOD: pow(a, -1, mod)

# x: 26^k*25^(K-k)
x = pow(26, K, MOD)

# comb: C(L+K-i-1, L-1)
comb = 1

ans = 0
for i in range(K, -1, -1):
    ans = (ans + comb * x) % MOD
    x = x * 25 * modinv(26) % MOD
    comb = comb * (L + K - i) * modinv(K - i + 1) % MOD
print(ans)
