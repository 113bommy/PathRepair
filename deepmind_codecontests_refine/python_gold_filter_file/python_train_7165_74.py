n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
p=0
for i in range(n):
    if a[i]<b[i]:
        p+=(b[i]-a[i])//2
    elif b[i]<a[i]:
        p-=(a[i]-b[i])
if p>=0:
    print('Yes')
else:
    print('No')