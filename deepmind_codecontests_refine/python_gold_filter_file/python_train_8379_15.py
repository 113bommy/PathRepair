mod = int(1e9) + 7

n = int(input())
a = pow(27, n, mod)
b = pow(7, n, mod)
print((a - b) % mod)
