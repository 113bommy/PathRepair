for _ in range(int(input())):
    n,r=map(int,input().split())
    m=min(n,r)
    ans=m*(m+1)//2
    if n <=r:
        ans-=(n-1)
    print(ans)