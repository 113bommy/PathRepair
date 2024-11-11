from heapq import heappop, heappush
INF = 10**30

class Rmin():
	def __init__(self, size):
		#the number of nodes is 2n-1
		self.n = 1
		while self.n < size:
			self.n *= 2
		self.node = [INF] * (2*self.n-1)

	def Access(self, x):
		return self.node[x+self.n-1]

	def Update(self, x, val):
		x += self.n-1
		self.node[x] = val
		while x > 0:
			x = (x-1)//2
			self.node[x] = min(self.node[2*x+1], self.node[2*x+2])
		return

	#[l, r)
	def Get(self, l, r):
		L, R = l+self.n, r+self.n
		s = INF
		while L < R:
			if R & 1:
				R -= 1
				s = min(s, self.node[R-1])			
			if L & 1:
				s = min(s, self.node[L-1])
				L += 1
			L >>= 1
			R >>= 1
		return s

n = int(input())
a = list(map(int, input().split()))

even, odd = Rmin(n), Rmin(n)
for i in range(n):
	if i%2 == 0:
		even.Update(i, a[i]*(10**7) + i)
	else:
		odd.Update(i, a[i]*(10**7) + i)

d = dict()

def search(l, r):
	if l%2 == 0:
		p = even.Get(l, r+1)
		q = odd.Get(p%(10**7)+1, r+1)
	else:
		p = odd.Get(l, r+1)
		q = even.Get(p%(10**7)+1, r+1)
	return p, q

x, y = search(0, n-1)
d[x%(10**7)] = (y, 0, n-1)
que = [x]
ans = []

while que:
	x = heappop(que)
	y, l, r = d[x%(10**7)]
	ans += [x//(10**7), y//(10**7)]

	if l != x%(10**7):
		p, q = search(l, x%(10**7)-1)
		d[p%(10**7)] = (q, l, x%(10**7)-1)
		heappush(que, p)

	if r != y%(10**7):
		p, q = search(y%(10**7)+1, r)
		d[p%(10**7)] = (q, y%(10**7)+1, r)
		heappush(que, p)

	if x%(10**7)+1 != y%(10**7):
		p, q = search(x%(10**7)+1, y%(10**7)-1)
		d[p%(10**7)] = (q, x%(10**7)+1, y%(10**7)-1)
		heappush(que, p)

print(*ans)