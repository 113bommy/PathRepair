N,K=map(int,input().split())
P=list(map(int,input().split()))
C=list(map(int,input().split()))
a=[]
ans=-10**10
for i in range(N):
    idx=P[i]-1
    z=set()
    rl=[]
    c=0
    tc=0
    while idx not in z and c<K:
        tc+=C[idx]
        rl.append(tc)
        ans=max(ans,tc)
        z.add(idx)
        idx=P[idx]-1
        c+=1
    if c<K:
        d,m=divmod(K,c)
        if m==0:
            d-=1
            m=c
        tc=d*tc
        tc+=max(rl[:m])
        ans=max(ans,tc)
print(ans)