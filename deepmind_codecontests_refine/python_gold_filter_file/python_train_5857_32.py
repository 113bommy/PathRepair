for _ in range(int(input())):
    n,r=map(int,input().split())
    if(r>=n):
        s=int((n*(n-1))//2)
        print(s+1)
    else:
        s=int((r*(r+1))//2)
        print(s)