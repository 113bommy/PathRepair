class binaryindexedtree():
  def __init__(self,n):
    self.n=n
    self.tree=[0]*n
  def add(self,a,w):
    x=a
    while x<=self.n:
      self.tree[x-1]+=w
      x+=x&(-x)
  def sums(self,a):
    x=a
    S=0
    while x!=0:
      S+=self.tree[x-1]
      x-=x&(-x)
    return S
n,q=map(int,input().split())
a=list(map(int,input().split()))
bit=binaryindexedtree(n)
for i,x in enumerate(a,1):
  bit.add(i,x)
ans=[]
for _ in range(q):
  x,y,z=map(int,input().split())
  if x:ans+=[bit.sums(z)-bit.sums(y)]
  else:bit.add(y,z)
print(*ans,sep='\n')