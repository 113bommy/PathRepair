t=int(input())
for _ in range(t):
    n,m=list(map(int,input().split()))
    a=[]
    for i in range(n):
        a.append(list(map(int,input().split())))
    ans,m1,c,z=0,101,0,0
    for i in range(n):
        for j in range(m):
            ans=ans+abs(a[i][j])
            if a[i][j]==0:
                z=1
            if a[i][j]<0:
                c=c+1
            if abs(a[i][j])<m1:
                m1=abs(a[i][j])
    if c%2==1:
        if z==0:
            ans=ans-2*abs(m1)
    print(ans)