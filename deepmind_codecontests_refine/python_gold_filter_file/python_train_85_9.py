n,m=map(int,input().split())
student=[list(map(int,input().split())) for i in range(n)]
point=[list(map(int,input().split())) for i in range(m)]

for a,b in student:
  length=10**10
  pn=0
  for j in range(m):
    c,d=point[j]
    if abs(a-c)+abs(b-d)<length:
      length=abs(a-c)+abs(b-d)
      pn=1+j
  print(pn)