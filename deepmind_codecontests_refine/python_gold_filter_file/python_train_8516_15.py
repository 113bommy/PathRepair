def solve():
    N = int(input())
    Ss = input()
    Q = int(input())
    ks = list(map(int, input().split()))

    anss = []
    for k in ks:
        numD = numM = numDM = numDMC = 0
        for i in range(N):
            S = Ss[i]
            if S == 'D':
                numD += 1
            elif S == 'M':
                numM += 1
                numDM += numD
            elif S == 'C':
                numDMC += numDM

            if i >= k-1:
                S = Ss[i-k+1]
                if S == 'D':
                    numD -= 1
                    numDM -= numM
                elif S == 'M':
                    numM -= 1

        anss.append(numDMC)

    print('\n'.join(map(str, anss)))


solve()
