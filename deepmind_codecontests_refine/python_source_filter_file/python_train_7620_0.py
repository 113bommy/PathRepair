import sys
import math
from collections import defaultdict,Counter,deque

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
	newlines = 0

	def __init__(self, file):
		self._fd = file.fileno()
		self.buffer = BytesIO()
		self.writable = "x" in file.mode or "r" not in file.mode
		self.write = self.buffer.write if self.writable else None

	def read(self):
		while True:
			b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
			if not b:
				break
			ptr = self.buffer.tell()
			self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
		self.newlines = 0
		return self.buffer.read()

	def readline(self):
		while self.newlines == 0:
			b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
			self.newlines = b.count(b"\n") + (not b)
			ptr = self.buffer.tell()
			self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
		self.newlines -= 1
		return self.buffer.readline()

	def flush(self):
		if self.writable:
			os.write(self._fd, self.buffer.getvalue())
			self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
	def __init__(self, file):
		self.buffer = FastIO(file)
		self.flush = self.buffer.flush
		self.writable = self.buffer.writable
		self.write = lambda s: self.buffer.write(s.encode("ascii"))
		self.read = lambda: self.buffer.read().decode("ascii")
		self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# mod=pow(10,9)+7
# t=int(input())
for i in range(1):
	n=int(input())
	a=list(map(int,input().split()))
	l=defaultdict(list)
	q=deque()
	for j in range(n):
		if j+a[j]<n:
			l[j+a[j]].append(j)
			if (a[j]&1)^(a[j+a[j]]&1):
				q.append(j)
		if j-a[j]>=0:
			l[j-a[j]].append(j)
			if (a[j]&1)^(a[j-a[j]]&1):
				q.append(j)

	# print(q)
	ans=[-1]*n
	lev=[-1]*(n+1)
	for j in q:
		lev[j]=1
	while q:
		s=q.popleft()
		ans[s-1]=lev[s]
		for j in l[s]:
			if lev[j]==-1:
				q.append(j)
				lev[j]=lev[s]+1
	print(*ans)
	# ans1=[10**9]*n
	# for j in range(n-1,-1,-1):
	# 	p=j
	# 	flag=a[p]&1
	# 	if p+a[p]<n:
	# 		p+=a[p]
	# 		if flag^(a[p]&1):
	# 			ans[j]=1
	# 		else:
	# 			ans[j]=1+ans[p]
	# print(ans)
	# for j in range(n):
	# 	p=j
	# 	flag=a[p]&1
	# 	if p-a[p]>=0:
	# 		p-=a[p]
	# 		if flag^(a[p]&1):
	# 			ans1[j]=1
	# 		else:
	# 			ans1[j]=1+ans1[p]
	# print(ans1)
	# for j in range(n):
	# 	cur=min(ans[j],ans1[j])
	# 	if j+a[j]<n:
	# 		cur=min(cur,1+ans1[j+a[j]])
	# 	if j-a[j]>=0:
	# 		cur=min(cur,1+ans[j-a[j]])
	# 	if cur>=10**9:
	# 		print(-1,end=' ')
	# 	else:
	# 		print(cur,end=' ')
