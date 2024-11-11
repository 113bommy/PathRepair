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
algo=list(map(int,input().split()))
skill=list(map(int,input().split()))
#ok i think i may know
dict1={}
dict2={}
for s in range(n):
    nums=algo[s]
    if not(nums in dict1):
        dict1[nums]=1
        dict2[nums]=skill[s]
    else:
        dict1[nums]+=1
        dict2[nums]+=skill[s]
#find 2 students that are equal and know the most algorithms
maxsofar=0
keys=[]
for s in dict1.keys():
    keys.append(s)
for s in keys:
    if s in dict1:
        if dict1[s]>=2:
            #then find all students with their susbet of skills
            popkeys=[]
            if s!=0:
                for j in dict1.keys():
                    if (s^j==(max(s,j)-min(s,j))) and j!=s and j!=0:
                        dict2[s]+=dict2[j]
                        popkeys.append(j)
                        dict1[s]+=dict1[j]
            for j in range(len(popkeys)):
                dict1.pop(popkeys[j])
                dict2.pop(popkeys[j])
for s in dict1.keys():
    if dict1[s]>=2:
        skills=dict2[s]
        if s!=0:
            for j in dict1.keys():
                if s!=j and dict1[j]>=2 and j!=0:
                    skills+=dict2[j]
        if skills>maxsofar:
            maxsofar=skills
print(maxsofar)