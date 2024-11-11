from collections import defaultdict as di
MOD = int(1e9+7)

bells = di(int)
bells[0,0] = 1
K=60
for j in range(1,K):
    bells[0,j] = bells[j-1,j-1]
    for i in range(j):
        bells[i+1,j] = (bells[i,j] + bells[i,j-1])%MOD
    
def bellman(n):
    return bells[n-1,n-1]

m,n = [int(x) for x in input().split()]
Tlist = []

for _ in range(n):
    Tlist.append(input())
numbs = []
for i in range(m):
    numb = []
    for j in range(n):
        numb.append(Tlist[j][i])
    numbs.append(int(''.join(numb),2))

eqsize = di(lambda:0)
for numb in numbs:
    eqsize[numb]+=1
sets = []
for numb in eqsize:
    sets.append(eqsize[numb])

parts = 1
for s in sets:
    parts*=bellman(s)
    parts%=MOD
print(parts)
