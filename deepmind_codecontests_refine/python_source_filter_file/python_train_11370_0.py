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

# sys.stdout=open("CP1/output.txt",'w')
# sys.stdin=open("CP1/input.txt",'r')

# mod=pow(10,9)+7
t=int(input())
for _ in range(t):
	r,c=map(int,input().split())
	cnt=0
	l=[]
	flag=0
	flag2=0
	h=[0,0]
	v=[0,0]
	for i in range(r):
		s=list(input())
		cur=1
		for j in range(c):
			if s[j]=='A':
				s[j]=1
				cnt+=1
				if j==0 or j==c-1:
					flag=1
					if j==0:
						v[0]+=1
					else:
						v[1]+=1
				elif i==0 or i==r-1:
					flag=1
					if i==0:
						h[0]+=1
					else:
						h[1]+=1
			else:
				s[j]=0
				cur=0
		if cur:
			flag2=1
		l.append(s)

	if cnt==0:
		print("MORTAL")
	elif cnt==r*c:
		print(0)
	elif flag==0:
		print(4)
	else:
		if max(h)==c or max(v)==r:
			print(1)
			flag=0
		if flag:
			if l[0][0] or l[0][c-1] or l[r-1][c-1] or l[r-1][0] or flag2:
				print(2)
			else:
				for j in range(1,c-1):
					for k in range(r):
						if l[k][j]==0:
							break
					else:
						print(2)
						flag2=1
						break
				if flag2==0:
					print(3)
