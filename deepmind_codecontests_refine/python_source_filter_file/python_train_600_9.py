
import sys
def input():
	return sys.stdin.readline().strip()


N, M = list(map(int, input().split()))

LRC = []
for _ in range(M):
	LRC.append(tuple(map(int, input().split())))

LRC.sort()


class seg_tree():
	def __init__(self, N):
		# N: 処理する区間の長さ
		self.N0 = 2 ** (N - 1).bit_length()
		self.INF = 2 ** 31 - 1 #単位限的なもの(最小値なので、非常に大きい値を置いておく)
		self.data = [self.INF] * (2 * self.N0)

	# a_k の値を x に更新
	def update(self, k, x):
		#値は0始まり
		k += self.N0 - 1
		self.data[k] = x
		while k >= 0:
			k = (k - 1) // 2
			self.data[k] = min(self.data[2 * k + 1], self.data[2 * k + 2])

	# 区間[l, r)の最小値
	def query(self, l, r):
		L = l + self.N0
		R = r + self.N0
		s = self.INF
		while L < R:
			if R & 1:
				R -= 1
				s = min(s, self.data[R - 1])

			if L & 1:
				s = min(s, self.data[L - 1])
				L += 1
			L >>= 1
			R >>= 1
		return s

dist = seg_tree(N)
dist.update(0, 0)

for i in range(M):
	L, R, C = LRC[i]
	L -= 1
	R -= 1
	dist_start = dist.query(L, N)
	target_dist = dist.query(R, N)
	if dist_start + C < target_dist:
		dist.update(R, dist_start + C)


ans = dist.query(N - 1, N)
if ans == dist.INF:
	print(-1)
else:
	print(ans)