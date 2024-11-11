#E
from collections import Counter
n,p=map(int,input().split())
s=input()
cnt=0

if p==2 or p==5:
    for i in range(n):
        if int(s[i])%p==0:
            cnt+=i+1
else:
    U=[0]*(n+1)
    for i in range(n,0,-1):
        U[i-1]=(int(s[i-1])*pow(10,n-i,p)+U[i])%p
    #print(U)
    C=Counter(U)
    for c in C.values():
        cnt+=c*(c-1)//2

print(cnt)