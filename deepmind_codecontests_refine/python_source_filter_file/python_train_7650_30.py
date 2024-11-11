n = int(input())

sie = [1]*1200

prms = []

sie[1]=0
sie[0] = 0
for i in range(2,1200):
    if sie[i]:
        for j in range(i*i, 1200, i):
            sie[j] = 0

for i in range(len(sie)):
    if sie[i]:
        prms.append(i)

ans = 0
op = []
for i in range(len(prms)):
    if prms[i]<=n:
        k = 1
        while prms[i]*k < n:
            op.append(prms[i]*k)
            k+=1
            ans+=1
        
print(ans)
print(*op)
