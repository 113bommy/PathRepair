# Author : nitish420 --------------------------------------------------------------------
import os
import sys
from io import BytesIO, IOBase

def main():
	n,m=map(int,input().split())
	arr=[]
	for _ in range(n):
		arr.append(list(map(lambda x: int(x)-1,input().split())))
	ans=0

	def solvemin(x):
		# in this values are of type x m+x 2m+x ..... so on
		zz=0
		cnt=[0]*(n)
		for i in range(n):
			val=arr[i][x]-x
			if val%m==0 and val%m<n:
				cnt[(i-val//m+n)%n]+=1
		zz=float('inf')
		for i in range(n):
			zz=min(zz,n-cnt[i]+i)

		return zz


	for i in range(m):
		ans+=solvemin(i)
	print(ans)
	

# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
	newlines = 0

	def __init__(self, file):
		self._fd = file.fileno()
		self.buffer = BytesIO()
		self.writable = 'x' in file.mode or 'r' not in file.mode
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
			self.newlines = b.count(b'\n') + (not b)
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
		self.write = lambda s: self.buffer.write(s.encode('ascii'))
		self.read = lambda: self.buffer.read().decode('ascii')
		self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')


# endregion

if __name__ == '__main__':
	main()