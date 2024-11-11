import os
import sys

# import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

# 解説AC
# https://twitter.com/maspy_stars/status/1185552225474498560
N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))


def test(k):
    bc = np.bincount(A)
    bc.sort()
    bc = bc[np.searchsorted(bc, 1):]
    bc = bc[::-1]
    ret = 0

    while len(bc) >= k:
        bc[:k] -= 1
        bc.sort()
        bc = bc[np.searchsorted(bc, 1):]
        bc = bc[::-1]
        ret += 1
    return ret


def cumsum(it):
    """
    累積和
    :param collections.Iterable it:
    :return:
    """
    s = 0
    ret = []
    for a in it:
        s += a
        ret.append(s)
    return ret


C = [0] * (max(A) + 1)
for a in A:
    C[a] += 1
C.sort()
cs = list(reversed(cumsum(reversed(C))))


def solve(k):
    cnt = N // k
    if C[-1] <= cnt:
        # 全部取れるとしていい
        # 最後に2つ以上余ると max_c <= cnt に矛盾する
        return cnt

    # S = N
    # i = 1
    # while i < k:
    #     # 最大値は毎回取ることにしてもう見ない
    #     S -= C[-i]
    #     cnt = S // (k - i)
    #     max_c = C[-i - 1]
    #     if max_c <= cnt:
    #         return cnt
    #     i += 1

    ng = 0
    ok = k
    while abs(ng - ok) > 1:
        i = (ng + ok) // 2
        s = N - cs[-i]
        cnt = s // (k - i)
        max_c = C[-i - 1]
        if max_c <= cnt:
            ok = i
        else:
            ng = i
    if ok < k:
        i = ok
        s = N - cs[-i]
        return s // (k - i)
    else:
        return 0


ans = [0] * N
for k in reversed(range(1, N + 1)):
    ans[k - 1] = solve(k)
print(*ans, sep='\n')
