n=int(input())
l=list(map(int,input().split()))
from itertools import combinations
from copy import deepcopy
answ=[]
for i in combinations(l,2):
    ls=deepcopy(l)
    for j in i:
        ls.remove(j)
    ls.sort()
    ans=0
    for i in range(len(ls)-1):
        ans+=ls[i+1]-ls[i]
    answ.append(ans)
print(min(answ))
