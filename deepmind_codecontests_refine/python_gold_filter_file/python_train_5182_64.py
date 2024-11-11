n, k = map(int, input().split())
P = list(map(lambda x: int(x)-1, input().split()))
C = list(map(int, input().split()))
ans = -10**18
for i in range(n):  # 開始点を全通り
  x = i
  sc = []
  tot = 0
  while True:
    x = P[x]
    sc.append(C[x])
    tot += C[x]
    if x == i: break  # 開始点に戻ってきて循環に入った
  #print(i, sc, tot)
  l = len(sc)
  cum = 0
  for j in range(l):  # 何ステップ進むとよいか
    cum += sc[j]
    if j+1 > k: break  # k=1は最初の1周のみ
    val = cum  # 循環ループ考慮するスコア
    if tot > 0:
      cyc = (k-(j+1)) // l  # 残りステップで循環できる数
      val += tot * cyc
    ans = max(ans, val)
    #print(j, cum, cyc, val)
print(ans)