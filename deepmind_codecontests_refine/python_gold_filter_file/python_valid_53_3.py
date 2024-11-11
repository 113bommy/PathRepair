t=int(input())

for _ in range(t):
    n, k=map(int,input().split())
    a=list(map(int,input().split()))

    b=sorted(a)
    d={}
    for i in range(n):
        d[b[i]]=i

    ans=0
    for i in range(n):
        if i==n-1 or d[a[i]]+1!=d[a[i+1]]:
            ans+=1

    if ans<=k:
        print("Yes")
    else:
        print("No")
