n,m=input().split()
n=int(n)
m=int(m)

a=[]
for i in range(n):
    x=input().split()
    x=[int(p) for p in x]
    a.append(x)


if n<=m:
    ans=''
    step=0
    for i in range(n):
        t=500
        for j in range(m):
            t=min(t,a[i][j])
        ans+=('row'+' '+str(i+1)+'\n')*t
        step+=t
        for j in range(m):
            a[i][j]-=t

    can=True
    for j in range(m):
        t=a[0][j]
        for i in range(n):
            if a[i][j]!=t:
                can=False
        step+=t
        ans+=('col'+' '+str(j+1)+'\n')*t

    if can:
        print(step)
        print(ans)
    else:
        print(-1)
else:
    ans=''
    step=0
    for j in range(m):
        t=500
        for i in range(n):
            t=min(t,a[i][j])
        ans+=('col'+' '+str(j+1)+'\n')*t
        step+=t
        for i in range(n):
            a[i][j]-=t

    can=True
    for i in range(n):
        t=a[i][0]
        for i in range(m):
            if a[i][j]!=t:
                can=False
        step+=t
        ans+=('row'+' '+str(i+1)+'\n')*t

    if can:
        print(step)
        print(ans)
    else:
        print(-1)
