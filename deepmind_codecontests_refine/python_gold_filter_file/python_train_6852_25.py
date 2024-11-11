N = int(input())
A = [int(x) for x in input().split()]
total_medians = N*(N+1)//2
# n件のデータ
# (上側中央値 >= x) iff (a > x となる a が(n-1)//2以下)

def BIT_update(BIT,x,value):
  # 番号xにvalueを加える
  L = len(BIT)
  while x < L:
    BIT[x] += value
    bottom_bit = x & (-x)
    x += bottom_bit
  return

def BIT_sum(BIT,x):
  # 番号1～xの和を求める
  result = 0
  while x:
    result += BIT[x]
    bottom_bit = x & (-x)
    x -= bottom_bit
  return result

def test(x):
  # 「答はx以下である」
  # 「xより真に大きな区間中央値が(total_medians-1)//2個以下」
  B = [0]
  for a in A:
    B.append(B[-1] + (1 if a>x else -1))
  m = min(B)-1
  B = [x-m for x in B]

  BIT = [0]*(N+1)
  
  cnt = 0
  for R in range(1,N+1):
    BIT_update(BIT,B[R-1],1)
    cnt += BIT_sum(BIT,B[R]) # 右端がRとなる(L,R)対
  return cnt <= (total_medians-1)//2

AA = sorted(A)
left = -1 # 答はAA[left]より大きい
right = len(AA)-1 # 答はAA[right]以下である
while right - left > 1:
  mid = (left+right)//2
  if test(AA[mid]):
    right = mid
  else:
    left = mid
answer = AA[right]

print(answer)
