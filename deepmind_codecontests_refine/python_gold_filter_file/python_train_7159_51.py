import sys
input = sys.stdin.buffer.readline

#sys.setrecursionlimit(10**9)
#from functools import lru_cache

def RD(): return sys.stdin.read()
def II(): return int(input())
def MI(): return map(int,input().split())
def MF(): return map(float,input().split())
def LI(): return list(map(int,input().split()))
def LF(): return list(map(float,input().split()))
def TI(): return tuple(map(int,input().split()))
# rstrip().decode()


class BIT:
	def __init__(self, n):
		self.n = n
		self.data = [0]*(n+1)
		self.el = [0]*(n+1)
	def sum(self, i):
		s = 0
		while i > 0:
			s += self.data[i]
			i -= i & -i
		return s
	def add(self, i, x):
		# assert i > 0
		self.el[i] += x
		while i <= self.n:
			self.data[i] += x
			i += i & -i
	def get(self, i, j=None):
		if j is None:
			return self.el[i]
		return self.sum(j) - self.sum(i)


def main():
	n,q=MI()
	C=[0]+LI()

	lr=[]

	for i in range(q):
		l,r=MI()
		lr.append([l,r,i])
	lr.sort(key=lambda x:x[1])
	#print(lr)
	R=[-1]*(n+1)

	B=BIT(n)
	now=1
	ans=[-1]*(q)
	for l,r,i in lr:
		while now<=r:
			if R[C[now]]!=-1:
				B.add(R[C[now]],-1)
			R[C[now]]=now
			B.add(R[C[now]],1)
			now+=1
		#print(R)
		#print(B.el)
		ans[i]=B.get(l-1,r)
	print(*ans,sep="\n")



if __name__ == "__main__":
	main()
