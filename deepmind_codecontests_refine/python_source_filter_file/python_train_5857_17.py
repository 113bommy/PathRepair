for _ in range(int(input())):
    n,r=map(int,input().split())
    q=min(n-1,r)
    ans=((q+1)//2*q)
    print(ans+(r>=n))