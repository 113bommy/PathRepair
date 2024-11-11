#import modules here
import math,sys,os
#from itertools import permutations, combinations
# from collections import defaultdict,deque,OrderedDict,Counter
# import bisect as bi
#import heapq
from io import BytesIO, IOBase
mod=10**9+7

# region fastio
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

#input functions
def minp(): return map(int, sys.stdin.readline().rstrip().split())
def linp(): return list(map(int, sys.stdin.readline().rstrip().split()))
def inp(): return int(input())
def print_list(l):
    print(' '.join(map(str,l)))

# functions
# def BinarySearch(a,x): 
#     i=bi.bisect_left(a, x) 
#     if i != len(a) and a[i] == x: 
#         return i 
#     else: 
#         return -1
        
# def gcd(a,b):
#     return math.gcd(a,b)
    
# def is_prime(n):
#     """returns True if n is prime else False"""
#     if n < 5 or n & 1 == 0 or n % 3 == 0:
#         return 2 <= n <= 3
#     s = ((n - 1) & (1 - n)).bit_length() - 1
#     d = n >> s
#     for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
#         p = pow(a, d, n)
#         if p == 1 or p == n - 1 or a % n == 0:
#             continue
#         for _ in range(s):
#             p = (p * p) % n
#             if p == n - 1:
#                 break
#         else:
#             return False
#     return True
    
# def mulinverse(a):
#     return pow(a,mod-2,mod)

####################Let's Go Baby########################
n,k=minp()
a=[]
for i in range(n):
    a.append(linp())
a=sorted(a, key=lambda x: (-x[0],x[1]))
#print(a)
#print(a[k-1])
print(a.count(a[k-1]))