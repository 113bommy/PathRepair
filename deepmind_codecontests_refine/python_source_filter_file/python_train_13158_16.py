n,k=map(int,input().split())
x=list(map(int,input().split()))
y=[]
s=sum(x[:k])
y.append(s)
for i in range(k,n):
  s+=x[i]
  s-=x[i-k]
  y.append(s)
u=y[0]
v=y[k]
ans=u+v
l=0
r=k
a,b=-1,-1
for i in range(k+1,len(y)):
  v=y[i]
  r=i
  if u<y[i-k]:
    l=i-k
    u=y[i-k]
  if ans<u+v:
    a=l+1
    b=r+1
    ans=u+v
print(a,b)