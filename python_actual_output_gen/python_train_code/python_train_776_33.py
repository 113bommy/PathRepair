n,m=map(int,input().split())
a=[int(x) for x in input().split()]
a.sort()
d=a[n-1]-a[0]
for i in range(1,m-n+1):
    D=a[i-n+1]-a[i]
    d=min(d,D)
print(d)    
