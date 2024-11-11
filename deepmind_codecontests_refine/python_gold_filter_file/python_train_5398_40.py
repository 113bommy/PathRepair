N,K=map(int,input().split())
L=list(map(int,input().split()))

import itertools
l=[i for i in range(1,N)]
Arr=list(itertools.combinations(l,K-1)) #Lの中から2個

#print(Arr)

ans=10**12
for i in Arr:
    cost=0
    hight=L[0]
    for j in range(1,N):
        if j in i:
            if hight<L[j]:
                hight=L[j]
            else:
                cost+=(hight-L[j]+1)
                hight+=1
        else:
            hight=max(hight,L[j])
    if ans>cost:
        ans=cost
print(ans)