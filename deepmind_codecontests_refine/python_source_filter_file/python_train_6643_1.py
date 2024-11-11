import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def MI(): return map(int, sys.stdin.readline().split())
def MI1(): return map(int1, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LI1(): return list(map(int1, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]

def com(com_n, com_r):
    return fac[com_n] * inv[com_r] * inv[com_n - com_r] % md
def way(h, w):
    if h < 0 or w < 0:
        return 0
    else:
        return com(h + w, h)

# combinationの準備
# md>n_maxの条件
md = 10 ** 9 + 7
n_max = 100
fac = [1]
inv = [1] * (n_max + 1)
k_fac_inv = 1
for i in range(1, n_max + 1):
    k_fac_inv = k_fac_inv * i % md
    fac.append(k_fac_inv)
k_fac_inv = pow(k_fac_inv, md - 2, md)
for i in range(n_max, 1, -1):
    inv[i] = k_fac_inv
    k_fac_inv = k_fac_inv * i % md

def main():
    h, w, n = MI()
    rc = [LI1() for _ in range(n)]
    # i番目の壁まで無傷で来る方法の数
    # (全ルート)－(i-1までの壁にぶつかる分)
    rc.sort(key=lambda x: x[0] + x[1])
    dp = [0] * n
    for i, (r, c) in enumerate(rc):
        dp[i] = way(r, c) - sum(v * way(r - pr, c - pc) % md for v, (pr, pc) in zip(dp[:i], rc[:i]))
        dp[i] %= md
    h, w = h - 1, w - 1
    ans = way(h, w) - sum(v * way(h - r, w - c) % md for v, (r, c) in zip(dp, rc))
    print(ans % md)

main()
