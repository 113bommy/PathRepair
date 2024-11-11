from collections import Counter
N,K=map(int,input().split())
N=list(map(int,input().split()))
A=Counter(N)
C=list(A.values())
C=C.sort(reverse=True)
if len(C)<=K:
    print(0)
else:
    ans=sum(C[-(len(C)-K):])
    print(ans)