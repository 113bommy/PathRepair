mod=10**9+7
import sys 
sys.setrecursionlimit(10**6) 
from sys import stdin, stdout
import bisect
from bisect import bisect_left as bl              #c++ lowerbound bl(array,element)
from bisect import bisect_right as br             #c++ upperbound
import itertools
import collections
import math
import heapq
import random
def modinv(n,p):
    return pow(n,p-2,p)
def ncr(n,r,p):                        #for using this uncomment the lines calculating fact and ifact
    t=((fact[n])*((ifact[r]*ifact[n-r])%p))%p
    return t
def cin():
    return map(int,sin().split())
def ain():                           #takes array as input
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())
def GCD(x,y):
    while(y):
        x, y = y, x % y
    return x
"""*******************************************************"""
 
def main():
    t=inin()
    for _ in range(t):
        n=inin()
        j,k,l=cin()
        u=j
        v=k
        w=l
        s=sin()
        jj=kk=ll=0
        for i in s:
            if(i=="S"):
                jj+=1
            elif(i=="P"):
                ll+=1
            else:
                kk+=1
        j=min(jj,j)
        k=min(kk,k)
        l=min(ll,l)
        x=j+k+l
        if(x>math.ceil(n/2)):
            print("YES")
            d=""
            for i in s:
                if(i=="S" and j>0):
                    u-=1
                    j-=1
                    d+="R"
                elif(i=="P" and l>0):
                    w-=1
                    l-=1
                    d+="S"
                elif(i=="R" and k>0):
                    v-=1
                    k-=1
                    d+="P"
                else:
                    d+="-"
            for i in d:
                if(i!="-"):
                    print(i,end="")
                else:
                    if(u>0):
                        print("R",end="")
                        u-=1
                    else:
                        if(v>0):
                            print("P",end="")
                            v-=1
                        else:
                            print("S",end="")
                            w-=1
            print()
        else:
            print("NO")
        
                        
######## Python 2 and 3 footer by Pajenegod and c1729
 
py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
 
import os, sys
from io import IOBase, BytesIO
 
BUFSIZE = 8192
class FastIO(BytesIO):
    newlines = 0
 
    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None
 
    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s
 
    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()
 
    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s:self.buffer.write(s.encode('ascii'))
            self.read = lambda:self.buffer.read().decode('ascii')
            self.readline = lambda:self.buffer.readline().decode('ascii')
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')
 
# Cout implemented in Python
import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = '\n'
 
# Read all remaining integers in stdin, type is given by optional argument, this is fast
def readnumbers(zero = 0):
    conv = ord if py2 else lambda x:x
    A = []; numb = zero; sign = 1; i = 0; s = sys.stdin.buffer.read()
    try:
        while True:
            if s[i] >= b'0' [0]:
                numb = 10 * numb + conv(s[i]) - 48
            elif s[i] == b'-' [0]: sign = -1
            elif s[i] != b'\r' [0]:
                A.append(sign*numb)
                numb = zero; sign = 1
            i += 1
    except:pass
    if s and s[-1] >= b'0' [0]:
        A.append(sign*numb)
    return A
 
if __name__== "__main__":
  main()
