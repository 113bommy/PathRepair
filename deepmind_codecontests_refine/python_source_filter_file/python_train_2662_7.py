#------------------------------what is this I don't know....just makes my mess faster--------------------------------------
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
 
#----------------------------------Real game starts here--------------------------------------
'''
 
 
___________________THIS IS AESTROIX CODE________________________
                       KARMANYA GUPTA
 
'''
#_______________________________________________________________#
import math
def fact(x):
	if x == 0:
		return 1
	else:
		return x * fact(x-1)
def lower_bound(li, num): #return 0 if all are greater or equal to
	answer = -1 
	start = 0
	end = len(li)-1

	while(start <= end):
		middle = (end+start)//2
		if li[middle] >= num:
			answer = middle
			end = middle - 1
		else:
			start = middle + 1
	return answer #index where x is not less than num
def upper_bound(li, num): #return n-1 if all are small or equal
	answer = -1
	start = 0
	end = len(li)-1

	while(start <= end):
		middle = (end+start)//2

		if li[middle] <= num:
			answer = middle
			start = middle + 1
		
		else:
			end = middle - 1
	return answer #index where x is not greater than num
def binary_search(lb, ub, val, cnt):
	mid = (lb + ub)//2
	if val < mid:
		ub = mid-1
		binary_search(lb, ub, val, cnt-1)
	elif val > mid:
		lb = mid + 1
		binary_search(lb, ub, val, cnt-1)
	else:
		print(cnt)
def abs(x):
	return x if x >=0 else -x
#_______________________________________________________________#



for t in range(1):
	n, a, b = list(map(int, input().split()))
	comp = input()
	comp = 'x'+comp

	if comp[a] == comp[b]:
		print(0)
	else:
		print(abs(a-b))




	











