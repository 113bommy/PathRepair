import io
import os

from collections import Counter, defaultdict, deque


def solve(Q, X, queries):
    freq = Counter()
    ans = []
    mex = 0
    wholeRows = 0
    for y in queries:
        freq[y % X] += 1
        while freq[mex % X] >= wholeRows + 1:
            mex += 1
            if mex % X == 0:
                wholeRows += 1
        ans.append(mex)

    return "\n".join(map(str, ans))


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    Q, X = [int(x) for x in input().split()]
    queries = []
    for i in range(Q):
        (y,) = [int(x) for x in input().split()]
        queries.append(y)
    ans = solve(Q, X, queries)
    print(ans)
