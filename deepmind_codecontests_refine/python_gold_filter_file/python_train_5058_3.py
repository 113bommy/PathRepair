n=int(input())
l1=[]
r1=[]
for i in range(n):
  l,r=list(map(int,input().split()))
  l1.append(l);r1.append(r)
lp=max(l1)
rp=min(r1)
m=int(input())
l2=[]
r2=[]
for i in range(m):
   l3,r3=list(map(int,input().split()))
   l2.append(l3);r2.append(r3)
x,y=max(l2),min(r2)
print(max(0,x-rp,lp-y))