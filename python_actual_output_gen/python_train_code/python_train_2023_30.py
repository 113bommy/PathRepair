t=int(input())
for _ in range(t):
    n,r=map(int,input().split())
    if n<r:
        s=int(n*(n-1)//2+1)
    else:
        s=int(r*(r+1)//2)
    print(s)