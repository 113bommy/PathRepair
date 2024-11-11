# created 2020. 9. 2. 13:01
#!/usr/bin/env python3
from sys import stdin


def solve():
    n, k = map(int, stdin.readline().split())
    seq = list(map(int, stdin.readline().split()))

    suffix = [[0, 0] for i in range(n)]

    cursum = 0
    for i in range(n-1, n-k-1, -1):
        cursum += seq[i]

    suffix[n-k] = [cursum, n-k]
    for i in range(n-k-1, -1, -1):
        suffix[i] = suffix[i+1]
        cursum += seq[i] - seq[i+k]
        if cursum >= suffix[i+1][0]:
            suffix[i] = [cursum, i]

    prefix = [0 for i in range(n)]
    for i in range(k):
        prefix[0] += seq[i]

    for i in range(1, n-k):
        prefix[i] = prefix[i-1] + seq[i+k-1] - seq[i-1]

    maxsum = 0
    ans = [-1,-1]
    for i in range(n-k-k):
        cursum = prefix[i] + suffix[i+k][0]
        if cursum>maxsum:
            maxsum = cursum
            ans = [i+1, suffix[i+k][1]+1]

    print(ans[0], ans[1])


solve()