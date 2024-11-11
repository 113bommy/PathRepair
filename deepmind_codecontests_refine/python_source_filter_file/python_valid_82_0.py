from __future__ import division, print_function
import math
import sys
import os
from io import BytesIO, IOBase
#from collections import deque, Counter, OrderedDict, defaultdict
#import heapq
#ceil,floor,log,sqrt,factorial,pow,pi,gcd
#import bisect
#from bisect import bisect_left,bisect_right

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


def print(*args, **kwargs):
	"""Prints the values to a stream, or to sys.stdout by default."""
	sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
	at_start = True
	for x in args:
		if not at_start:
			file.write(sep)
		file.write(str(x))
		at_start = False
	file.write(kwargs.pop("end", "\n"))
	if kwargs.pop("flush", False):
		file.flush()


if sys.version_info[0] < 3:
	sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
	sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")

def inp():
    return(int(input()))
def inps():
    return input().strip()
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input().strip()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().split()))
def mdn(v):
	if v==0:
		return 0
	if v%2:
		return 1
	return 2

def bs(lf,r,v):
    s,e=lf,r
    while(s<=e):
        m=(s+e)//2
        val=l[m-1]-l[lf-1]-l[r]+l[m]
        if val==0:
            return m
        if (v<0 and val<0 )or (v>0 and val>0):
            e=m-1
        else:
            s=m+1
    return s



for _ in range(inp()):
    n,q=invr()
    s=insr()
    d={'+':1,'-':-1}
    l=[0]
    for i in range(n):
        if i%2:
            l.append(l[-1]-d[s[i]])
        else:
            l.append(l[-1]+d[s[i]])
    # print(l)
    for i in range(q):
        lf,rt=invr()
        v=mdn(l[rt]-l[lf-1])
        # print(v,'here')
        if v==0:
            print(0)
        elif v==1:
            print(1)
            print(bs(lf,rt,v))
        else:
            print(2)
            if (l[rt]-l[lf])%2!=0:
                print(lf,bs(lf+1,rt,l[rt]-l[lf]))
            else:
                print(bs(lf+1,rt,l[rt-1]-l[lf-1]),rt)