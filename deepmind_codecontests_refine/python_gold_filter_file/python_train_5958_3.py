t = int(input())
for _ in range(t):
    n,g,b = map(int, input().split())
    low=n//2
    lowcycle=low//b
    amari=low%b

    maxlow = (g+b)*lowcycle+g+amari
    if maxlow>=n:
        print(n)
    else:
        ans=(g+b)*(lowcycle+1)
        ans+=(n-maxlow)//g*(g+b)+(n-maxlow)%g
        if not (n-maxlow)%g:
            ans-=b
        print(ans)
    
