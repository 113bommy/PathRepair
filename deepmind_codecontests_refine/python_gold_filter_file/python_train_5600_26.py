class BinaryIndexedTree():
  def __init__(self,n):self.bit=[0]*n
  def add(self,i,x):
    i+=1
    while i<=len(self.bit):
      self.bit[i-1]+=x
      i+=i&-i
  def sum_1(self,i):
    a=0
    i+=1
    while i:
      a+=self.bit[i-1]
      i-=i&-i
    return a
  def sum(self,i,j):
    a=self.sum_1(j-1)
    if i!=0:a-=self.sum_1(i-1)
    return a
def tentousu(a):
  bit=BinaryIndexedTree(n)
  b=[0]*n
  for i in range(n):
    b[a[i]]=i
  ans=0
  for i in range(n):
    j=b[i]+bit.sum(b[i]+1,n)
    ans+=j-i
    bit.add(b[i],1)
  return ans
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
for i in range(1,n,2):a[i],b[i]=b[i],a[i]
ans=inf=float('inf')
for i in range(2**n):
  s=bin(i)[2:].zfill(n)
  if s.count("0")!=n//2:continue
  ac=[]
  bc=[]
  for j in range(n):
    if s[j]=="1":ac.append((a[j],j))
    else:bc.append((b[j],j))
  ac.sort()
  bc.sort()
  x=[]
  for j in range(n):
    if j%2:x.append(bc[j//2])
    else:x.append(ac[j//2])
  f=False
  for j in range(1,n):
    if x[j-1][0]>x[j][0]:f=True
  if f:continue
  m=[]
  for j in range(n):m.append(x[j][1])
  ans=min(ans,tentousu(m))
if ans==inf:ans=-1
print(ans)