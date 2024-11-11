n,m=map(int,input().split())
a=list(map(int,input().split()))
s=a[0]-1
for i in range(m-1):
    if a[i]<=a[i+1]:
        s=s+a[i+1]-a[i]
    else:
        s=s+n-a[i]+n-a[i+1]
print(s)
