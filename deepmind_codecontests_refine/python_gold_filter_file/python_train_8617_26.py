n=int(input())
s=list(input())
q=int(input())

def ctoi(c):
  return ord(c)-97
class Bit:
  def __init__(self, n):
    self.size = n
    self.tree = [[0]*(n+1) for _ in range(26)]
  def query(self,a,i):
    r = 0
    while i > 0:
      r += self.tree[a][i]
      i -= i & -i
    return r
  def update(self,i,a,x):
    while i<=n:
      self.tree[a][i]+=x
      i+=i&(-i)
bi=Bit(n)
for i in range(n):
  bi.update(i+1,ctoi(s[i]),1)
  
for _ in range(q):
  a,b,c=input().split()
  a,b=int(a),int(b)
  if a==1 and s[b-1]!=c:
    bi.update(b,ctoi(s[b-1]),-1)
    bi.update(b,ctoi(c),1)
    s[b-1]=c
  elif a==2:
    c=int(c)
    right=[bi.query(i,c) for i in range(26)]
    left=[bi.query(i,b-1) for i in range(26)]
    ans=0
    for r,l in zip(right,left):
      if r-l>0:
        ans+=1
    print(ans)