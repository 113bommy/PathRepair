import sys; input = sys.stdin.buffer.readline
sys.setrecursionlimit(10**7)
from collections import defaultdict
con = 10 ** 9 + 7; INF = float("inf")

def getlist():
	return list(map(int, input().split()))

class SegmentTree(object):
	#N:処理する区間の長さ
	def __init__(self, N):
		self.N = N
		self.N0 = 2 ** (N - 1).bit_length()
		self.initVal = 0
		self.data = [self.initVal] * (2 * self.N0)

	# 区間クエリの種類
	def calc(self, a, b):
		return a + b

	# k番目の値にxを加算
	def add(self, k, x):
		k += self.N0 - 1
		self.data[k] += x
		while k > 0:
			k = (k - 1) // 2
			self.data[k] = self.calc(self.data[2 * k + 1], self.data[2 * k + 2])

	#区間[l, r]の演算値
	def query(self, l, r):
		L = l + self.N0; R = r + self.N0 + 1
		m = self.initVal
		while L < R:
			if R & 1:
				R -= 1
				m = self.calc(m, self.data[R - 1])
			if L & 1:
				m = self.calc(m, self.data[L - 1])
				L += 1
			L >>= 1; R >>= 1

		return m

#処理内容
def main():
	N, K = getlist()
	A = []
	for i in range(N):
		a = int(input())
		A.append(a)

	# K引く
	for i in range(N):
		A[i] -= K
	
	# 累積和
	B = [0]
	for i in range(N):
		B.append(B[-1] + A[i])

	# 座圧
	C = list(set(B))
	C.sort()
	D = defaultdict(int)
	for i in range(len(C)):
		D[C[i]] = i

	# 座標変換
	for i in range(N + 1):
		B[i] = D[B[i]]

	# セグ木
	ans = 0
	Seg = SegmentTree(N + 1)
	for i in range(N + 1):
		b = B[i]
		val = Seg.query(0, b)
		ans += val
		Seg.add(b, 1)

	print(ans)


if __name__ == '__main__':
	main()