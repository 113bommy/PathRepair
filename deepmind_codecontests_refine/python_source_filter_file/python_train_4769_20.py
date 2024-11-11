q=int(input())
query=[input() for _ in range(q)]
from bisect import bisect_left
ary=[-float('inf')]
for qq in query:
  if qq[0]=='1':
    _,a,_=map(int,qq.split())
    ary.append(a)
ary.sort()
ary.append(float('inf'))

class SegmentTree():
  def __init__(self,size,f=lambda x,y:x+y,default=0):
    self.size=pow(2,(size-1).bit_length())
    self.f=f
    self.default=default
    self.data=[default]*(self.size*2)
  def update(self,i,x):
    i+=self.size
    self.data[i]=x
    while i:
      i>>=1
      self.data[i]=self.f(self.data[i*2],self.data[i*2+1])
  # 区間[l,r)へのクエリ
  def query(self,l,r):
    l,r=l+self.size,r+self.size
    lret,rret=self.default,self.default
    while l<r:
      if l&1:
        lret=self.f(self.data[l],lret)
        l+=1
      if r&1:
        r-=1
        rret=self.f(self.data[r],rret)
      l>>=1
      r>>=1
    return self.f(lret,rret)
  def get(self,i):
    return self.data[self.size+i]
  def add(self,i,x):
    self.update(i,self.get(i)+x)

ml,mr=0,len(ary)+1
mv=0
st=SegmentTree(len(ary))
for qq in query:
  if qq[0]=='2':
    print(ary[ml],mv)
  else:
    _,a,b=map(int,qq.split())
    a=bisect_left(ary,a)
    st.add(0,-1)
    st.add(a,2)
    if ml<=a<mr:
      mv+=b
      ml,mr=a,a+1
    else:
      l,r=0,len(ary)+1
      # はじめて0以上になる場所を二分探索→ここがml
      while r-l>1:
        x=(r+l)//2
        if st.query(0,x)>=0:
          l,r=l,x
        else:
          l,r=x,r
      # はじめて1以上になる場所を二分探索→ここがmr
      mv+=b
      mv+=min(abs(ary[l]-ary[ml]),abs(ary[l]-ary[mr]))+abs(ary[l]-ary[a])
      ml=l
      l,r=0,len(ary)+1
      while r-l>1:
        x=(r+l)//2
        if st.query(0,x)>0:
          l,r=l,x
        else:
          l,r=x,r
      mr=l