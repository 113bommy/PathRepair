n=100000
p=[0]*2+[1]*(n-1)
for i in range(2,n+1):
  if p[i]:
    for j in range(i*2,n+1,i):
      p[j]=0
for i in range(1,n+1)[::-1]:
  if p[i]:
    if p[(i+1)//2]:
      continue
    p[i]=0
p[2]=0
c=[0]*(n+1)
for i in range(1,n+1):
  c[i]=c[i-1]+p[i]
q=int(input())
for i in range(q):
  l,r=map(int,input().split())
  print(c[r]-c[l-1])