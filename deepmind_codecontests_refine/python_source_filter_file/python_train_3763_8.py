def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

n = int(input())
p = 0
a = list(map(int,input().split()))
b,l = list(map(int,input().split())),0
from collections import defaultdict
c = defaultdict(int)
for i in range(n):
    if a[i]==0:
        if b[i]==0:
            p=p+1
    else:
        while True:
            k = gcd(a[i],b[i])
            a[i]=a[i]//k
            b[i]=b[i]//k
            if k==1 or k==-1:
                break
            c[(a[i],b[i])]+=1
l = 0
for i in c:
    if c[i]>l:
        l=c[i]
print(l+p)
