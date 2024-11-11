def answer():
    rc=[0]*(n+1)
    lc=[0]*(n+1)

    for i in range(n):
        if(i < l):lc[a[i]]+=1
        else:rc[a[i]]+=1

    v=n//2
    left=max(0,v-l) + max(0,v-r)
    
    for i in range(n+1):
        m=min(rc[i],lc[i])

        rc[i]-=m
        lc[i]-=m

    ans,extra=0,0
    for i in range(n+1):

        if(l > r):
            v=min(lc[i]//2,left)
            ans+=v

            left-=v
            lc[i]-=2*v

            extra+=lc[i] + rc[i]
        else:
            v=min(rc[i]//2,left)
            ans+=v

            left-=v
            rc[i]-=2*v
            
            extra+=lc[i] + rc[i]

    return ans + extra//2 + left



for T in range(int(input())):

    n,l,r=map(int,input().split())

    a=list(map(int,input().split()))

    print(answer())
