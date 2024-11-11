t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=a[n:]
    a=a[:n]
    for i in range(n):
        if a[i]==2:
            a[i]=-1
    for j in range(n):
        if b[j]==2:
            b[j]=-1
    a=a[n-1::-1]
    d=dict()
    da=dict()
    da[a[0]]=0
    d[b[0]]=0
    d[0]=-1 
    da[0]=-1
    for i in range(1,n):
        a[i]=a[i]+a[i-1]
        b[i]=b[i]+b[i-1]
        if da.get(a[i],None)==None:
            da[a[i]]=i
        if d.get(b[i],None)==None:
            d[b[i]]=i
    s=a[i]+b[i]
    if s==0:
        print(0)
        continue
    ans=99999999999999999
    # print(s)
    for i in range(n):
        if ((s>0 and a[i]<0) or (s<0 and a[i]>0)):
            continue
        # print(i,a[i],d.get(s-a[i],None))
        if d.get(s-a[i],None)!=None:
            # print('here')
            # print(i+1+d.get(s-a[i])+1)
            ans=min(ans,i+1+d.get(s-a[i])+1)
    for i in range(n):
        if ((s>0 and b[i]<0) or (s<0 and b[i]>0)):
            continue
        if da.get(s-b[i],None):
            ans=min(ans,i+1+da.get(s-b[i])+1)
    print(ans)
        
    