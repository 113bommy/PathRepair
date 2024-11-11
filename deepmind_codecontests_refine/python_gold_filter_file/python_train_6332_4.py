class unionFind():
	def __init__(self,n):
		self.tree=[-1]*n
	def find(self,x):
		if self.tree[x]<0:
			return x
		else:
			self.tree[x]=self.find(self.tree[x])
			return self.tree[x]
	def union(self,x,y):
		xr=self.find(x)
		yr=self.find(y)
		if xr!=yr:
			if self.tree[xr]<self.tree[yr]:
				self.tree[yr]=xr
			elif self.tree[xr]>self.tree[yr]:
				self.tree[xr]=yr
			else:
				self.tree[xr]-=1
				self.tree[yr]=xr
			return True
		
		return False
def main():
	ans=0
	n,m=map(int,input().split())
	a=unionFind(n)
	li=[x-1 for x in list(map(int,input().split()))]
	for _ in range(m):
		x,y=map(int,input().split())
		a.union(x-1,y-1)
	for x in range(n):
		ans += a.find(x)==a.find(li[x])
	return ans
print(main())