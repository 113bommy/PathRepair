n,t=map(int,input().split())
l=list(map(int,input().split()))
if sum(l)+(n-1) <=t:
    print("YES")
else:
    print("NO")