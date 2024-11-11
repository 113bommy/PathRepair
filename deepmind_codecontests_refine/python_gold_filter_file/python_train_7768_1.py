n,x=map(int,input().split())
l=list(map(int,input().split()))
if sum(l)+n-1==x:
    print("YES")
else:
    print("NO")