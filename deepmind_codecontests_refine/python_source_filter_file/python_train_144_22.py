s=[int(i) for i in input().split(" ")]
n=s[0]
c=s[1]
a=[int(i) for i in input().split(" ")]
k=-1
for i in range(n-1):
    if a[i]-a[i+1]>k:
        k=a[i]-a[i+1]
if k==-1:
    print(0)
else:
    print(k-c)