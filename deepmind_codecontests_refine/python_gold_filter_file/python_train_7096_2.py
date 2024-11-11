n,m=[int(x) for x in input().split()]
ARR=[0 for i in range(n-1)]
BAADME=[]
for _ in range(m):
    a,l,r=[int(x) for x  in input().split()]
    if a==1:
        for e in range(l-1,r-1): ARR[e]=1
    else: BAADME.append([l,r])
flag=0
for [l,r] in BAADME:
    cflag=0
    for e in range(l-1,r-1):
        if ARR[e]==0: cflag=1; break
    if cflag==0: flag=1; break
if flag==1: print("NO")
else:
    print("YES")
    BARR=[1]
    start=1
    for i in range(n-2,-1,-1):
        if ARR[i]==0: start+=1
        BARR.append(start)
    for i in range(n-1,-1,-1): print(BARR[i],end=" ")
