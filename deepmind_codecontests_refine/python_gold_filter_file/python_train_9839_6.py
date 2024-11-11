tc=int(input())
for _ in range(tc):
    n=int(input())
    res=n*(n+1)//2
    for i in range(30):
        if 2**i<=n:res-=2**(i+1)
    print(res)