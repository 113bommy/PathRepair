n,*a=map(int,open(0).read().split())
ans=1
vec=0
for i in range(n-1):
    now=a[i+1]-a[i]
    if vec*now<0:
        ans+=1
        vec=0
    elif vec==0:
        vec=now
print(ans)