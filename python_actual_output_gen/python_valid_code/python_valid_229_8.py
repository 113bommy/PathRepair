n,m=[int(x) for x in input().split(' ')]
z=[int(x) for x in input().split(' ')]
z.sort()
a,b,ans=0,0,0
for i in range(n-1):
    if z[i]<=1:
        if z[i]==1:
            a=1
        continue
    if z[i]>1:
        if z[i]>a:
            ans+=z[i]-1
        else:
            ans+=a-1
    a+=1
    a=min(a,z[i])
if z[i]>a:
    ans+=a
else:
    ans+=z[i]-1
print(ans)