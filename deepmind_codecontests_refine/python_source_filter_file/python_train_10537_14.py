from bisect import *


def read_ints(): return map(int, input().split())


def read_int(): return int(input())


T = read_int()
for _ in range(T):
    s = str(input())
    t = str(input())

    occ = dict()
    for ii, cc in enumerate(s):
        if cc not in occ:
            occ[cc] = [ii]
        else:
            occ[cc].append(ii)

    print(occ)
    s_ind = 0
    ans = 1
    for i, c in enumerate(t):
        if c not in occ:
            ans = -1
            break
        else:
            k = bisect_left(occ[c], s_ind)
            if k == len(occ[c]):
                ans += 1
                s_ind = occ[c][0] + 1
            else:
                s_ind = occ[c][k] + 1

    print(ans)
