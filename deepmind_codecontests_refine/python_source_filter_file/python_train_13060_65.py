import math
import sys

def isP(n):
    if n == 2:
        return True
    a = int(math.ceil(math.sqrt(n)))
    for i in range(2, a):
        if n % i == 0:
            return False
    return True

n = int(input())
for i in range(n-1, 1, -1):
    if not isP(i):
        for j in range(2, n-1):
            if not isP(j):
                if j + i == n:
                    print(str(j), str(i) )
                    sys.exit(0)
                elif j + i > n:
                    break

