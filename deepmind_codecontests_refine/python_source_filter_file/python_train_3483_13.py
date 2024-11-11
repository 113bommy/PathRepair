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
##########################################################3
import threading
sys.setrecursionlimit(10**5+1)
threading.stack_size(10**8)
def flowers(n):
    global k,l,mod
    if n<k:
        return 1
    if l[n]!=0:
        return l[n]
    ans=0
    ans=(flowers(n-k)+flowers(n-1))%mod
    l[n]=ans
    return ans
def main():
    global k,l,mod
    l=[0]*100001
    l1=[0]*100001
    t,k=map(int,input().split())
    mod=10**9+7
    for i in range(k):
        l[i]=1
    flowers(100000)
    l1[0]=l[0]
    for i in range(1,100001):
        l1[i]=(l1[i-1]+l[i])%mod
    for i in range(t):
        a,b=map(int,input().split())
        print((l1[b]-l1[a-1]+mod)%mod)
t=threading.Thread(target=main)
t.start()
t.join()

    
    
        
        
    
