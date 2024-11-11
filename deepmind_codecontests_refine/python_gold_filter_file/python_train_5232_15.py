import collections
import string


def main():
    n = int( input() )
    a = list(map(int, input().split()))

    b = sorted(a)
    d = collections.defaultdict(list)
    f = collections.defaultdict(list)

    for i in range(n-1, -1, -1):
        d[ b[i] ].append(i)
    
    tmp = []
    for i in range(n):

        whereInB = d[ a[i] ][-1]

        if a[i] in f:
            z = 1 + f[a[i]][-1]
            if whereInB != 0 and (b[whereInB - 1] in f):
                prevNumberList = f[b[whereInB - 1]]
                p = prevNumberList
                z = max(z, p[0] + len(p))
            f[a[i]].append(z)
            tmp.append(f[a[i]][-1])
            continue

        if whereInB == 0 or (b[whereInB - 1] not in f):
            f[a[i]].append(1)
        else:
            if len(d[b[whereInB - 1]]) == len(f[b[whereInB - 1]]):
                prevNumberList = f[b[whereInB - 1]]
                p = prevNumberList
                f[a[i]].append( p[0] + len(p) )
            else:
                f[a[i]].append(1 + len(f[b[whereInB - 1]]))

        tmp.append(f[a[i]][-1])

    print (n - max(map(max, f.values())))



tn = int(input())
for _ in range(tn):
    main()