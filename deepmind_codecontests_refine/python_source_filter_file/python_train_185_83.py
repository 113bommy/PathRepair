import math
N,P = map(int,input().split(" "))

i = 2
plimes = []

if N == 1:
    print(P)
else:
    while(i <= math.sqrt(P)):
        if P % i == 0:
            P = P // i
            plimes.append(i)
        elif i == 2:
            i += 1
        else:
            i += 2
    plimes.append(P)


    resalt = 1
    j = 0

    while(len(plimes) > j):
        k =plimes.count(plimes[j])
        if k // N >= 1:
            resalt = resalt * plimes[j] * (k//N)
        j = j + k
    print(resalt)
