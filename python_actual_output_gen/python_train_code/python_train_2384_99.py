t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    x=n/m
    if n/m==2:
        print("YES")
    else:
        print("NO")
