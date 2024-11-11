n=int(input())
a=list(map(int,input().split()))
d=1
mx=[]
for i in range(n+1):
  d-=a[i]
  mx.append(d)
  d*=2

mx.append(1)
f=True
d=0
c=0
for i in range(n,-1,-1):
  d+=a[i]
  c+=d
  t=(d+1)//2
  if t>mx[i-1]:
    f=False
    break
  d=min(d,mx[i-1])
print(c if f else -1)