def chk(m):
    k=min(g,m%(g+b))
    if (m//(g+b))*g + k >=r:
        return True
    return False
for _ in range(int(input())):
    n,g,b=map(int,input().split())
    mi=0
    ma=10**20
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
        