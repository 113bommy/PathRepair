n=int(input())
f=[0 for x in range(0,367)]
m=[0 for x in range(0,367)]
for i in range(0,n):
    [g,r,l]=input().split()
    if g=='F':
        for x in range(int(r),int(l)+1):
            f[x]+=1
    else:
        for x in range(int(r),int(l)+1):
            m[x]+=1
c=1
for i in range(0,367):
    c=max(c,2*min(m[i],f[i]))
print(c)
