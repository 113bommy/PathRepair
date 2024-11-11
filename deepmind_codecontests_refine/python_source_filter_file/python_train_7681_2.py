def segfunc_min(x,y):return min(x,y)
def segfunc_max(x,y):return max(x,y)
ide_ele_min=10**18
ide_ele_max=0
class segtree():
  def __init__(self,init_val,segfunc,ide_ele):
    n=len(init_val)
    self.segfunc=segfunc
    self.ide_ele=ide_ele
    self.num=1<<(n-1).bit_length()
    self.tree=[ide_ele]*2*self.num
    for i in range(n):
      self.tree[self.num+i]=init_val[i]
    for i in range(self.num-1,0,-1):
      self.tree[i]=self.segfunc(self.tree[2*i], self.tree[2*i+1])
  def update(self,k,x):
    k+=self.num
    self.tree[k]=x
    while k>1:
      self.tree[k>>1]=self.segfunc(self.tree[k],self.tree[k^1])
      k>>=1
  def query(self,l,r):
    res=self.ide_ele
    l+=self.num
    r+=self.num
    while l<r:
      if l&1:
        res=self.segfunc(res,self.tree[l])
        l+=1
      if r&1:
        res=self.segfunc(res,self.tree[r-1])
      l>>=1
      r>>=1
    return res
n,k=map(int,input().split())
*p,=map(int,input().split())
q=[1]*n
ans=n-k+1
cnt=1
c=0
for i in range(n-1):
  if p[i+1]>p[i]:cnt+=1
  else:cnt=1
  c+=cnt>=k
  if cnt>k:q[i-k]=0
if c>1:ans-=c-1
stn=segtree(p,segfunc_min,ide_ele_min)
stx=segtree(p,segfunc_max,ide_ele_max)
for i in range(n-k):
  if stn.query(i,i+k)==p[i] and stx.query(i+1,i+k+1)==p[i+k] and q[i]:ans-=1
print(ans)