mod = int(1e9) + 7

n = int(input())
a = pow(9, n, mod)
b = pow(7, n, mod)
print((a - b) % mod)
