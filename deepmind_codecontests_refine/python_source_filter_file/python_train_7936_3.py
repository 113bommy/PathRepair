for T in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    used=[False]*(n+1)
    for i in range(1,n):
        a[i]+=a[i-1]
        if(a[i]<=n):
            used[a[i]]=1
    for i in range(n):
        for j in range(i-2,-1,-1):
            if(a[i]-a[j]>n):
                break
            used[a[i]-a[j]]=True
    res=used[a[0]]
    for i in range(1,n):
        res+=used[a[i]-a[i-1]]
    print(res)
    
