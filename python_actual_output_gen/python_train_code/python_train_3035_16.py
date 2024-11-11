x, k = map(int, input().strip().split())
MOD = 10**9 + 7

def pow2(k):
    if k == 0:
        return 1
    if k == 1:
        return 2
    r = pow2(k // 2)
    r = r * r
    if k % 2 != 0:
        r *= 2
    return r % MOD

def calc(x, k):
    if x == 0:
        return 0
    if k == 0:
        return 2 * x
    r = pow2(k) * (2 * x - 1) + 1
    return r % MOD

print(calc(x, k))