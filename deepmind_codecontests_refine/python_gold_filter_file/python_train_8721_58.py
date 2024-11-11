n,m = map(int,input().split())
a = sorted(list(map(int,input().split())),reverse=1)
print("Yes") if a[m-1] >= sum(a)/(4*m) else print("No")