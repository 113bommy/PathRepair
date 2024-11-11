import io
import os

from collections import Counter, defaultdict, deque


def solve(N, ):
    if N % 2 == 0:
        return "YES"
    return "NO"


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    T = int(input())
    for t in range(T):
        N, = [int(x) for x in input().split()]
        ans = solve(N, )
        print(ans)
