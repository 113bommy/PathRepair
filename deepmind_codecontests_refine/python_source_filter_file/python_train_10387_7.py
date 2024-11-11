def segfunc(x,y):return max(x,y)
ide_ele=0
class segtree():
  def __init__(self,init_val,segfunc=segfunc,ide_ele=ide_ele):
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
    r+=self.num+1
    while l<r:
      if l&1:
        res=self.segfunc(res,self.tree[l])
        l+=1
      if r&1:
        res=self.segfunc(res,self.tree[r-1])
      l>>=1
      r>>=1
    return res
def isok(mid,key):
  return st.query(x-1,mid-1)>=key
def b_search(x,key):
  ng=x-1
  ok=n+1
  while abs(ng-ok)>1:
    mid=(ng+ok)//2
    if isok(mid,key):ok=mid
    else:ng=mid
  return ok
n,q=map(int,input().split())
a=list(map(int,input().split()))
st=segtree(a)
ans=[]
for _ in range(q):
  c,x,y=map(int,input().split())
  if c==1:st.update(x-1,y)
  elif c==2:ans+=[st.query(x-1,y)]
  else:ans+=[b_search(x,y)]
print(*ans,sep='\n')
