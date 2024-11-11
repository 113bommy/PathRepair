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
f=1
c=0
for i in v:
    if i%2!=0:
        f=0
        break
    else:
        c+=int(i/2)
if f==0:
    print(-1)
else:
    print(c)