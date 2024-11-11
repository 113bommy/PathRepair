n,*a=map(int,open(0).read().split())
a.sort()
tmp=(a[0]+a[1])/2
for i in range(2,n):
  tmp=(tmp+a[i])/2
print(int(tmp))