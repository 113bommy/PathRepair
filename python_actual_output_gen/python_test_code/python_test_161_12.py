a, b, n = map(int, input().split())

i = 0
while n > 0:
    if i % 2 == 0:
        aE = a
        nE = n
        while nE > 0:
            c = aE % nE
            aE = nE
            nE = c
        n -= aE
    else:
        bE = b
        nE = n
        while nE > 0:
            c = bE % nE
            bE = nE
            nE = c
        n -= bE
    i += 1

if i % 2 == 0:
    print(0)
else:
    print(1)



