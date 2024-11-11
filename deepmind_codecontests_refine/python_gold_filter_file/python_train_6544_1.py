import sys
input = sys.stdin.buffer.readline

def main():
	
	# SegmentTree Class
	class SegmentTree:
		
		# 初期化
		def __init__(self, size, default):
			self.size = 2**(size-1).bit_length()
			self.default = default
			self.seg = [default]*(2*self.size-1)

		# function(max, min, plus, minus, etc...)
		def segfunc(self,x,y):
			return max(x,y)

		# update
		def update(self,k,x):
			k += self.size-1
			self.seg[k] = x
			while k:
				k = (k-1)//2
				self.seg[k] = self.segfunc(self.seg[2*k+1],self.seg[2*k+2])

		# query([p,q)のsegfunc)
		def query(self,p,q):
			if q <= p:
				return self.default
			p += self.size-1;q += self.size-2
			ret = self.default
			while q-p > 1:
				if p&1 == 0:
					ret = self.segfunc(ret,self.seg[p])
				if q&1 == 1:
					ret = self.segfunc(ret,self.seg[q])
					q -= 1
				p = p//2
				q = (q-1)//2
			ret = self.segfunc(self.segfunc(ret,self.seg[p]),self.seg[q])
			return ret

		# seg確認用
		def seg_print(self):
			print(self.seg)
		
	N = int(input())
	a = list(map(int,input().split()))
	ans=[i+1 for i in range(N)]
	left_seg = SegmentTree(N, 0)
	for i, num in enumerate(a):
	    ans[num-1] *= i + 1 - left_seg.query(0,num)
	    left_seg.update(num-1, i+1)
	right_seg = SegmentTree(N, 0)
	for i, num in enumerate(a[::-1]):
	    ans[num-1] *= i + 1 - right_seg.query(0,num)
	    right_seg.update(num-1, i+1)
	
	print(sum(ans))

if __name__ == "__main__":
	main()
