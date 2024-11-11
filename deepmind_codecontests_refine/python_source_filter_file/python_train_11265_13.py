import sys, os, io
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math,datetime,functools,itertools,operator,bisect,fractions,statistics
from collections import deque,defaultdict,OrderedDict,Counter
from fractions import Fraction
from decimal import Decimal
from sys import stdout

def main():
    starttime=datetime.datetime.now()
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    
    
    for _ in range(1):
        n=ri()
        a=ria()
        zaa=a.copy()
        a=[0]+a+[0]
        
        strincsubarrays=[]
        top=[]
        s=0
        for i in range(1,n+2):
            if a[i]-a[i-1]<=0:
                strincsubarrays.append(s)
                s=1
            else:
                s+=1
            # if i>1 and i<n+1 and a[i]>=a[i-1] and a[i+1]>a[i-1]:
            #     top.append(i-1)
        ans=max(strincsubarrays)
        na=[]
        c=0
        for i in strincsubarrays:
            c+=1
            na+=[[i,c]]*i
        
        for i in range(1,n-1):
            if zaa[i-1]<zaa[i+1] and na[i][1]!=na[i-1][1]:
                k=na[i][0]-1+na[i-1][0]
                if k>ans:
                    ans=k
        print(ans)
        # print(strincsubarrays)
        # print(top)
        # print(na)
        # for i in range(len(top)):
        #     if top[i]+1<len(na):
        #         A=na[top[i]]
        #         B=na[top[i]+1]
        #         nm=A-1+B
        #         if nm>ans:
        #             ans=nm
        # print(ans)
            
        
        
            
        
                        

        
        
            
     
        
        
            
        
        
                
            
        
        
        
                
            
        

            
             
        
            
        
        
        
                
        
            
        
        
        
        
                
        
        
            
        
        
        
        
                
        
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
    