for _ in range(int(input())):
    c,s=list(map(int,input().split()))
    r=s%c
    q=s//c
    if c>s:
        print(s**2)
        continue
    if r==0:
        print(c*(q**2))
    else:
        ans=r*((q+1)**2)+(c-r)*(q**2)
        print(ans)
