import math
import sys
from bisect import *


def get_ints(): return list(map(int, sys.stdin.readline().strip().split()))

def solve(N, M, pos, dirs):
    can = {
        "R": [],
        "L_odd": [],
        "L_even": [],
    }
    for i in range(N):
        if dirs[i] == "R":
            can[dirs[i]].append((pos[i], i))
        else:
            if pos[i] & 1:
                can["L_odd"].append((pos[i], i))
            else:
                can["L_even"].append((pos[i], i))

    ans = [-1] * N
    for key in can:
        can[key].sort()

    next_L = {
        "odd": [],
        "even": [],
    }
    while can["R"]:
        r, r_idx = can["R"].pop()
        if r & 1:
            key = "L_odd"
        else:
            key = "L_even"

        idx = bisect_left(can[key], (r, r_idx))
        if 0 <= idx < len(can[key]) and can[key][idx][0] > r:
            l, l_idx = can[key].pop(idx)
            ans[r_idx] = (l + r) // 2 - l
            ans[l_idx] = (l + r) // 2 - l
        else:
            if r & 1:
                next_L["odd"].append((r, r_idx))
            else:
                next_L["even"].append((r, r_idx))

    next_next_L = {
        "odd": [],
        "even": [],
    }
    for key in ["odd", "even"]:
        for i in range(0, len(next_L[key]), 2):
            if i + 1 < len(next_L[key]):
                v1, idx1 = next_L[key][i]
                v2, idx2 = next_L[key][i + 1]
                time = abs(v1 - v2) // 2 + M - v1
                ans[idx1] = time
                ans[idx2] = time
            else:
                next_next_L[key].append(next_L[key][i])

    next_next_R = {
        "odd": [],
        "even": [],
    }
    for key in ["L_odd", "L_even"]:
        for i in range(0, len(can[key]), 2):
            if i + 1 < len(can[key]):
                v1, idx1 = can[key][i]
                v2, idx2 = can[key][i + 1]
                time = abs(v1 - v2) // 2 + v1
                ans[idx1] = time
                ans[idx2] = time
            else:
                next_next_R[key[2:]].append(can[key][i])

    # print(next_next_L)
    # print(next_next_R)
    for key in ["odd", "even"]:
        L_idx, R_idx = len(next_next_L[key]) - 1, 0
        while L_idx >= 0 and R_idx < len(next_next_R[key]):
            l, l_idx = next_next_L[key][L_idx]
            r, r_idx = next_next_R[key][R_idx]

            time = (M * 2 - (l - r)) // 2
            ans[l_idx] = time
            ans[r_idx] = time

            L_idx -= 1
            R_idx += 1

    # for key in can:
    #     print(key, can[key])
    return (" ").join(map(str, ans))

T = int(input())
for _ in range(T):
    N, M = get_ints()
    pos = get_ints()
    dirs = input().split()
    print(solve(N, M, pos, dirs))
