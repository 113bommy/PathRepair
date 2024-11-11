n, m, k = map(int, input().split())
roads = []
flagstores = [0]*n
mi = 10**9+1
for i in range(m):
    x, y, l = map(int, input().split())
    roads.append((x, y, l))
if(k>0):
    stores = list(map(int, input().split()))
    for i in range(k):
        flagstores[stores[i]-1]=1
    for i in range(m):
        if(flagstores[roads[i][0]-1]==1 and flagstores[roads[i][1]-1]==0 or flagstores[roads[i][1]-1]==1 and flagstores[roads[i][0]-1]==0):
            mi= min(mi, roads[i][2])
    if(m==10**9+1):
        print(-1)
    else:
        print(mi)
else:
    print(-1)