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
def check(dd,i1,i2):
    if dd<0:
        dd=i2-i1
    return dd
def dist(a,b,x,y):
    d1=x-a;d2=y-b;d1=check(d1,x,a);d2=check(d2,y,b)
    return d1+d2
def next1(x,y):
    return (ax*x+bx,ay*y+by)
x,y,ax,ay,bx,by=map(int,input().split())
xs,ys,t=map(int,input().split())
nr=[(x,y)];nxt=next1(x,y)
t2=t
while dist(xs,ys,nxt[0],nxt[1])<dist(xs,ys,nr[-1][0],nr[-1][1]):
    nr.append(nxt);nxt=next1(nxt[0],nxt[1])
#case 1
after=next1(nr[-1][0],nr[-1][1])
ans=0;nearest=nr[-1];vis=set([]);cur=[xs,ys]
while t>0 and not((x,y) in vis):
    d=dist(cur[0],cur[1],nearest[0],nearest[1])
    if d<=t:
        t-=d;vis.add(nearest);ans+=1
        cur=[nearest[0],nearest[1]];nearest=((nearest[0]-bx)//ax,(nearest[1]-by)//ay)
    else:
        break
while t>0:
    d=dist(cur[0],cur[1],after[0],after[1])
    if d<=t:
        t-=d;ans+=1
        cur=[after[0],after[1]];after=next1(after[0],after[1])
    else:
        break
#case 2
nr.append(next1(nr[-1][0],nr[-1][0]))
after=next1(nr[-1][0],nr[-1][1])
ans1=0;nearest=nr[-1];vis=set([]);cur=[xs,ys]
while t2>0 and not((x,y) in vis):
    d=dist(cur[0],cur[1],nearest[0],nearest[1])
    if d<=t2:
        t2-=d;vis.add(nearest);ans1+=1
        cur=[nearest[0],nearest[1]];nearest=((nearest[0]-bx)//ax,(nearest[1]-by)//ay)
    else:
        break
while t2>0:
    d=dist(cur[0],cur[1],after[0],after[1])
    if d<=t2:
        t2-=d;ans1+=1
        cur=[after[0],after[1]];after=next1(after[0],after[1])
    else:
        break
print(max(ans1,ans))