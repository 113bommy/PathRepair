# EDPC Q - Flowers
# 重み付きのLISと言って良いような問題
# これは、LISのdpを少し改造すれば解ける

# import numpy as np


## test data
# 4
# 3 1 4 2
# 10 20 30 40
## ans=60

# import bisect

class SegTree:
	def __init__(self,size,func,init_val,undef):
		self.specSize = size
		self.datSize = 1
		self.compareFunc = func		# suppose to min or max
		self.INIT_VAL = init_val	# 0 etc
		self.UNDEFINED_VAL = undef	# 1e18 -1e18 etc
		while self.datSize < size: self.datSize *= 2

		# the tree is implemented by sequencial list
		self.datTree = [self.INIT_VAL for _ in range(2*self.datSize+1)]
		# self.datTree = np.full(2*self.datSize+1,self.INIT_VAL,int)

	def update(self, i, val ):
		i -= 1	# 1-orderで指定され、内部では0-Order想定?
		i += (self.datSize - 1)
		# print("upd",i,val)
		self.datTree[i] = val
		while 0 < i:
			i = (i-1) >> 1	# (i-1)//2
			self.datTree[i] = self.compareFunc( self.datTree[i*2+1], self.datTree[i*2+2] )
			# print("upd",i,self.datTree[i])

	def query(self,a,b):
		return self.query_2(a,b,0,0,self.datSize)

	def query_(self,a,b,i,l,r):
		""" get minimun/maximum value of range[a,b)
		all 1-indexed
		i is the root vertex of search 
		l,r is range of the root vertex
		"""
		if r <= a or b <= l:
			# (a,b) and (l,r) is not intersected
			return self.UNDEFINED_VAL

		if a <= l and r <= b:
			# i is index required
			return self.datTree[i]
		else:
			# search children
			m = (l+r) >> 1 #(l+r) // 2
			# vl = self.query_(a, b, i*2 + 1, l, m )
			# vr = self.query_(a, b, i*2 + 2, m, r )
			vl = self.query_(a, b, (i << 1) + 1, l, m )
			vr = self.query_(a, b, (i << 1) + 2, m, r )
			return self.compareFunc(vl,vr)

	def query_2(self,a,b,i,l,r):
		""" get minimun/maximum value of range[a,b)
		all 1-indexed
		i is the root vertex of search 
		l,r is range of the root vertex
		"""
		ret = self.UNDEFINED_VAL

		a += self.datSize
		b += self.datSize
		while a < b:
			if b & 1:
				b -= 1
				ret = self.compareFunc(ret, self.datTree[b-1])

			if a & 1:
				ret = self.compareFunc(ret, self.datTree[a-1])
				a += 1

			a >>= 1; b >>= 1

		return ret
		# if r <= a or b <= l:
		# 	# (a,b) and (l,r) is not intersected
		# 	return self.UNDEFINED_VAL

		# if a <= l and r <= b:
		# 	# i is index required
		# 	return self.datTree[i]
		# else:
		# 	# search children
		# 	m = (l+r) >> 1 #(l+r) // 2
		# 	# vl = self.query_(a, b, i*2 + 1, l, m )
		# 	# vr = self.query_(a, b, i*2 + 2, m, r )
		# 	vl = self.query_(a, b, (i << 1) + 1, l, m )
		# 	vr = self.query_(a, b, (i << 1) + 2, m, r )
		# 	return self.compareFunc(vl,vr)


def LongestIncreaseSeaquence(H,A):
	# === Coordinate compression ===
	# unique and sort asc
	N = len(H)
	# sortedA = sorted(list(set(A)))
	lis = 0

	# === Range Maximum Query ===
	# ここでは、各要素iに、最後の値がiの時のLISを登録
	tree = SegTree(N,max,0,-1e18)
	for n in range(N):

		# i=bisect.bisect_left(sortedA,A[n])

		maxValOfCurrentRange = tree.query(0,H[n])
		# valOfNext = tree.query(H[n],H[n]+1)

		# # i+=1

		# if valOfNext < maxValOfCurrentRange + A[n]:
		# print( H[n], maxValOfCurrentRange + A[n] )
		# tree.debugPrint()
		tree.update( H[n], maxValOfCurrentRange + A[n] )

	lis = tree.query(0,N+1)
	return lis


def main():
	N = int(input())
	# 高さは、N以下で全部違うらしい
	H = list(map(int, input().split()))
	A = list(map(int, input().split()))
	# A = [ int(input()) for _ in range(N)]
	print(LongestIncreaseSeaquence(H,A))



if __name__ == "__main__":
	main()
