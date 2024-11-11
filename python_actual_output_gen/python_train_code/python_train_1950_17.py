a = list(map(int,input().split()))
a.sort()
print((a[0]%2==1)*(a[1]%2==1)*(a[2]%2==1)*a[1]*a[2])