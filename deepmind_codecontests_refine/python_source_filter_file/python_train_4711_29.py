import math

t = int(input())

for i in range(t):

    n = int(input())

    l = [int(x) for x in input().split()]

    # l = sorted(l)
    z=10000
    for j in range(n-1):
        for k in range(1,n):

            p = abs(l[j]-l[k])

            if p<z:
                z=p

    print(z)
