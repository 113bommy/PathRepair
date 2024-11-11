n=int(input())
a=list(map(int,input().split()))
b=[0]*10009
c=[0]*10009
for i in range(n//2):
  b[a[i*2]]+=1
  c[a[i*2+1]]+=1
t=max(b)
r=max(c)
s=b.index(t)
p=c.index(r)
if s==p:
  b[s]=0
  k=max(b)
  c[p]=0
  j=max(c)
  f=max(k+r,t+j)
else:
  f=t+r
print(n-f)