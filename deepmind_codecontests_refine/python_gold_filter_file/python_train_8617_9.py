#!python3

import sys

from bisect import bisect, insort_left

iim = lambda: map(int, input().rstrip().split())

def resolve():
    N = int(input())
    S = list(input())
    Q = int(input())

    c0 = ord('a')
    S1 = [[] for i in range(26)]
    for i, c1 in enumerate(S):
        ci = ord(c1) - c0
        S1[ci].append(i)

    ans = []
    for cmd, i, j in (line.split() for line in sys.stdin):
        i = int(i) - 1
        if cmd == "1":
            if S[i] == j:
                continue

            c1 = ord(S[i]) - c0
            s1 = S1[c1]
            s1.pop(bisect(s1, i)-1)
            S[i] = j
            c1 = ord(j) - c0
            insort_left(S1[c1], i)
        elif cmd == "2":
            j = int(j) - 1
            num = 0

            for s1 in S1:
                ls = len(s1)
                k = bisect(s1, i-1, 0, ls)

                if k == ls:
                    continue
                if i <= s1[k] <= j:
                    num += 1

            ans.append(num)

    print(*ans, sep="\n")

if __name__ == "__main__":
    resolve()
