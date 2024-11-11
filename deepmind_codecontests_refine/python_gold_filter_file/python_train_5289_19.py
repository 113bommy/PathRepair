import sys
input = sys.stdin.readline

def solve():
    MOD = 998244353

    N = int(input())
    pts = [tuple(map(int, input().split())) for _ in range(N)]

    iXs = list(range(N))
    iXs.sort(key=lambda iX: pts[iX][0])
    iYs = list(range(N))
    iYs.sort(key=lambda iY: pts[iY][1])
    odrYs = [0]*(N)
    for odrY, iY in enumerate(iYs):
        odrYs[iY] = odrY

    def init(As):
        numPow2 = 2 ** (len(As)-1).bit_length()
        data = [0] * (numPow2+1)
        return data, numPow2
    def addValue(iA, A):
        iA += 1
        while iA <= numPow2:
            data[iA] += A
            iA += iA & -iA
    def getSum(iA):
        iA += 1
        ans = 0
        while iA > 0:
            ans += data[iA]
            iA -= iA & -iA
        return ans

    numPtss = [[0]*(4) for _ in range(N)]

    data, numPow2 = init([0]*N)
    for odr, iX in enumerate(iXs):
        y = odrYs[iX]
        num = getSum(y)
        numPtss[iX][0] = num
        numPtss[iX][1] = odr - num
        addValue(y, 1)

    data, numPow2 = init([0]*N)
    for odr, iX in enumerate(reversed(iXs)):
        y = odrYs[iX]
        num = getSum(y)
        numPtss[iX][2] = num
        numPtss[iX][3] = odr - num
        addValue(y, 1)

    def getPows(base, n, MOD):
        pows = [1] * (n+1)
        for x in range(1, n+1):
            pows[x] = (pows[x-1] * base) % MOD
        return pows

    pow2s = getPows(2, N, MOD)

    ans = 0
    for numPts in numPtss:
        num = pow2s[N-1]
        nums = [pow2s[k] for k in numPts]
        num += (nums[0]-1)*(nums[1])*(nums[2])*(nums[3]-1) % MOD
        num += (nums[0])*(nums[1]-1)*(nums[2]-1)*(nums[3]) % MOD
        num -= (nums[0]-1)*(nums[1]-1)*(nums[2]-1)*(nums[3]-1) % MOD
        ans += num % MOD
        ans %= MOD

    print(ans)


solve()
