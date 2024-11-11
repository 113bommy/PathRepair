testcases = int(input())

for t in range(testcases):
    poolSize = int(input())
    piranhas = [int(p) for p in input().strip().split()]
    mx = max(piranhas)
    mn = min(piranhas)
    if mx == mn:
        print(-1)
        continue
    dominant = -1
    for pIndex in range(poolSize):
        if mx != piranhas[pIndex]:
            continue
        if pIndex == 0:
            if piranhas[0] > piranhas[1]:
                dominant = 1
                break
        elif pIndex == poolSize - 1:
            if piranhas[poolSize - 2] < piranhas[poolSize - 1]:
                dominant = poolSize
                break
        elif piranhas[pIndex] > piranhas[pIndex + 1] or\
             piranhas[pIndex] > piranhas[pIndex - 1]:
            dominant = pIndex + 1
            break
    print(dominant)


