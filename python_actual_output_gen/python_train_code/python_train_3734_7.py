n=int(input())
a=list(map(int,input().split()))
m=None
i=0
k1=0
k2=0
while i<n-1:
    k=abs(a[i]-a[i+1])
    if m==None or m>k:
        m=k
        k1=i
        k2=i+1
    i=i+1
k=abs(a[n-1]-a[0])
if m>k:
    m=k
    k1=n-1
    k2=0
print(k1,k2)