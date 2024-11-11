def findCulprit(p, d, i):
    if i in d:
        print(i, end = " ")
    else:
        d.append(i)
        findCulprit(p, d, p[i-1])

n = int(input())
pl = [*map(int, input().split())]

for i in range(n):
    findCulprit(pl, [], i+1)



