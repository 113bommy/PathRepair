class BIT:
	"0-indexed apparently"
	
	def __init__(self, n):
		self.n = n
		self.data = [0] * (n+1)
		
	def point_add(self, index, value):
		index += 1
		while index <= self.n:
			self.data[index] += value
			index += index & -index
		
	def folded(self, r):
		"[0, r)"
		ret = 0
		while r > 0:
			ret += self.data[r]
			r -= r & -r
		return ret
		
	def bisect_left(self, value):
		index = 0
		k = 1 << ((self.n + 1).bit_length() - 1)
		while k > 0:
			if index + k <= self.n and self.data[index + k] < value:
				value -= self.data[index + k]
				index += k
			k >>= 1
		return index + 1
		
N = int(input())
As = list(map(int, input().split()))

A_inv = [0] * N
for i, A in enumerate(As):
	A_inv[A-1] = i
	
bit = BIT(N + 2)
bit.point_add(0, 1)
bit.point_add(N+1, 1)
ans = 0
for A, index in enumerate(A_inv):
	A += 1
	index += 1
	v = bit.folded(index)
	ans += A * (bit.bisect_left(v+1) - index - 1) * (index - bit.bisect_left(v) + 1)
	#print(A, ans)
	bit.point_add(index, 1)
	
print(ans)