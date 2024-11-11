def findCulprit(p, d, i):
    if i in d:
        print(i, end = " ")
    else:
        d.append(i)
        findCulprit(p, d, p[i-1])

n = int(input())
p = [*map(int, input().split())]

for i in range(n):
    findCulprit(p, [], p[i])



