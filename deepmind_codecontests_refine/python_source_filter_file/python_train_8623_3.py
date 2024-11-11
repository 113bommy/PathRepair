import heapq
import sys
input=sys.stdin.readline

class SegmentTreeMin():
  def __init__(self,n,init):
    self.offset=2**((n-1).bit_length())
    self.tree=[init]*(2*self.offset)
    self.init=init
  def update(self,pos,val):
    pos+=self.offset
    self.tree[pos]=val
    while pos>1:
      pos=pos//2
      self.tree[pos]=min(self.tree[2*pos],self.tree[2*pos+1])
  def query(self,l,r):
    l+=self.offset
    r+=self.offset
    ret=self.init
    while l<=r:
      ret=min(ret,self.tree[r])
      r=(r-1)//2
      ret=min(ret,self.tree[l])
      l=(l+1)//2
    return ret

n=int(input())
arr=list(map(int,input().split()))
odds=SegmentTreeMin(n//2,10**18)
evens=SegmentTreeMin(n//2,10**18)
dic={}
for i in range(n):
  dic[arr[i]]=i
  if i%2==0:
    odds.update(i//2,arr[i])
  else:
    evens.update(i//2,arr[i])
q=[]
heapq.heappush(q,(odds.query(0,(n-1)//2),0,n-1))
ans=[]
while len(q)!=0:
  _,l,r=heapq.heappop(q)
  if l%2==0:
    a=odds.query(l//2,r//2)
    odds.update(dic[a]//2,10**18)
    b=evens.query(dic[a]//2,r//2)
    evens.update(dic[b]//2,10**18)
    ans.append(a)
    ans.append(b)
    tl=dic[a]
    tr=dic[b]
    if tl!=l:
      heapq.heappush(q,(odds.query(l,(tl-1)//2),l,tl-1))
    if tl+1<tr-1:
      heapq.heappush(q,(evens.query((tl+1)//2,(tr-1)//2),tl+1,tr-1))
    if tr!=r:
      heapq.heappush(q,(odds.query((tr+1)//2,r//2),tr+1,r))
  else:
    a=evens.query(l//2,r//2)
    evens.update(dic[a]//2,10**18)
    b=odds.query((dic[a]+1)//2,r//2)
    odds.update(dic[b]//2,10**18)
    ans.append(a)
    ans.append(b)
    tl=dic[a]
    tr=dic[b]
    if tl!=l:
      heapq.heappush(q,(evens.query(l,(tl-1)//2),l,tl-1))
    if tl+1<tr-1:
      heapq.heappush(q,(odds.query((tl+1)//2,(tr-1)//2),tl+1,tr-1))
    if tr!=r:
      heapq.heappush(q,(evens.query((tr+1)//2,r//2),tr+1,r))
print(*ans)