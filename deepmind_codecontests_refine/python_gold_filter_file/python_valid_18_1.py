import os
from io import BytesIO, IOBase
import sys
import math
def split(word):
   return [char for char in word]
def ncr(n, r, p):
	# initialize numerator
	# and denominator
	num = den = 1
	for i in range(r):
		num = (num * (n - i)) % p
		den = (den * (i + 1)) % p
	return (num * pow(den,p - 2, p)) % p   
def main():
      for i in range(int(input())):
         n,k=map(int,input().split())
         h=[0]*2*n
         a=[]
         b=[]
         for j in range(k):
            x,y=map(int,input().split())
            a.append(x-1)
            b.append(y-1)
            if a[j]>b[j]:
               t=a[j]
               a[j]=b[j]
               b[j]=t
            h[x-1]=1
            h[y-1]=1
         h1=0
         for j in range(k):
            c=0
            for l in range(j+1,k):
               if a[j]<b[l] and a[j]>a[l]:
                  if b[j]>b[l] or b[j]<a[l]:
                     c=c+1
               elif a[j]>b[l] or a[j]<a[l]:
                  if b[j]<b[l] and b[j]>a[l]:
                     c=c+1
            h1=h1+c      
            fi=0
            se=0
            for l in range(a[j]+1,b[j]):
               if h[l]==0:
                  fi=fi+1
            for l in range(a[j]):
               if h[l]==0:
                  se=se+1
            for l in range(b[j]+1,2*n):
               if h[l]==0:
                  se=se+1
            if fi>se:
               h1=h1+se
            else:
               h1=h1+fi
         print(h1+((n-k)*(n-k-1))//2)      
         
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
 
if __name__ == "__main__":
    main()  