import io
import os

from collections import Counter, defaultdict, deque


def solve(N, A):
    highBit = defaultdict(list)
    for pos in reversed(range(20)):
        mask = 1 << pos
        mask2 = (1 << (pos + 1)) - 1
        for x in A:
            if x & mask and x <= mask2:
                highBit[pos].append(x)
    ans = 0
    for k, v in highBit.items():
        m = len(v)
        ans += m * (m - 1) // 2


    return ans


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    TC = int(input())
    for tc in range(1, TC + 1):
        N, = [int(x) for x in input().split()]
        A = [int(x) for x in input().split()]
        ans = solve(N, A)
        print(ans)
