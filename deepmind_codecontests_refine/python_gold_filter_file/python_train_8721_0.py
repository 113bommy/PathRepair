n,m=map(int,input().split())
a=list(map(int,input().split()))
c=len([i for i in a if i>=sum(a)/(4*m)])
print("Yes" if c>=m else "No")