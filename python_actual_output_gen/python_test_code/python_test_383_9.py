n,m,a,b = map(int, input().split())
ans = 0
if m*a<=b:
    ans = n*a
    print(ans)
else:
    while n>0:
        ans += b
        n = n-m
    if n!=0:
        if n*a>b:
            ans+=b
        else:
            ans+=n*a
    print(ans)


