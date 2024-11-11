import math
#import math 
#------------------------------warmup----------------------------
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
 
#-------------------game starts now----------------------------------------------------import math
for ik in range(int(input())):
    n,s=map(str,input().split())
    n=int(n)
    smallest=[0]*n
    t=1
    c=s.count('<')+1
    cou=n-c
    for i in range(n-1):
        if s[i]=='>': 
            smallest[t]=cou
            cou-=1
        t+=1
    #print(smallest)
    cou=s.count('<')+1
    rt=[i+1+n-c for i in range(cou)]
    rt=rt[::-1]
    t=0
    ind=0
    i=0
    #print(rt)
    s='<'+s
    while(i<n):
        if s[i]=='<':
            print(i)
            de=i
            while(s[de]=='<'):
                ind+=1
                de+=1
                if de==n:
                    break
            rty=ind
            ind+=-1
            for j in range(i,de):
                    smallest[j]=rt[ind] 
                    ind-=1
                    #print(smallest)
            ind=rty
            i=de
        #print(smallest)
        i+=1
    largest=[0]*n
    s=s+'<'
    w=[]
    for i in range(len(s)):
        if s[i]=='<':
            w.append(i)
    cd=n
    for j in range(len(w)-2,-1,-1):
        for k in range(w[j],w[j+1]):
            largest[k]=cd
            cd-=1
    print(*smallest,sep=' ') 
    print(*largest,sep=' ')
    
        
        