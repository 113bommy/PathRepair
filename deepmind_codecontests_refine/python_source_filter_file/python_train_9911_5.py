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
#ik what to do now, tihs is easy
dict0={}
dict1={}
dict2={}
set3=set([])
for j in range(n-2):
    a,b,c=map(int,input().split())
    setty=set([a,b,c])
    if not(a in dict0):
        dict0[a]=1
        dict1[a]=setty
        dict2[a]=setty
    else:
        dict0[a]+=1
        dict2[a]=dict2[a].union(setty)
    if not(b in dict0):
        dict0[b]=1
        dict1[b]=setty
        dict2[b]=setty
    else:
        dict0[b]+=1
        dict2[b]=dict2[b].union(setty)
    if not(c in dict0):
        dict0[c]=1
        dict1[c]=setty
        dict2[c]=setty
    else:
        dict0[c]+=1
        dict2[c]=dict2[c].union(setty)
    if dict0[a]==3:
        set3.add(a)
    if dict0[b]==3:
        set3.add(b)
    if dict0[c]==3:
        set3.add(c)
#
ind=0
for s in dict0.keys():
    if dict0[s]==1:
        ind=s
        break
ans=[ind]
val=dict1[ind].union(set([]))
val.remove(ind)
for s in val:
    if s in set3:
        continue
    else:
        ans.append(s)
val.remove(ans[-1])
for s in val:
    ans.append(s)
key=ans[-2]
for b in range(n-3):
    if key in dict2:
        temp=dict2[key].union(set([]))
        if len(temp)==4:
            for k in range(3):
                if ans[-k] in temp:
                    temp.remove(ans[-k])
        elif len(temp)==5:
            for k in range(4):
                if ans[-k] in temp:
                    temp.remove(ans[-k])
        for s in temp:
            ans.append(s)
        key=ans[-2]
print(*ans)