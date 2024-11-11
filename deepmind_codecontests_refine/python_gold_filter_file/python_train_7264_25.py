from bisect import bisect_left, bisect_right
import sys
input = sys.stdin.readline

def solve():
    MOD = 998244353
    INF = float('inf')

    N = int(input())
    XDs = [tuple(map(int, input().split())) for _ in range(N)] + [(10**12, 0)]

    XDs.sort()
    Xs = [X for X, D in XDs]

    def max2(x, y): return x if x >= y else y
    def makeBIT(numEle):
        numPow2 = 2 ** (numEle-1).bit_length()
        data = [-INF] * (numPow2+1)
        return data, numPow2
    def setInit(As):
        for iB, A in enumerate(As, 1):
            data[iB] = A
        for iB in range(1, numPow2):
            i = iB + (iB & -iB)
            data[i] = max2(data[i], data[iB])
    def setValue(iA, A):
        iB = iA + 1
        while iB <= numPow2:
            data[iB] = max2(data[iB], A)
            iB += iB & -iB
    def getMax(iA):
        iB = iA + 1
        ans = -INF
        while iB > 0:
            ans = max2(ans, data[iB])
            iB -= iB & -iB
        return ans

    data, numPow2 = makeBIT(N+1)
    setInit(list(range(N)))

    dp = [0] * (N+1)
    dp[-1] = 1
    for i in reversed(range(N)):
        X, D = XDs[i]
        j = bisect_left(Xs, X+D) - 1
        pos = getMax(j)
        setValue(i, pos)
        dp[i] = dp[pos+1] + dp[i+1]
        dp[i] %= MOD

    print(dp[0])


solve()
