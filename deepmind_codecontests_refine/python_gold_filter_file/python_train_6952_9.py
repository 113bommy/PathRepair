import itertools
import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

# MOD = 998244353


A, B, C = [sys.stdin.buffer.readline().decode().rstrip() for _ in range(3)]
A = list(map(ord, A))
B = list(map(ord, B))
C = list(map(ord, C))

memo = {}
Q = ord('?')


def get_ok_idx(A, B):
    key = str(A) + str(B)
    if key in memo:
        return memo[key]
    ret = []
    for i in range(len(A) + 1):
        for a, b in zip(A[i:], B):
            if a != b and a != Q and b != Q:
                break
        else:
            ret.append(i)
    memo[key] = ret
    return ret


# A = np.array(A, dtype=int)
# B = np.array(B, dtype=int)
# C = np.array(C, dtype=int)

def solve(A, B, C):
    ok_ab = get_ok_idx(A, B)
    ok_bc = get_ok_idx(B, C)
    ok_cb = get_ok_idx(C, B)
    ok_ac = get_ok_idx(A, C)

    ok_ab_flags = [False] * (len(A) + 1)
    ok_bc_flags = [False] * (len(B) + 1)
    ok_cb_flags = [False] * (len(C) + 1)
    ok_ac_flags = [False] * (len(A) + 1)
    for i in ok_ab:
        ok_ab_flags[i] = True
    for i in ok_bc:
        ok_bc_flags[i] = True
    for i in ok_cb:
        ok_cb_flags[i] = True
    for i in ok_ac:
        ok_ac_flags[i] = True

    ret = INF
    for ab, bc in itertools.product(ok_ab, ok_bc):
        if ab + bc >= len(A) or ok_ac_flags[ab + bc]:
            ret = min(ret, max(len(A), ab + len(B), ab + bc + len(C)))
    for ac, bc in itertools.product(ok_ac, ok_bc):
        if ac - bc < 0:
            continue
        if ac - bc >= len(A) or ok_ab_flags[ac - bc]:
            ret = min(ret, max(len(A), ac - bc + len(B), ac + len(C)))
    for ab, ac in itertools.product(ok_ab, ok_ac):
        if ab < ac and (ac - ab >= len(B) or ok_bc_flags[ac - ab]):
            ret = min(ret, max(len(A), ab + len(B), ac + len(C)))
        elif ac < ab and (ab - ac >= len(C) or ok_cb_flags[ab - ac]):
            ret = min(ret, max(len(A), ab + len(B), ac + len(C)))
    return ret


ans = len(A) + len(B) + len(C)
ans = min(ans, solve(A, B, C))
ans = min(ans, solve(A, C, B))
ans = min(ans, solve(B, A, C))
ans = min(ans, solve(B, C, A))
ans = min(ans, solve(C, A, B))
ans = min(ans, solve(C, B, A))
print(ans)
