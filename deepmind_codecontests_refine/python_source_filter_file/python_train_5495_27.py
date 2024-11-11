k,n=map(int,input().split())
a=list(map(int,input().split()))
t=0
for i in range(1,n):
  t=max(t,a[i]-a[i-1])
k=max(t,k-a[n-1]+a[0])
print(k-t)
