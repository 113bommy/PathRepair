n=int(input())
arr=list(map(int,input().split()))
d={}
for i in arr:
    if i!=0:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
v=list(d.values())
f=0
c=0
for i in v:
    if i>2:
        f=1
        break
    else:
        c+=int(i/2)
if f:
    print(-1)
else:
    print(c)