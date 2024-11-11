def solve(l,r):
    if l>r:
        return
    m=(l+r)//2
    a[m]=(l-r,m)
    solve(l,m-1)
    solve(m+1,r)
    
t=int(input())
for w in range(t):
    n=int(input())
    a=b=[0]*(n+1)
    solve(1,n)
    for i,j in enumerate(sorted(a[1:n+1]),start=1):
        b[j[1]]=i
    print(*b[1:n+1])