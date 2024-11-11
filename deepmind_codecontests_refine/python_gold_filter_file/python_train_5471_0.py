ii=lambda:int(input())
kk=lambda:map(int, input().split())
ll=lambda:list(kk())

class Node:
	"""docstring for Node"""
	def __init__(self, parent, edge):
		self.children = [None, None]
		self.count = 0
		self.parent = parent
		self.fin = False
		self.edge= edge

	def next(self, pref):
		return (pref, self.children[pref]) if self.children[pref] else (pref^1, self.children[pref^1])
	def add(self, di):
		if not self.children[di]:
			self.children[di] = Node(self, di)
		return self.children[di]

	def end(self):
		self.count+=1
		self.fin=True

	def remC(self, i):
		self.children[i]=None
		if self.children[i^1] is None:
			self.parent.remC(self.edge)
			del self

	def remV(self):
		self.count-=1
		if self.count==0:
			self.parent.remC(self.edge)
			del self

def make(ite, node):
	for v in ite: node = node.add(v)
	node.end()
def remove(ite, node):
	for v in ite: node = node.children[v]
	node.remV()
def traverse(ite, node):
	res = 0
	for v in ite:
		i,node= node.next(v^1)
		res = 2*res + (i^v)
	return res

root = Node(None, -1)
make((0 for _ in range(31)), root)
for _ in range(ii()):
	s,i=input().split()
	i = int(i)
	ite = (min(1, (2**x)&i) for x in range(30, -1, -1))	
	if s == '+': make(ite, root)
	elif s == '-': remove(ite, root)
	else: print(traverse(ite,root))