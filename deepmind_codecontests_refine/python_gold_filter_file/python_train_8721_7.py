n,m=map(int,input().split())
l=list(map(int,input().split()))
c=len([i for i in l if i >= sum(l)/(4*m)])
print("Yes" if c>=m else "No")