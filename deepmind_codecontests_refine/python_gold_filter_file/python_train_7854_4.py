n = int(input())
lis = []
for i in range(n):
    k = [int(x) for x in input().split()]
    lis.append(k)
slis = sorted(lis,key = lambda x: (x[0],x[1]))

m = min(slis[0][0],slis[0][1])
for i in range(1,n):
    if slis[i][1] >= m:
        m = min(slis[i][0],slis[i][1])

    else:
        m = slis[i][0]


print(m)

