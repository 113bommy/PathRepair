from itertools import accumulate

n,m,q = map(int,input().split())
li = [[0 for i in range(n+1)]for j in range(n+1)]
lin = []

for i in range(m):
    l,r = map(int,input().split())
    li[l][r] += 1

for i in range(n+1):
    lin.append(list(accumulate(li[i])))

for i in range(q):
    l,r = map(int,input().split())
    point = 0
    for i in range(l,r+1):
        point += lin[i][r]-lin[i][l-1]
    print(point)