from __future__ import division, print_function

import os,sys
from io import BytesIO, IOBase

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

from bisect import bisect_left as lower_bound, bisect_right as upper_bound 
def so():  return int(input())
def st():  return input()
def mj():  return map(int,input().strip().split(" "))
def msj(): return map(str,input().strip().split(" "))
def le():  return list(map(int,input().split()))
def lebe():return list(map(int, input()))

def dmain():
    sys.setrecursionlimit(1000000)
    threading.stack_size(1024000)
    thread = threading.Thread(target=main)
    thread.start()
def joro(L):
    return(''.join(map(str, L)))


def decimalToBinary(n): return bin(n).replace("0b","")


def isprime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True
        
    
def read():
    sys.stdin  = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 
def tr(n):
    return n*(n+1)//2

    
def iu():
    import sys
    n,q=mj()
    L=le()
    
    vv=[0]*(n+1)
    for i in range(1,n+1):
        vv[i]=L[i-1]
    a=-(1e9)
    for i in range(max(1,n-4*q),n+1,1):
        for j in range(1+i,n+1,1):
            mo=q*(vv[i]|vv[j])
            id=i*j
            a=max(a,id-mo)
    print(a)

    
    
   
    
    
    
        
    
            
        
        
        
                
def main():
    for i in range(so()):
        iu()
    
    
            
                    
                
                    
                    
                    
                    
                    
                    
        
                
        
        
       
    
           
          
          
                
            
        
                
    
        
        
        
       
            
                
        




# region fastio
# template taken from https://github.com/cheran-senthil/PyRival/blob/master/templates/template.py

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

# endregion


if __name__ == "__main__":
    #read()
    main()
    #dmain()

# Comment Read()