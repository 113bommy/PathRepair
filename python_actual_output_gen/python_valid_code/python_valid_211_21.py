n,l=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
r=max(a[0],l-a[n-1])*2
for i in range(n-1):
    r=max(r,a[i+1]-a[i])
print("%.10f"%r)