n,m=[int(i) for i in input().split()]
a=m*[0]
b=m*[0]
for i in range(m):
    a[i],b[i]=[int(i) for i in input().split()]
for i in range(1-1,m):
    bish=b[0]
    k=0
    for j in range(1,m-i):
        if b[j]>bish:
            bish=b[j]
            k=j
    a[k],a[m-1-i]=a[m-1-i],a[k]
    b[k],b[m-1-i]=b[m-1-i],b[k]
a.reverse()
b.reverse()
i=0
h=0
r=0
while i<m:
    if h+a[i]<=n:
        r+=a[i]*b[i]
        h+=a[i]
        i+=1
    else:
        z=n-h
        r+=z*b[i]
        break
print(r)
