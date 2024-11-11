''' ===============================
    -- @uthor : Kaleab Asfaw
    -- Handle : kaleabasfaw2010
    -- Bio    : High-School Student
    ==============================='''

# Fast IO
import sys
import os
from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file): self._fd = file.fileno(); self.buffer = BytesIO(); self.writable = "x" in file.mode or "r" not in file.mode; self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b: break
            ptr = self.buffer.tell(); self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0; return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE)); self.newlines = b.count(b"\n") + (not b); ptr = self.buffer.tell(); self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1; return self.buffer.readline()
    def flush(self):
        if self.writable: os.write(self._fd, self.buffer.getvalue()); self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file): self.buffer = FastIO(file); self.flush = self.buffer.flush; self.writable = self.buffer.writable; self.write = lambda s: self.buffer.write(s.encode("ascii")); self.read = lambda: self.buffer.read().decode("ascii"); self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout); input = lambda: sys.stdin.readline().rstrip("\r\n")
# Others
# from math import floor, ceil, gcd
# from decimal import Decimal as d
mod = 10**9+7
def lcm(x, y): return (x * y) / (gcd(x, y))
def fact(x, mod=mod):
	ans = 1
	for i in range(1, x+1): ans = (ans * i) % mod
	return ans
def arr2D(n, m, default=0):
	lst = []
	for i in range(n): temp = [default] * m; lst.append(temp)
	return lst
def sortDictV(x): return {k: v for k, v in sorted(x.items(), key = lambda item : item[1])}

def solve(n, lst):
	cnt = {}
	for i in range(len(lst)):
		if cnt.get(lst[i]) == None:
			cnt[lst[i]] = [i+1, i]
		else:
			cnt[lst[i]] = [max(cnt[lst[i]][0], i-cnt[lst[i]][1]), i]

	for i in cnt:
		cnt[i] = [max(cnt[i][0], n-cnt[i][1]), cnt[i][1]]
	
	cnt = sortDictV(cnt)
	# print(cnt)
	
	ans = [float("inf")] * 6
	for i in cnt:
		ans[cnt[i][0]] = min(ans[cnt[i][0]-1], ans[cnt[i][0]], i)
	# print(ans)
	
	prev = float("inf")
	for i in ans[1:]:
		if min(i, prev) == float("inf"):
			print(-1, end=" ")
		else:
			print(min(i, prev), end=" ")
			prev = min(prev, i)
	print()


for _ in range(int(input())): # Multicase
	n = int(input())
	lst = list(map(int, input().split()))
	solve(n, lst)