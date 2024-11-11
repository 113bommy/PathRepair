n=int(input())
a=[-1]
a.extend(list(map(int,input().split())))
i=1
while i<=n-i+1:
    if i%2==0:
        a[i],a[n-i+1]=a[n-i+1],a[i]
    i+=1
for i in range(1,n+1):
    print(a[i],end=' ')
