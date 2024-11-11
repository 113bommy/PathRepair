# coding: utf-8
import sys
from functools import lru_cache
sys.setrecursionlimit(10 ** 9)

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
A = lr()
# 奇数の時と偶数の時、奇数の場合は真ん中を選ぶかどうか
INF = 10 ** 17

@lru_cache(None)
def F(index, n):
    if index >= N:
        return -INF
    if N - index + 2 < 2 * n:
        return -INF
    if n == 0:
        return 0
    elif n == 1:
        return max(A[index:])
    ret = max(A[index] + F(index+2, n-1), F(index+1, n))
    return ret

answer = F(0, N//2)
print(answer)
