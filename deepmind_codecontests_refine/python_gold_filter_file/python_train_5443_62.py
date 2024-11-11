t=int(input())
for _ in range(t):
    l,r=map(int,input().split())
    if(l+l>r):
        print("YES")
    else:
        print("NO")
