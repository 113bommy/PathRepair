import itertools
n,m=map(int,input().split())
edge=[[]for i in range(m+1)]

for i in range(m):
    a,b=map(int,input().split())
    edge[a].append(b)
    edge[b].append(a)
    
ans=0
for i in itertools.permutations(range(1,n+1)):
    if i[0]!=1:
        continue
    for j in range(n-1):
        if i[j+1] not in edge[i[j]]:
            break
    else:
        ans+=1
print(ans)