"""
NTC here
"""
from sys import stdin, setrecursionlimit
setrecursionlimit(10**6)


import operator as op
from io import BytesIO, IOBase
import sys,os

# print("Case #{}: {} {}".format(i, n + m, n * m))

import threading
threading.stack_size(2 ** 27)
 
def iin(): return int(stdin.readline())
 
 
def lin(): return list(map(int, stdin.readline().split()))

# range = xrange
# input = raw_input

import math
ceil=math.ceil
log=math.log
gcd=math.gcd

def main():
    n=iin()
    a=list(input())
    l=a[:n//2]
    r=a[n//2:]
    ch1,ch2=l.count('?'),r.count('?')
    ch3,ch4=(ch1+1)//2, (ch2+1)//2
    cl,cr=0,0
    for i in l:
        if i!='?':cl+=int(i)
    for i in r:
        if i!='?':cr+=int(i)
    
    #l<r
    #print(cl,cr,ch1,ch2)
    if cl+ch3*9!=cr+ch4*9 :
        print('Monocarp')
    else:
        print('Bicarp')
     



#threading.Thread(target=main).start()



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

def Print(*args, **kwargs):
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
 
 

input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# endregion
main()