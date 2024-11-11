import math
a,b=map(int,input().split())
g=math.gcd(a,b)
#print(g)
l1=[]
for i in range(1,int(math.sqrt(g))+1):
    if g%i==0:
        l1.append(i)
        l1.append(g//i)
#print(l1)
n=int(input())
for i in range(n):
    l,r=map(int,input().split())
    res=-1
    for j in range(len(l1)):
        if l1[j]>=l and l1[j]<=r:
            res=max(res,l1[j])
    print(res)
