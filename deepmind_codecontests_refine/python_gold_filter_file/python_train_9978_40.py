mod = 10 ** 9 + 7

SIZE = 10 ** 5 + 5
fact = [0] * SIZE
inv = [0] * SIZE
finv = [0] * SIZE
fact[0], fact[1] = 1, 1
inv[1] = 1
finv[0], finv[1] = 1, 1
for i in range(2, SIZE):
    fact[i] = fact[i - 1] * i % mod
    inv[i] = mod - inv[mod % i] * (mod // i) % mod
    finv[i] = finv[i - 1] * inv[i] % mod


def nCr(n, r):
    if n < 0 or r < 0 or n < r:
        return 0
    return fact[n] * (finv[r] * finv[n - r] % mod) % mod


from collections import Counter


n = int(input())
A = list(map(int, input().split()))
counterA = Counter(A)
duplicate = 0
for num, count in counterA.items():
    if count == 2:
        duplicate = num
        break

duplicate_pos = []
for i, a in enumerate(A):
    if a == duplicate:
        duplicate_pos.append(i)

first, second, *_ = duplicate_pos

for k in range(1, n+2):
    base = nCr(n+1, k)
    duplicate_pattern = nCr(first + n-second, k-1)
    print((base - duplicate_pattern) % mod)

