n,m=map(int,input().split())
l=list(map(int,input().split()))
s=sum(l)+n-1
if m in [s] :
    print("YES")
else :
    print("NO")
