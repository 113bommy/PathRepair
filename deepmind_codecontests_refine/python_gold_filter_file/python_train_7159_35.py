import sys
input = sys.stdin.readline

def solve():
    def makeBIT(numEle):
        numPow2 = 2 ** (numEle-1).bit_length()
        data = [0] * (numPow2+1)
        return data, numPow2
    def addValue(iA, A):
        iB = iA + 1
        while iB <= numPow2:
            data[iB] += A
            iB += iB & -iB
    def getSum(iA):
        iB = iA + 1
        ans = 0
        while iB > 0:
            ans += data[iB]
            iB -= iB & -iB
        return ans
    def getRangeSum(iFr, iTo):
        return getSum(iTo) - getSum(iFr-1)

    N, Q = map(int, input().split())
    cs = list(map(lambda x: int(x)-1, input().split()))
    LRs = []
    Lss = [[] for _ in range(N)]
    for i in range(Q):
        L, R = map(int, input().split())
        L, R = L-1, R-1
        LRs.append((L, R))
        Lss[R].append((L, i))

    data, numPow2 = makeBIT(Q)

    anss = [0] * Q
    posRights = [-1] * N
    for R, c in enumerate(cs):
        if posRights[c] != -1:
            addValue(posRights[c], -1)
        addValue(R, 1)
        posRights[c] = R
        for L, i in Lss[R]:
            anss[i] = getRangeSum(L, R)

    print('\n'.join(map(str, anss)))


solve()
