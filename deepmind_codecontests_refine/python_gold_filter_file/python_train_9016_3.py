n, k, m=map(int,input().split())
a=list(map(int,input().split()))
c=[0]*m
for i in range(n):
    x=a[i]%m
    c[x]=c[x]+1
f=0 
i=0
s=''

for i in range (m):
    if c[i]>=k:
        f+=1
        x=i
if f==0:
    print('No')
else:
    f=0
    i=0
    print('Yes')
    while f<k:
        if a[i]%m==x:
            s+=str(a[i])+' '
            f+=1
        i+=1
    print(s)