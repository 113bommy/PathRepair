def cmb(n, r, mod):
    c=1
    for i in range(1, r+1):
        c = (c * (n-i+1) * pow(i, mod-2, mod)) % mod
    return c

n, a, b = map(int, inputs[0]().split())
MOD = 10**9 + 7
print((pow(2, n, MOD) - cmb(n, a, MOD) - cmb(n, b, MOD) - 1) % MOD)