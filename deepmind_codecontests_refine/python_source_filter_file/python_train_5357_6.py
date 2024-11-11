p,q,l,r=map(int,input().split())
a=[]
b=[]
for i in range(p):
    x=list(map(int,input().split()))
    a.append(x)
for i in range(q):
    x=list(map(int,input().split()))
    b.append(x)
mx=a[p-1][1]+1
c1=[0]*mx
c2=[0]*mx
j=0
k=0
for i in range(mx):
    if j < p:
        if i>a[j][1]:
            j+=1
    if k < q:
        if i>b[k][1]:
            k+=1
    if j<p:
        if i>=a[j][0] and i<=a[j][1]:
            c1[i]=1
    if k<q:
        if i>=b[k][0] and i<=b[k][1]:
            c2[i]=1
for i in range(l):
    c1.insert(0,0)
ans=0
for i in range(r-l+1):
    f=0
    for j in range(mx):
        if c1[j]+c2[j]==2:
            f=1
            break
    if f==1:
        ans+=1
    c2.insert(0, 0)
print(ans)