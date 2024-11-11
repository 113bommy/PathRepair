for _ in range(int(input())):
    l,r = map(int,input().split())
    ans = 0
    while l!=0 or r!=0:
        ans+=r-l
        r//=10
        l//=10
    print(ans)