from sys import exit
info = input().split()
redsock = int(info[0])
bluesock = int(info[1])
hipsterpairs = 0
regularpairs = 0

if redsock < bluesock:
    hipsterpairs = redsock
    bluesock = bluesock - redsock
    redsock = 0
    regularpairs = bluesock//2
elif redsock == bluesock:
    print(redsock)
    exit(0)
else:
    hipsterpairs = bluesock
    redsock = redsock - bluesock
    bluesock = 0
    regularpairs = redsock//2

print(hipsterpairs, regularpairs)
