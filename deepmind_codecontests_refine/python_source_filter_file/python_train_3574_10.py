import math
n,x=map(int,input().split())
a=list(map(int,input().split()))
new=0
if(a.count(x)==0):
    a.append(x)
    new+=1
a.sort()
index=0
dest=(n+1)//2
best=1000
val=0
for i in range(n):
    if(a[i]==x):
        d=abs(dest-(i+1))
        if(d<best):
            best=d
            val=i+1
n1=n
if(val<=(n+1)//2):
    while(val!=(n1+1)//2):
        val+=1
        n1+=1
    print(n1-n+new)
else:
    while(val!=(n1+1)//2):
        n1+=1
    print(n1-n+new)



