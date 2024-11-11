import sys
import math
from collections import defaultdict,Counter

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP1/output.txt",'w')
# sys.stdin=open("CP1/input.txt",'r')
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


# sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
# input = lambda: sys.stdin.readline().rstrip("\r\n")


# mod=pow(10,9)+7
t=int(input())
for i in range(t):
	n,m=map(int,input().split())
	l=[]
	for j in range(n):
		s=list(input())
		l.append(s)
	ans=[]
	for j in range(n-1):
		if j&1 and j!=n-2:
			continue
		for k in range(m-1):
			if k&1 and k!=m-2:
				continue
			cur=[]
			if l[j][k]=='1':
				cur.extend([j+1,k+1])
			if l[j][k+1]=='1':
				cur.extend([j+1,k+2])
			if l[j+1][k]=='1':
				cur.extend([j+2,k+1])
			if l[j+1][k+1]=='1':
				cur.extend([j+2,k+2])
			if len(cur)==6:
				ans.append(cur)
			elif len(cur)==2:
				cur1=[]
				if l[j][k]=='1' or l[j+1][k]=='1':
					cur1.extend([j+1,k+1])
					cur1.extend([j+2,k+1])
					cur1.extend([j+2,k+2])
					ans.append(cur1)
					cur1=[]
					cur1.extend([j+1,k+1])
					cur1.extend([j+2,k+1])
					cur1.extend([j+1,k+2])
					ans.append(cur1)
					cur1=[]
					cur1.extend([j+2,k+2])
					cur1.extend([j+1,k+2])
					if l[j][k]=='1':
						cur1.extend([j+1,k+1])
					else:
						cur1.extend([j+2,k+1])
					ans.append(cur1)
				else:
					cur1.extend([j+1,k+1])
					cur1.extend([j+1,k+2])
					cur1.extend([j+2,k+2])
					ans.append(cur1)
					cur1=[]
					cur1.extend([j+2,k+1])
					cur1.extend([j+2,k+2])
					cur1.extend([j+1,k+2])
					ans.append(cur1)
					cur1=[]
					cur1.extend([j+2,k+1])
					cur1.extend([j+1,k+1])
					if l[j][k+1]=='1':
						cur1.extend([j+1,k+2])
					else:
						cur1.extend([j+2,k+2])
					ans.append(cur1)
			elif len(cur)==8:
				cur1=[]
				cur1.extend([j+2,k+2])
				cur1.extend([j+1,k+2])
				cur1.extend([j+2,k+1])
				ans.append(cur1)
				cur1=[]
				cur1.extend([j+1,k+1])
				cur1.extend([j+2,k+1])
				cur1.extend([j+2,k+2])
				ans.append(cur1)
				cur1=[]
				cur1.extend([j+1,k+1])
				cur1.extend([j+2,k+1])
				cur1.extend([j+1,k+2])
				ans.append(cur1)
				cur1=[]
				cur1.extend([j+2,k+2])
				cur1.extend([j+1,k+2])
				cur1.extend([j+1,k+1])
				ans.append(cur1)
			elif len(cur)==4:
				if l[j][k]=='1':
					if l[j][k+1]=='1':
						cur1=[]
						cur1.extend([j+1,k+1])
						cur1.extend([j+2,k+1])
						cur1.extend([j+2,k+2])
						ans.append(cur1)
						cur1=[]
						cur1.extend([j+2,k+1])
						cur1.extend([j+2,k+2])
						cur1.extend([j+1,k+2])
						ans.append(cur1)
					elif l[j+1][k]=='1':
						cur1=[]
						cur1.extend([j+1,k+1])
						cur1.extend([j+2,k+2])
						cur1.extend([j+1,k+2])
						ans.append(cur1)
						cur1=[]
						cur1.extend([j+2,k+1])
						cur1.extend([j+2,k+2])
						cur1.extend([j+1,k+2])
						ans.append(cur1)
					else:
						cur1=[]
						cur1.extend([j+1,k+1])
						cur1.extend([j+2,k+2])
						cur1.extend([j+1,k+2])
						ans.append(cur1)
						cur1=[]
						cur1.extend([j+2,k+1])
						cur1.extend([j+2,k+2])
						cur1.extend([j+1,k+2])
						ans.append(cur1)
				elif l[j+1][k+1]=='1':
					if l[j][k+1]=='1':
						cur1=[]
						cur1.extend([j+1,k+1])
						cur1.extend([j+2,k+1])
						cur1.extend([j+1,k+2])
						ans.append(cur1)
						cur1=[]
						cur1.extend([j+2,k+1])
						cur1.extend([j+2,k+2])
						cur1.extend([j+1,k+1])
						ans.append(cur1)
					else:
						cur1=[]
						cur1.extend([j+1,k+1])
						cur1.extend([j+2,k+1])
						cur1.extend([j+1,k+2])
						ans.append(cur1)
						cur1=[]
						cur1.extend([j+2,k+2])
						cur1.extend([j+1,k+2])
						cur1.extend([j+1,k+1])
						ans.append(cur1)
				else:
					cur1=[]
					cur1.extend([j+1,k+1])
					cur1.extend([j+2,k+2])
					cur1.extend([j+1,k+2])
					ans.append(cur1)
					cur1=[]
					cur1.extend([j+2,k+1])
					cur1.extend([j+2,k+2])
					cur1.extend([j+1,k+1])
					ans.append(cur1)


			l[j][k]='0'
			l[j][k+1]='0'
			l[j+1][k+1]='0'
			l[j+1][k]='0'

	print(len(ans))
	for i in ans:
		print(*i)