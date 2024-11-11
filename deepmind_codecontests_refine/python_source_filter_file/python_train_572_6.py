a=list(map(int,input().split()))
d=[0]*(a[2]+1)
if a[0]<a[2]:
    d[a[0]]=a[0]
if len(d)<a[1] and len(d)<a[0]:
    print("No")
    exit()
for i in range(1,a[2]+1):
    if d[i]>0:
        if d[i]+a[0]<=a[2]:
            d[i+a[0]]=d[i]+a[0]

if a[1]<a[2]:
    d[a[1]]=a[1]
for i in range(1,a[2]+1):
    if d[i]>0:
        if d[i]+a[1]<=a[2]:
            d[i+a[1]]=d[i]+a[1]
print(("No","Yes")[d.count(a[2])])

