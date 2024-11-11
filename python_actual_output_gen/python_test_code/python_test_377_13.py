for _ in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    s=sorted(l)
    fe=s[0]
    ans=0
    for i in range(1,n):
        if s[i]<=k:
            ans=ans+(k-l[i])//fe
    print(ans)