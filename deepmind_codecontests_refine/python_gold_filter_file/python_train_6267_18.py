# ------------------- fast io --------------------
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
# ------------------- fast io --------------------
import math;import bisect
primes=[2]
for s in range(3, math.ceil(math.sqrt(10**5))+1):
    ind=bisect.bisect_left(primes,math.ceil(math.sqrt(s)));found=False
    for i in range(ind+1):
        if s%primes[i]==0:
            found=True;break
    if found==False:
        primes.append(s)
n=int(input());vals=list(map(int,input().split()))
choc=[]
for s in range(n):
    if vals[s]==1:
        choc.append(s)
if len(choc)==1:
    print(-1)
else:
    prime=[];ind2=min(bisect.bisect_left(primes,math.ceil(math.sqrt(len(choc)))),len(primes)-1)
    temp=len(choc)
    for s in range(ind2+1):
        if len(choc)%primes[s]==0:
            prime.append(primes[s])
            while temp%primes[s]==0:
                temp=temp//primes[s]
    if temp>1:
        prime.append(temp)
    mintime=10**20
    for p in prime:
        time=0
        for s in range(0,len(choc),p):
            if p==2:
                time+=choc[s+1]-choc[s]
            else:
                mid=choc[s+p//2]
                for i in range(s,s+p//2):
                    time+=mid-choc[i]
                for i in range(s+p//2+1,s+p):
                    time+=choc[i]-mid
        mintime=min(time,mintime)
    print(mintime)