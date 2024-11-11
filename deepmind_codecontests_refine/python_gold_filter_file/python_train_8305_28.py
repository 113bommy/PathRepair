def solve():
    N = int(input())
    Ps = list(map(int, input().split()))

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

    data, numPow2 = makeBIT(N)

    iPs = list(range(N))
    iPs.sort(key=lambda iP: Ps[iP])

    ans = 0
    for iP in reversed(iPs):
        v = getSum(iP)
        Bs = []
        for x in range(v-1, v+3):
            if x <= 0:
                L = -1
            elif getSum(numPow2-1) < x:
                L = N
            else:
                maxD = numPow2.bit_length()-1
                L = 0
                S = 0
                for d in reversed(range(maxD)):
                    if S+data[L+(1<<d)] < x:
                        S += data[L+(1<<d)]
                        L += 1<<d
            Bs.append(L)

        num = (Bs[1]-Bs[0])*(Bs[2]-iP) + (iP-Bs[1])*(Bs[3]-Bs[2])
        ans += Ps[iP] * num
        addValue(iP, 1)

    print(ans)


solve()
