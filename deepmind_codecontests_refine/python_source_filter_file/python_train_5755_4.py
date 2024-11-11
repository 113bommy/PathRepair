from bisect import bisect,bisect_left 
for _ in range(int(input())):
    n,k=map(int,input().split())
    x=list(map(int,input().split()))
    y=input()
    x.sort()
    a=[]
    b=[]
    i=0
    while i<n:
        b.append(bisect(x,x[i]+k)-i)
        a.append(i-bisect_left(x,x[i]-k)+1)
        i+=1
    b.reverse()
    for i in range(1,n):
        a[i]=max(a[i],a[i-1])
        b[i]=max(b[i],b[i-1])
    b.reverse()
    m=1
    for i in range(1,n-1):
        m=max(a[i]+b[i+1],m)
    print(m)