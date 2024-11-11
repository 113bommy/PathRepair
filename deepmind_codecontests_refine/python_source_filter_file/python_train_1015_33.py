class SegTree:
	"""
	1-indexed
	"""
	def __init__(self,size,func,init_val,undef):
		self.specSize = size
		self.datSize = 1
		self.compareFunc = func		# suppose to min or max
		self.INIT_VAL = init_val	# 0 etc
		self.UNDEFINED_VAL = undef	# 1e18 -1e18 etc
		# num:size以上の最小の2のべき乗
		self.datSize = 2**size.bit_length()

		# the tree is implemented by sequencial list
		# (1-indexed, 0 is not use.)
		self.datTree = [self.INIT_VAL for _ in range(2*self.datSize+1)]

	def update(self, i, val ):
		"""
		i: index(1-ordered)
		"""
		# i -= 1	# 1-orderで指定され、内部では0-Order想定?
		# i += (self.datSize - 1)
		i += self.datSize
		self.datTree[i] = val
		while 1 < i:
			i >>= 1
			self.datTree[i] = self.compareFunc( self.datTree[i<<1|0], self.datTree[i<<1|1] )

	def query(self,a,b):
		return self.query_(a,b,1,0,self.datSize)

	def query_(self,a,b,i,l,r):
		""" get minimun/maximum value of range[a,b)
		all 1-indexed
		i is the root vertex of search 
		l,r is range of the root vertex(not use)
		"""
		ret = self.UNDEFINED_VAL

		a += self.datSize
		b += self.datSize
		while a < b:
			if b & 1:
				b -= 1
				ret = self.compareFunc(ret, self.datTree[b])

			if a & 1:
				ret = self.compareFunc(ret, self.datTree[a])
				a += 1

			a >>= 1; b >>= 1

		return ret

	def printTree(self):
		print(self.datTree)


def LongestSeaquence(A,K):
	N = len(A)
	lis = 0

	# === Range Maximum Query ===
	MAX_A = max(A)
	tree = SegTree(MAX_A+1,max,0,-1e18)
	# tree.update( 0, 1 )

	for n in range(N):
		x = A[n]
		l = max(1,x-K)
		r = min(MAX_A,x+K)
		tmp = tree.query(l,r+1)+1
		tree.update( x, tmp )
		lis = max(lis, tmp)

	return lis

def main():
	N,K = map(int,input().split())
	A = [ int(input()) for _ in range(N)]

	print(LongestSeaquence(A,K))



if __name__ == "__main__":
	main()