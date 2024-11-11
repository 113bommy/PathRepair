for _ in range(int(input())):
    n,r=map(int,input().split())
    if r>=n:
        print((r*(r-1))//2)
    else:
        print((n*(n+1))//2)