a=list(map(int,input().split()))
a.sort()
print('YNeos'[a[2]!=a[0]+a[1]::2])