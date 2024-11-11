import bisect as bi
n,x=map(int,input().split())
l=[]
h=[]
ans=0
for i in range(n):
    a,b=map(int,input().split())
    if a>b:
        l.append(b)
        h.append(a)
    else:
        l.append(a)
        h.append(b)
l.sort()
h.sort()
if l[n-1]>h[0]:
    print(-1)
else:
    m=bi.bisect(l,x)
    o=bi.bisect(h,x)
    if m!=n:
        ans+=l[n-1]-x
    if o!=0:
        ans+=x-h[0]
print(ans)