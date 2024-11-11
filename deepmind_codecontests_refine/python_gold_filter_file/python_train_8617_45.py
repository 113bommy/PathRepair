import sys
input=sys.stdin.buffer.readline
n=int(input())+1
data=[0]*n*2
def update(i,x):
  i+=n
  data[i]=x
  i//=2
  while i:
    data[i]=data[i*2]|data[i*2+1]
    i//=2
def query(l,r):
  l+=n
  r+=n
  s=0
  while l<r:
    if l&1:
      s|=data[l]
      l+=1
    if r&1:
      r-=1
      s|=data[r]
    l//=2
    r//=2
  return sum(map(int,bin(s)[2:]))
for i,c in enumerate(input()[:-1]):
  update(i,2**(c-97))
for _ in range(int(input())):
  q,a,b=input().split()
  if q[0]>49:print(query(int(a)-1,int(b)))
  else:update(int(a)-1,2**(b[0]-97))