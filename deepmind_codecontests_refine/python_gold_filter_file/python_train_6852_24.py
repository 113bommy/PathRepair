#!/usr/bin/env python3
# -*- coding: utf-8 -*-

N = int(input())
a = list(map(int, input().split()))
assert len(a) == N

# 解説を参照
# https://img.atcoder.jp/arc101/editorial.pdf

def mergesort(S, f, t, T=None):
    """f <= i < j <= t かつ S[i] <= S[j] である(i,j)の個数.
       実行後, S[f:t]は整列済みになる."""
    if t - f <= 1:
        return 0

    # 作業スペース
    if T == None:
        T = [0] * len(S)

    mid = (f + t) // 2
    n1 = mergesort(S, f, mid, T)
    n2 = mergesort(S, mid, t, T)

    # マージ
    n = n1 + n2
    i = f
    j = mid
    k = f
    while i < mid:
        if j >= t or S[i] <= S[j]:
            T[k] = S[i]
            i += 1
            n += t - j
        else:
            T[k] = S[j]
            j += 1
        k += 1
    for i in range(f, k):
        S[i] = T[i]
    return n

def n_median_larger_than_or_equal_to(x):
    """aの部分列の中央値のうちx以上のものの個数"""

    # aの要素を -1, 1 に置換したリスト
    b = [-1 if e < x else 1 for e in a]

    # bの累積和
    S = [0]
    for e in b:
        S.append(S[-1] + e)

    # 和が0以上であるbの部分列の個数
    # == i < j and S[i] <= S[j] である(i,j)の個数
    return mergesort(S, 0, len(S))

# 条件を満たす x の最大値を2分探索で探す
lo = 1
hi = max(a)

ncomb = N * (N + 1) // 2    # 部分列の個数

while lo < hi:
    mid = (lo + hi + 1) // 2
    nm = n_median_larger_than_or_equal_to(mid)
    if nm >= (ncomb + 1) // 2:
        lo = mid
    else:
        hi = mid - 1

print(lo)
