k,n=map(int,input().split())
a=list(map(int,input().split()))
m=0
for i in range(n-1):
    m=max(m,a[i+1]-a[i])
m=max(m,20-a[n-1]+a[0])
print(k-m)