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
##########################################################
from collections import Counter
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
import heapq
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
# n = int(input())
# ls = list(map(int, input().split()))
# n, k = map(int, input().split())
# n =int(input())
#arr=[(i,x) for i,x in enum]
#arr.sort(key=lambda x:x[0])
#print(arr)
# e=list(map(int, input().split()))
from collections import Counter
#print("\n".join(ls))
#print(os.path.commonprefix(ls[0:2]))
#n=int(input())
from bisect import  bisect_right
#for _ in range(int(input())):

    #n=int(input())
n=int(input())
#arr = list(map(int, input().split()))
arr=[(x,i) for i,x in enumerate(input().split())]
arr.sort(key=lambda x:x[0])
var=1
ans=[0]*n
ans[arr[0][1]]=1
f=0
mxx=1

cnt=1
ma=10**5
if arr[0][0]!="1":
    print(-1)
    exit()

for i in range(1,n):
    cnt+=1
    if arr[i][0]==arr[i-1][0]:
        ans[arr[i][1]]=var+1
        var+=1
        mxx = max(var, mxx)
        cnt+=1
        if cnt>ma:
            f=1
            break

    else:
        if int(arr[i][0])!=int(arr[i-1][0])+1:
            f=1
            break
        var=1
        ans[arr[i][1]]=var
        mxx = max(var, mxx)
        ma=cnt


        cnt=1

if f==1 or (n==1 and arr[0][0]!="1"):
    print(-1)
else:
    print(mxx)
    print(*ans)


