from collections import deque
# リストの両端の要素に対する編集が必要
# 同一方向に進むときは移動回数が増えないためリストのの先頭に挿入
# この仕組みを実装するためdequeを読み込み

H, W, K = map(int, input().split())
# HとWとKの値それぞれを取得

x1, y1, x2, y2 = map(int, input().split())
x1 -= 1
y1 -= 1
x2 -= 1
y2 -= 1
# リストの先頭要素は0番目として数えられる
# 座標のそれぞれの値から1を引いて取得

grid = [input() for _ in range(H)]
# グリッド部分をH行にわたって取得

INF = float('inf')
path = [[[(INF, INF)] * 4 for _ in range(W)] for _ in range(H)]
# 無限大の浮動小数点を管理

D = [(-1, 0), (0, 1), (1, 0), (0, -1)]
# 進行方向を座標で管理

q = deque()
for d in range(4):
	path[x1][y1][d] = (1, 0)
	# スタート地点を(1, 0)に設定
	q.append((x1, y1, d, 1, 0))
	# (x, y, 進行方向, 移動回数, 進行済マス数)を要素に追加

while q:
	x, y, d, c, k = q.popleft()
	#要素の削除
	
	# nx, ny: 次の座標
	# nd: 次の進行方向
	# nc: 次の移動回数
	# nk: 次の進行済マス数
	
	for nd in range(4):
		if nd == d:
			dx, dy = D[nd]
			nk = 1 if k == K else k + 1
			nc = c + 1 if k == K else c
		else:
			dx, dy = 0, 0
			nk = 0
			nc = c + 1
		nx = x + dx; ny = y + dy
		if 0 <= nx < H and 0 <= ny < W and grid[nx][ny] == '.' and path[nx][ny][nd] > (nc, nk):
			path[nx][ny][nd] = (nc), (nk)
			if nc == c:
				q.appendleft((nx, ny, nd, nc, nk))
			else:
				q.append((nx, ny, nd, nc, nk))
				
# コストの算出
ans = INF
for d in range(4):
	ans = min(ans, path[x2][y2][d][0])
ans = -1 if ans == INF else ans

print(ans)