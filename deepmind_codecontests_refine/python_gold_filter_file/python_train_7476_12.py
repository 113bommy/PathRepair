# coding:utf-8

import sys


input = sys.stdin.readline
INF = float('inf')
MOD = 10 ** 9 + 7


def inpl(): return list(map(int, input().split()))


# aのp乗を求めるアルゴリズム
# MOD版
def pow_mod(a, p):
    if p == 0: return 1

    if p % 2 == 0:
        half_p = p // 2
        half = pow_mod(a, half_p)
        return half * half % MOD
    else:
        return a * pow_mod(a, p - 1) % MOD


def solve(N, A):
    # 階乗N!を求める
    fact = [1] * N
    for i in range(1, N):
        fact[i] = fact[i - 1] * (i + 1) % MOD

    # 1/N!の逆元を求める
    fact_inv = [1] * N
    fact_inv[-1] = pow_mod(fact[-1], MOD - 2)
    for i in range(N - 1, 0, -1):
        tmp = fact_inv[i] * (i + 1)
        tmp %= MOD
        fact_inv[i - 1] = tmp

    # 1/kを求める
    inv = [1]
    for i in range(1, N):
        inv.append((fact[i - 1] * fact_inv[i]) % MOD)

    # 1/kの累積和を求める
    inv_sum = [1]
    for i in range(1, N):
        inv_sum.append((inv_sum[-1] + inv[i]) % MOD)

    # 累積和の結果を係数としてAiに掛けて、加算する
    ans = 0
    for i in range(N):
        ans += A[i] * (inv_sum[i] + inv_sum[N - 1 - i] - 1)
        ans %= MOD

    # ansにN!を掛けたものを返す
    return ans * fact[-1] % MOD


N = int(input())
A = inpl()
print(solve(N, A))
