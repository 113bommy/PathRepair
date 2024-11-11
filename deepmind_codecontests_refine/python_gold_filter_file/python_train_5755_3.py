for i in range(int(input())):
    n,k=list(map(int,input().split()))
    x=sorted(map(int,input().split()))
    input()
    a=[]
    j=0
    for i in range(n):
        while j<n and x[j]-x[i]<=k:
            j+=1
        a.append(j-i)
    c=a[:]
    a1=a[:]
    for i in range(1,n):
        a[i]=max(a[i],a[i-1])
    for i in range(n-2,-1,-1):
        a1[i]=max(a1[i],a1[i+1])
    j=n-1
    l=n-1
    z=0
    for i in range(n-1,-1,-1):
        while x[l]-x[i]>k:
            l-=1
        b=0
        if l!=n-1:
            b=a1[l+1]
        while j>=0 and x[i-1]-x[j]<=k:
            j-=1
        if j>=0:
            b=max(b,a[j])
        else:
            z=max(z,l+1)
        z=max(z,b+c[i])
    print(min(z,n))
