n,m=map(int,input().split())
a=sorted(list(map(int,input().split())),reverse=True)
print("Yes" if a[m-1]>=(sum(a)/(4*m)) else "No")