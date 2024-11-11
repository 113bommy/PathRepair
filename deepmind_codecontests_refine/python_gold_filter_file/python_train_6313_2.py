import configparser
import math
import sys

input = sys.stdin.readline


def get(l, r, cumsum):

    res = cumsum[r]
    if l >= 1:
        res -= cumsum[l-1]

    return res


def can(l, r, cumsum, am):
    return am >= get(l, r, cumsum)


def main():

    n = int(input())

    v = [int(x) for x in input().split(' ')]
    t = [int(x) for x in input().split(' ')]

    cumsum = [0 for i in range(n)]
    cumsum[0] = t[0]
    for i in range(1, n):
        cumsum[i] = t[i] + cumsum[i-1]

    ans = [0 for i in range(n)]
    alive = [[] for i in range(n)]
    for i in range(n):

        pos = i-1
        for j in range(25, -1, -1):
            jump = 2**j

            if pos+jump < n and can(i, pos+jump, cumsum, v[i]):
                pos += jump

        if pos == i - 1:
            alive[i].append(v[i])
        else:
            ans[i] += 1
            if pos + 1 < n:
                ans[pos+1] -= 1
            if pos != n-1 and v[i] > get(i, pos, cumsum):
                alive[pos+1].append(v[i] - get(i, pos, cumsum))

    for i in range(1, n):
        ans[i] += ans[i-1]

    res = [0 for i in range(n)]
    for i in range(n):
        res[i] = ans[i]*t[i]
        for j in alive[i]:
            res[i] += j


    for i in res:
        print(i, end=' ')



if __name__ == '__main__':
    main()
