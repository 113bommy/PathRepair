class SegmentTreeMax():
  def __init__(self,n,init):
    self.offset=2**((n-1).bit_length())
    self.tree=[init]*(2*self.offset)
    self.init=init
  def update(self,pos,val):
    pos+=self.offset
    self.tree[pos]=val
    while pos>1:
      pos=pos//2
      self.tree[pos]=max(self.tree[2*pos],self.tree[2*pos+1])
  def query(self,l,r):
    l+=self.offset
    r+=self.offset
    ret=self.init
    while l<=r:
      ret=max(ret,self.tree[r])
      r=(r-1)//2
      ret=max(ret,self.tree[l])
      l=(l+1)//2
    return ret

mod=998244353
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
arr=sorted(arr,key=lambda x:x[0])
st=SegmentTreeMax(n,0)
ranges=[]
for i in range(n):
  x=arr[i][0]+arr[i][1]
  l=-1
  r=n
  while r-l!=1:
    mid=(l+r)//2
    if arr[mid][0]>=x:
      r=mid
    else:
      l=mid
  ranges.append(r-1)
  st.update(i,r-1)
for i in range(n-1,-1,-1):
  ranges[i]=st.query(i,ranges[i])
  st.update(i,ranges[i])
dp=[0]*(n+1)
dp[-1]=1
for i in range(n-1,-1,-1):
  j=ranges[i]+1
  dp[i]=dp[i+1]+dp[j]
  dp[i]%=mod
print(dp[0])