n,w=[int(x) for x in input().split()]
l=list(map(int, input().split()))
for i in range(n-1):
    l[i+1]+=l[i]

mn=min(l)
mx=max(l)
x=w+1
if mx>=0:
    x-=mx

if mn<=0:
    x+=mn

if x<=w or x>=0:
    print(x)
else:
    print(0)

