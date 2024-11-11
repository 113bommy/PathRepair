#greedy customers
N=int(input())
ans=0
d=[int(input()) for _ in range(N)]
if d[0]>1:
    ans+=d[0]-1
d[0]=1
now=2
for i in range(1,N):
    if d[i]==now:
        now+=1
    else:
        #d[i]!=now:
        if d[i]<now:
            pass
        elif d[i]>now:
            if d[i]%now==0:
                K=d[i]//now
                if K==2:
                    ans+=1
                    d[i]=1
                elif K>2:
                    ans+=K-2
                    d[i]=1                
            elif d[i]%now!=0:
                u,v=divmod(d[i],now)
                ans+=u
                d[i]=v
print(ans)                   