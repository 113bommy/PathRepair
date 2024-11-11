import sys, os, io
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math,datetime,functools
from collections import deque,defaultdict,OrderedDict
import collections

def main():
    starttime=datetime.datetime.now()
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    

    
    #Solving Area Starts-->
    zz=0
    for _ in range(1):
        n=ri()
        s=rs()
        c=0
        ans=0
        for i in s:
            if i=='1':
                c+=1
        
        a=[]
        b=[]
        for i in range(n):
            g,h=ria()
            a.append(g)
            b.append(h)
        
        lolu=[0]*1000000
        p=1
        for i in range(n):
            if s[i]=='1':
                for k in range(b[i]):
                    lolu[k]+=1
                # print(1,b[i]-1)
                for k in range(1,p*100,2):
                    for j in range(k*a[i]+b[i],(k+1)*a[i]+b[i]):
                        lolu[j]+=1
                    # print(k*a[i]+b[i],(k+1)*a[i]+b[i]-1)

            else:
                
                for k in range(0,p*100,2):
                    for j in range(k*a[i]+b[i],(k+1)*a[i]+b[i]):
                        lolu[j]+=1
                    # print(k*a[i]+b[i],(k+1)*a[i]+b[i]-1)
            # print("_______________________")
        print(max(lolu))
                    
                
            
        
        
                
            
                
     
        
        
                
                
        
        
        
        
                
        

            
                
            


        
                
            
            
            
            
                    
        















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







