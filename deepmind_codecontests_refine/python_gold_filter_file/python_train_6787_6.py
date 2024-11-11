mod = 10 ** 9 + 7


def getAns(maxSide):
    if maxSide == 1:
        return 2
    if maxSide == 2:
        return 4
    dpSide = [0] * maxSide
    for i in range(len(dpSide)):
        dpSide[i] = [0, 0]

    dpSide[0] = [1, 1]
    dpSide[1] = [2, 2]
    f = True
    for i in range(1, len(dpSide) - 1):
        dpSide[i + 1][0] += dpSide[i][1]
        dpSide[i + 1][1] += dpSide[i][0]
        dpSide[i + 1][1] += dpSide[i - 1][0]
        dpSide[i + 1][0] += dpSide[i - 1][1]
        dpSide[i + 1][0] %= mod
        dpSide[i + 1][1] %= mod

    return sum(dpSide[maxSide - 1]) % mod


n, m = map(int, input().split())
print((getAns(n) + getAns(m) - 2) % mod)
