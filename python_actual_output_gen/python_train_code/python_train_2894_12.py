n,x=map(int,input().split())
a=list(map(int,input().split()))
c=0
if a[0]>x:
    c+=a[0]-x
    a[0]=x
for i in range(1,n,2):
    if a[i]+a[i-1]>x:
        c+=a[i]+a[i-1]-x
        a[i]-=a[i]+a[i-1]-x
print(c)
