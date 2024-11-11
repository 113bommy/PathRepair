n,l=map(int,input().split())
a=sorted(list(map(int,input().split())))
d=max(a[0],l-a[n-1])
for i in range(1,n-1):
    d=max((a[i]-a[i-1])/2,d)
print(d)