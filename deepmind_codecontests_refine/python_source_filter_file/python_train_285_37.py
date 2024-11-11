import sys; input = sys.stdin.buffer.readline
sys.setrecursionlimit(10**7)
from collections import defaultdict
con = 10 ** 9 + 7; INF = float("inf")
def getlist():
	return list(map(int, input().split()))

class SegmentTree(object):
	#N:処理する区間の長さ
	def __init__(self, N):
		self.N0 = 2 ** (N - 1).bit_length()
		self.data = [INF] * (2 * self.N0)

	#k番目の値をxに更新
	def update(self, k, x):
		k += self.N0 - 1
		self.data[k] = x
		while k > 0:
			k = (k - 1) // 2
			self.data[k] = min(self.data[2 * k + 1], self.data[2 * k + 2])

	#区間[l, r]の最小値
	def query(self, l, r):
		L = l + self.N0; R = r + self.N0 + 1
		m = INF
		while L < R:
			if R & 1:
				R -= 1
				m = min(m, self.data[R - 1])
			if L & 1:
				m = min(m, self.data[L - 1])
				L += 1
			L >>= 1; R >>= 1

		return m

class SegmentTreeMAX(object):
	#N:処理する区間の長さ
	def __init__(self, N):
		self.N0 = 2 ** (N - 1).bit_length()
		self.data = [-INF] * (2 * self.N0)

	#k番目の値をxに更新
	def update(self, k, x):
		k += self.N0 - 1
		self.data[k] = x
		while k > 0:
			k = (k - 1) // 2
			self.data[k] = max(self.data[2 * k + 1], self.data[2 * k + 2])

	#区間[l, r]の最小値
	def query(self, l, r):
		L = l + self.N0; R = r + self.N0 + 1
		m = -INF
		while L < R:
			if R & 1:
				R -= 1
				m = max(m, self.data[R - 1])
			if L & 1:
				m = max(m, self.data[L - 1])
				L += 1
			L >>= 1; R >>= 1

		return m


#処理内容
def main():
	T = int(input())
	for _ in range(T):
		N = int(input())
		Seg = SegmentTree(N)
		SegMAX = SegmentTreeMAX(N)
		#セグ木をindexで初期化
		for i in range(N):
			Seg.update(i, i)
			SegMAX.update(i, i)

		ans = 0
		Lis = []
		for i in range(N):
			K, L, R = getlist()
			ans += R
			dif = L - R
			Lis.append([abs(dif), dif, K - 1])

		Lis.sort()
		for i in range(N):
			ab, diff, ind = Lis[-1 - i]
			# 絶対にK番目以内になる場合
			if diff >= 0:
				if ind >= N - 1:
					ans += diff
				else:
					segInd = SegMAX.query(0, ind)
					if segInd == INF:
						pass
					else:
						ans += diff
						SegMAX.update(segInd, -INF)
			else:
				if ind >= N - 1:
					ans += diff
				# K番目に入るかの判定
				else:
					segInd = Seg.query(ind + 1, N - 1)
					if segInd == -INF:
						ans += diff
					else:
						SegMAX.update(segInd, -INF)

		print(ans)


if __name__ == '__main__':
	main()