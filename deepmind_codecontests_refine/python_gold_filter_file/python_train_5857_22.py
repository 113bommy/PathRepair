for _ in range(int(input())):
    n,r=map(int,input().split())
    q=min(n-1,r)
    ans=(q*(q+1)//2)
    print(ans+(r>=n))