t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    ok=False
    for x in range(n):
        if not ok and a[x]%2==0:
            print(1)
            print(x)
            ok=True
        for y in range(n):
            if not ok and x!=y and (a[x]+a[y])%2==0:
                print(2)
                print(x+1,y+1)
                ok=True
                
    if not ok:
        print(-1)