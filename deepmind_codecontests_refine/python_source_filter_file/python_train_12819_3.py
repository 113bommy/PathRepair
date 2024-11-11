import sys, os, io
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math,datetime,functools,itertools,operator,bisect,fractions
from collections import deque,defaultdict,OrderedDict
from fractions import Fraction
from decimal import Decimal
    
def main():
    starttime=datetime.datetime.now()
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    
    def colour(f,arena,n):
        c=0
        for a in range(n):
            for b in range(n):
                if arena[a][b]=='0':
                    if a+1<n and arena[a+1][b]==str(f):
                        arena[a][b]=str(f)  
                        c=1
                    if a-1>=0 and arena[a-1][b]==str(f):
                        arena[a][b]=str(f)
                        c=1
                    if b+1<n and arena[a][b+1]==str(f):
                        arena[a][b]=str(f)
                        c=1
                    if b-1>=0 and arena[a][b-1]==str(f):
                        arena[a][b]=str(f)
                        c=1
        if c==0:
            return 1
        else:
            return colour(f,arena,n)
    
    
    n=ri()
    ra,ca=ria()
    rd,cd=ria()
    arena=[]
    for i in range(n):
        arena.append(list(rs()))
        
    f=2
    for i in range(n):
        for j in range(n):
            if arena[i][j]=='0':
                arena[i][j]=str(f)
                l=colour(f,arena,n)
            f+=1
            
    for i in arena:
        print(i)
    if arena[ra-1][ca-1]==arena[rd-1][cd-1]:
        print(0)
    else:
        na=arena[ra-1][ca-1]
        nd=arena[rd-1][cd-1]
        d=9999999999999999999999
        for i in range(n):
            for j in range(n):
                if arena[i][j]==na:
                    for u in range(n):
                        for v in range(n):
                            if arena[u][v]==nd:
                                d=min(d,(u-i)**2 +(v-j)**2)
        print(d)
        
                    
            
                            
            
                
                
            
                
        
        
        
        
        
        
        
        
        
        
        
            
        
        
                
            
                
        
            
        
        
        
 
                    
        
        
                
    
    #<--Solving Area Ends
    endtime=datetime.datetime.now()
    time=(endtime-starttime).total_seconds()*1000
    if(os.path.exists('input.txt')):
        print("Time:",time,"ms")  
    
                
class FastReader(io.IOBase):
    newlines = 0

    def __init__(self, fd, chunk_size=1024 * 8):
        self._fd = fd
        self._chunk_size = chunk_size
        self.buffer = io.BytesIO()

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, self._chunk_size))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self, size=-1):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, self._chunk_size if size == -1 else size))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()


class FastWriter(io.IOBase):

    def __init__(self, fd):
        self._fd = fd
        self.buffer = io.BytesIO()
        self.write = self.buffer.write

    def flush(self):
        os.write(self._fd, self.buffer.getvalue())
        self.buffer.truncate(0), self.buffer.seek(0)


class FastStdin(io.IOBase):
    def __init__(self, fd=0):
        self.buffer = FastReader(fd)
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


class FastStdout(io.IOBase):
    def __init__(self, fd=1):
        self.buffer = FastWriter(fd)
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.flush = self.buffer.flush


if __name__ == '__main__':
    sys.stdin = FastStdin()
    sys.stdout = FastStdout()
    main()







