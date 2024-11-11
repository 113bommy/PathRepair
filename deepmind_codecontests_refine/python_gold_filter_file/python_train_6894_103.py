t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    x=n/m
    if x==x//1:
        print("YES")
    else:
        print("NO")
