import io
import os

from collections import Counter, defaultdict, deque


def solve(N, S, T):
    S0 = S.count("0")
    T0 = T.count("0")
    S1 = S.count("1")
    T1 = T.count("1")
    if S0 != T0 or S1 != T1:
        return -1

    consect = []
    for s, t in zip(S, T):
        if s != t:
            if not consect:
                consect.append([s, 1])
            else:
                if consect[-1][0] == s:
                    consect[-1][1] += 1
                else:
                    consect.append([s, 1])

    steps = 0
    while consect:
        nextConsect = []
        for ch, count in consect:
            if count > 1:
                if not nextConsect:
                    nextConsect.append([ch, count - 1])
                else:
                    if nextConsect[-1][0] == s:
                        nextConsect[-1][1] += count - 1
                    else:
                        nextConsect.append([ch, count - 1])
        consect = nextConsect

        steps += 1

    return steps

'''
for i in range(2 ** 5):
    for j in range(2 ** 5):
        solve(5, bin(i)[2:].rjust(5, '0'), bin(j)[2:].rjust(5, '0'))

'''

if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    (N,) = [int(x) for x in input().split()]
    S = input().decode().rstrip()
    T = input().decode().rstrip()
    ans = solve(N, S, T)
    print(ans)
