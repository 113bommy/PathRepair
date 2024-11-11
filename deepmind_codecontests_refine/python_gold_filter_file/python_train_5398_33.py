import itertools
import copy
N, K = map(int, input().split())
A =list(map(int, input().split()))
ans=10**15
for c in itertools.product([0,1],repeat=N):
    a=copy.deepcopy(A)
    sm=0
    for i in range(1,N):
        if c[i]==1:
            if a[i]<=max(a[:i]):
                sm+=max(a[:i])-a[i]+1
                a[i]=max(a[:i])+1
    cnt=1
    for i in range(1,N):
        if max(a[:i])<a[i]:
            cnt+=1
    if cnt==K:
        ans=min(ans,sm)
print(ans)

