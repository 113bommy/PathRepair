n,m=map(int,input().split())
a=sorted(list(map(int,input().split())),reverse=1)
print("Yes" if 4*m*a[m-1]>=sum(a) else "No")