import os
import sys
from io import BytesIO, IOBase
 
 
def main():
    pass
 
 
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

 
 
t = int(input())
 
 
for p in range(t):
    n,k = map(int, input().split())
    lis = list(map(int, input().split()))
    posit = []
    neg = []
    lis.sort()
    for i in lis:
        if i>0:
            posit.append(i)
        else:
            neg.append(i)
    neg = [-i for i in neg]
    neg.reverse()
    ans = 0
    pos = 0
    lol = len(posit)
    
    if lol%k!=0:
        ans += posit[(lol%k)-1]*2 
        pos += lol%k
    
    while pos<lol:
        ans += posit[pos+k-1]*2
        pos += k
 
    pos = 0
    lol = len(neg)
    if lol%k!=0:
        ans += neg[(lol%k)-1]*2 if (lol%k)-1!=lol else neg[(lol%k)-1]
        pos += lol%k
    
    while pos<lol:
        ans += neg[pos+k-1]*2 if pos+k != lol else neg[pos+k-1]
        pos += k
    #########
    neg,posit = posit,neg
 
    ans2 = 0
    pos = 0
    if lol%k!=0:
        ans2 += posit[(lol%k)-1]*2
        pos += lol%k
    
    while pos<lol:
        ans2 += posit[pos+k-1]*2
        pos += k
 
    pos = 0
    lol = len(neg)
    if lol%k!=0:
        ans2 += neg[(lol%k)-1]*2 if (lol%k)-1!=lol else neg[(lol%k)-1]
        pos += lol%k
    
    while pos<lol:
        ans2 += neg[pos+k-1]*2 if pos+k != lol else neg[pos+k-1]
        pos += k
    print(min(ans,ans2))
    
