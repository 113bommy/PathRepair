from sys import exit
x, k = map(int, input().split())
if x == 0:
    print(0)
    exit(0)
x = 2 * x - 1
mod = 10**9 + 7

def pot(r, k):
    if k == 0: return 1
    if k % 2 == 1:
        return r * pot(r, k - 1) % mod
    y = pot(r, k // 2)
    return y * y % mod

print((pot(2, k) * x + 1) % mod)
