t=int(input())
while t>0:
    n,m=map(int,input().split())
    if m*2==n:
        print("YES")
    else:
        print("NO")
    t-=1