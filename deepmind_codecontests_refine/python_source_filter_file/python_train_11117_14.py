n,m=map(int,input().split())
a=[0]*(n+1)
b=[0]*(n+1)
for i in range(m):
  p,s=input().split()
  p=int(p)
  if a[p]==0:
      if s=="AC":
        a[p]=1
      else:
        b[p]+=1
for i in range(n+1):
    if a[i]==0:
        b[i]==0
print(sum(a),sum(b))