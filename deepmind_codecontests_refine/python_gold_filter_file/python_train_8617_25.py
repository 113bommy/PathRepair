n=int(input())
s=[*input()]
q=int(input())
# BIT
B={chr(97+i):[0]*(n+1) for i in range(26)}
def bsum(c,i):
  s=0
  while i:
    s+=B[c][i]
    i-=i&-i
  return s
def badd(c,i,x):
  while i<=n:
    B[c][i]+=x
    i+=i&-i
for i,c in enumerate(s):
  badd(c,i+1,1)
for _ in range(q):
  x,y,z=input().split()
  y=int(y)-1
  if x=='1':
    badd(s[y],y+1,-1)
    s[y]=z
    badd(z,y+1,1)
  else:
    print(sum(bsum(c,int(z))-bsum(c,y)>0 for c in B))