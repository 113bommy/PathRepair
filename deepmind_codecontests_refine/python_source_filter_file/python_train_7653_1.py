import sys
import math

n, k = [int(x) for x in (sys.stdin.readline()).split()]
ai = [int(x) for x in (sys.stdin.readline()).split()]

z = n
res = 0
while(z > 0):
    i = 0
    f = False

    while(i < z):
        if(ai[i] == k):
            z = i - 1
            break
        else:
            f = True
            v = ai[i]
            j = i
            while(j < z):
                if(v != ai[j]):
                    break
                j += 1
            i = j
            ai[j - 1] += 1

    if(f):
        res += 1

print(res)       