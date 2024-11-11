#設定
import sys
input = sys.stdin.buffer.readline

#ライブラリインポート
from collections import defaultdict
INF = float("inf")

#入力受け取り
def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	H, W, N = getlist()
	L = []
	for i in range(N):
		x, y = getlist()
		L.append((x, y))
	L = sorted(L)
	damage = 0
	ans = INF
	xval = 0
	for i in range(N):
		x, y = L[i][0], L[i][1]
		if x >= y + 1 + damage:
			ans = x - 1
			break
		if x == y + damage and xval != x:
			damage += 1
		xval = x
	print(min(ans, H))


if __name__ == '__main__':
	main()