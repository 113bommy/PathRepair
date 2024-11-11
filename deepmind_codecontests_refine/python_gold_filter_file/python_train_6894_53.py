t=int(input())
for q in range(0,t):
    n,m=map(int,input().split())
    if n%m==0:
        print("YES")
    else:
        print("NO")