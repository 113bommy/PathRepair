n,m,k=map(int,input().split())
yadra=[0]*n
yach=[True]*(k+1)
yachzt=[[] for i in range(k+1)]
l2=[list(map(int,input().split())) for i in range(n)]
for i in range(m):
    for i2 in range(n):
        if l2[i2][i] and (not yadra[i2]):
            yachzt[l2[i2][i]].append(i2)
    for i2 in range(k+1):
        if (len(yachzt[i2])>=2) or (not yach[i2]) :
            yach[i2]=False
            for a in yachzt[i2]:
                yadra[a]=(i+1)
    yachzt=[[] for i2 in range(k+1)]
for fl in yadra:
    print(fl)
            
