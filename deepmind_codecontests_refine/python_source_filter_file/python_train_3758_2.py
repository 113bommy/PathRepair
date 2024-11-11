#!/usr/bin/python3

def solve(N, M, A):
    pv = [0] * M
    pm = [[] for _ in range(M)]
    allm = {}

    for (p, c) in A:
        p -= 1
        pv[p] += 1
        if p == 0:
            continue
        pm[p].append(c)
        if c not in allm:
            allm[c] = 0
        allm[c] += 1
    for m in pm:
        m.sort()
    allml = list(allm)
    allml.sort()

    maxv = max(pv)

    best = 10 ** 9 * 3000 + 1

    for iv in range(1, min(maxv + 2, N + 1)):
        allmrest = dict(allm)
        cost = 0

        reqd = 0
        if pv[0] < iv:
            reqd = iv - pv[0]

        got = 0
        for i in range(1, M):
            if pv[i] >= iv:
                ad = pv[i] - iv + 1
                for j in range(ad):
                    cost += pm[i][j]
                    allmrest[pm[i][j]] -= 1
                got += ad

        if reqd > got:
            for m in allml:
                c = allmrest[m]
                toget = min(reqd - got, c)
                cost += toget * m
                got += c
                if reqd == got:
                    break

        if reqd > got:
            continue

        best = min(best, cost)

    return best


def main():
    N, M = [int(e) for e in input().split(' ')]
    A = [[int(e) for e in input().split(' ')] for _ in range(N)]
    print(solve(N, M, A))


if __name__ == '__main__':
    main()
