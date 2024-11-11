import sys
from collections import Counter


def solve():
    n, k = list(map(int, sys.stdin.readline().split()))
    a = sorted(list(map(int, sys.stdin.readline().split())))
    cnt = Counter(a)
    opr = cnt.copy()
    opr.clear()
    result = 10**7

    for val in a:
        cur_opr = 0
        while (val > 0):
            if (cnt[val] == k):
                result = min(result, opr[val])
            val //= 2
            cur_opr += 1
            opr[val] += cur_opr
            cnt[val] += 1

    print(result)


solve()
