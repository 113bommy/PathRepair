N = int(input())
A = list(map(int,input().split()))
A.reverse() #後ろから見る。

if A[0] != 2:
  print(-1)
  exit()
MIN = 2
MAX = 3
for i in range(1,N):
  nxt = A[i]
  if MAX < nxt:
    print(-1)
    exit() 
  #オッケーの最大値
  MAX = (MAX//nxt)*nxt #MAXは絶対前の数の倍数
  if MAX < MIN:
    print(-1)
    exit()
  #オッケーの最小値
  MIN = min(MAX,((MIN+nxt-1)//nxt)*nxt)

  print(MIN,MAX)
 
  #最小値は変化なし。
  MAX = MAX+(nxt-1)
  print(nxt,MIN,MAX)
print(MIN,MAX)
