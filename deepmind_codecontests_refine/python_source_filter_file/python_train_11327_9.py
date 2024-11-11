n,m=map(int,input().split())
l=list(map(int,input().split()))
d=dict()
for i in range(m):
  a,b=map(int,input().split())
  if b in d:
    d[b]+=a
  else:
    d[b]=a
x=sorted(d.keys())[::-1]
now=0
for x in d:
  now+=d[x]
  l+=[x]*min(n,d[x])
  if now>n:
    break
print(sum(sorted(l)[::-1][:n]))