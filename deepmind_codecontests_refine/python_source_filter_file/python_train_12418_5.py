for _ in range(int(input())):
    n,k=[int(i) for i in input().split()]
    lx=[int(i) for i in input().split()]
    l=0
    r=n*k-1
    ans=0
    if(n%2==0):
        x=n//2
    else: x=n//2+1
    while(l<r):
        r-=(n-x+1)
        l+=x-1
        ans+=lx[r+1]
    print(ans)