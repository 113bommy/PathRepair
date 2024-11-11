#CA3SAR KA JAADOOO
from sys import stdin,stdout,setrecursionlimit
from io import BytesIO, IOBase
# from math import gcd,floor,sqrt,ceil
# from collections import Counter,deque
# from itertools import accumulate as acc,permutations as perm
# from bisect import bisect_left as bl,bisect_right as br,bisect as bis
 
setrecursionlimit(10000)
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
        self.BUFSIZE = 8192
 
    def read(self):
        while True:
            a = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            if not a:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(a), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            a = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            self.newlines = a.count(b"\n") + (not a)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(a), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
stdin, stdout = IOWrapper(stdin), IOWrapper(stdout)
input = lambda: stdin.readline().rstrip("\r\n")
 
# inf = float('inf')
# ninf = float('-inf')
# abc = 'abcdefghijklmnopqrstuvwxyz'
inp = lambda: int(input())
st = lambda: input().strip()
jn = lambda x,l: x.join(map(str,l))
int_arr = lambda : list(map(int,input().strip().split()))
str_arr = lambda :list(map(str,input().split()))
get_str = lambda : map(str,input().strip().split())
get_int = lambda: map(int,input().strip().split())
get_float = lambda : map(float,input().strip().split())
 
mod = 10**9 + 7


for _ in range(inp()):
    n=inp()
    a=int_arr()
    c=0
    for i in a:
        if i==1:
            c+=1
    if c==0:
        for i in range(n+1):
            print(i+1,end=' ')
    elif a[0]==1:
        print(n+1,end=' ')
        for i in range(1,n+1):
            print(i,end=' ')
    else:
        x=0
        for i in range(n-1):
            if a[i]==0 and a[i+1]==1:
                x=i
                break
        for i in range(n):
            print(i+1,end=' ')
            if i==x:
                print(n+1,end=' ')
            
        
    print('')
        

    

