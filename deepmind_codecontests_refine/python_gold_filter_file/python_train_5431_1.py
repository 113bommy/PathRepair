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
n=int(input())
total=0;inte=[];pos=[];neg=[]
#add 1 to pos or add 1 to neg
for s in range(n):
    num1=input().split(".")
    num=list(map(int,num1))
    if sum(num)==num[0]:
        total+=num[0]
        inte.append((num[0],s))
    else:
        if num1[0][0]!="-":
            #its positive
            #round down
            pos.append([num[0],s])
            total+=num[0]
        else:
            #its negative
            #round down
            neg.append([num[0]-1,s])
            total+=num[0]-1
for i in range(len(pos)):
    if total<0:
        pos[i][0]+=1;total+=1
    else:
        break
for i in range(len(neg)):
    if total<0:
        neg[i][0]+=1;total+=1
    else:
        break
ans=inte+pos+neg;ans.sort(key=lambda x: x[1])
for i in range(n):
    print(ans[i][0])