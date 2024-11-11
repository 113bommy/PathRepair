def chk(m):
    k=min(g,m%(g+b))
    if m//(g+b) + k >=r:
        return True
    return False
for _ in range(int(input())):
    n,g,b=map(int,input().split())
    mi=0
    ma=10**18
    ans=10**18
    r=-(-n//2)
    while mi<ma:
        m=(mi+ma)//2
        if chk(m):
            ma=m
            ans=m
        else:
            mi=m+1
    print(max(ans,n))
        