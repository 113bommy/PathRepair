def func(x):
    global a
    y=0
    for i in range(x):
        y+=a[i][1]
    return y
n,s=map(int,input().split())
a=[]
for i in range(n):
    x,y,k=map(int,input().split())
    a.append([x*x+y*y,k])
if func(n)+s<10**6:
    print(-1)
    exit(0)
a.sort()
l=0
r=n-1
while l+1<r:
    m=(l+r)//2
    if s+func(m)>=10**6:
        r=m
    else:
        l=m
print(a[l][0]**0.5)