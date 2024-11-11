import sys
readline = sys.stdin.readline

# dp[i] = 高さiのときの最大価値
# 順に見ていって、高さH[i]が来た時に、dp[i - 1]の最大値(美しさ)にA[i]を足したものをdp[i]に入れる
# セグメント木

# 求める値によって以下を書き換える
# DEF=結果に影響を与えない初期値(ex.最小値を求める場合INF)
# __choose__():結果の算出ロジック(ex.最小値を求める場合return min(a,b))
class SegmentTree:
  arr=None
  tree=None
  n=0
  # 結果に影響を与えないdefault value
  DEF=0
  def __init__(self,arr):
    self.arr=arr
    size=len(arr)
    # n階層目は2**(n-1)要素
    self.n=1
    while self.n<size:
      self.n*=2
    self.tree=[self.DEF]*(2*self.n-1)
    # 親=(n-1)//2
    # 子=2*n+1,2*n+2
    # 最下階層の要素を埋めていく
    for i in range(size):
      self.tree[i+self.n-1]=arr[i]
    for i in range(self.n-2,-1,-1):
      self.tree[i]=self.__choose__(self.tree[2*i+1],self.tree[2*i+2])
    
  # 区間からの代表値の選び方を定義する（最小値を選ぶ場合はminなど）
  def __choose__(self,a,b):
    return max(a,b)
  
  # 添字xをvalで更新する
  def update(self,x,val):
    x+=self.n-1
    
    self.tree[x]=val
    while x>0:
      x=(x-1)//2
      self.tree[x]=self.__choose__(self.tree[2*x+1],self.tree[2*x+2])
      
  # 対象区間[a,b)の値を求めるクエリ (bは含まないので注意)
  # k:自分がいるノードのindex
  # [l,r):検査する区間
  def get_val(self,a,b,k=0,l=0,r=-1):
    # 最初に呼び出されたときは対象区間が[0,N)
    if r<0:
      r=self.n
      
    # 要求区間と対象区間が交わらない
    if r<=a or b<=l:
      return self.DEF
    
    # 要求区間が対象区間を完全に満たす->対象区間を計算に使用する
    if a<=l and r<=b:
      return self.tree[k]
    
    # 要求区間が対象区間の一部を満たす->子を探索
    ll=self.get_val(a,b,2*k+1,l,(l+r)//2)
    rr=self.get_val(a,b,2*k+2,(l+r)//2,r)
    
    return self.__choose__(ll,rr)
    
  def show(self):
    print(self.tree)
    
N = int(readline())
H = list(map(int,readline().split()))
A = list(map(int,readline().split()))

dp = [0] * (N + 1)
ST = SegmentTree(dp)

for i in range(len(H)):
  h = H[i]
  a = A[i]
  # そこまでの最大値を求める
  maxval = ST.get_val(0,h)
  ST.update(h, maxval + a)

print(ST.get_val(0, N + 1))
