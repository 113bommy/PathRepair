import sys
import heapq
import math


lines = sys.stdin.read().splitlines()
n, m, k = [int(x) for x in lines[0].split(' ')]
elems = [int(x) for x in lines[1].split(' ')]
sortedElems = sorted(elems)
if m*k >= n:
    print(sum(elems))
    for i in range(0, k):
        print((i+1)*n//k, end=' ' if i < k-1 else '\n')
else:
    boundaryElem = sortedElems[-m*k]
    # print('boundaryElem: ' + str(boundaryElem))
    count = sortedElems[-m*k:].count(boundaryElem)
    # print('count: ' + str(count))
    upToM = 0
    print(sum(sortedElems[-m*k:]))
    for index in range(0, len(elems)):
        i = elems[index]
        if i > boundaryElem:
            upToM += 1
            if upToM > m:
                print(index, end=' ')
                upToM = 1
        elif i == boundaryElem and count > 0:
            count -= 1
            upToM += 1
            if upToM > m:
                print(index, end=' ')
                upToM = 1
        # print(upToM)
    print()





