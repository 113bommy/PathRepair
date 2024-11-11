n,m = map(int,input().split())
ans=True
a={}
m=0
for i in range(n):
    x,y=map(int,input().split())
    m=max(m,y)
    if x in a:
        a[x]=max(a[x],m)
    else:
        a[x]=m
k=list(a.keys())
k.sort()
for i in range(len(k)):
    if i==0:
        if k[i]==0:
            continue
        else:
            ans=False
            break
    else:
        if k[i]<=a[k[i-1]]:
            continue
        else:
            ans=False
            break
if ans:
    if m<=a[k[-1]]:
        print("YES")
    else:
        print("NO")
else:
    print("NO")
