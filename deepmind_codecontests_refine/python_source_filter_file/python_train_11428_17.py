n,x,m=map(int,input().split())
l=[0 for i in range(m)]
ans=0
y=[]
i=1
flag=0
ys=n
while i<n:
    if flag==0:
        ans+=x
    l[x]+=1
    x=x*x%m
    i+=1
    if l[x]==2 and flag==0:
        flag=1
        ys=i
    if flag:
        if l[x]==3:
            break
        y.append(x)
if len(y):
    p,pp=divmod(n-ys,len(y))
    print(ans+p*sum(y)+sum(y[:pp+1]))
    #print(ans,p*sum(y),sum(y[:pp+1]))
else:
    print(ans)