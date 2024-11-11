import math

n,x=map(int,input().split(' '))
res=0
q=int(math.sqrt(n)+1)
for i in range(1,q):
    if(x%i==0):
        if(i<=n and x//i<=n):
            res+=2
        if(i==x//i):
            res-=1
print(res)