import os,sys,math 
from io import BytesIO, IOBase
from collections import defaultdict,deque,OrderedDict
import bisect as bi
def yes():print('YES')
def no():print('NO')
def I():return (int(input()))
def In():return(map(int,input().split()))
def ln():return list(map(int,input().split()))
def Sn():return input().strip()
BUFSIZE = 8192
#complete the main function with number of test cases to complete greater than x
def find_gt(a, x):
    i = bi.bisect_left(a, x)
    if i != len(a):
        return i
    else:            
        return len(a)

def solve():
    v=I()
    l=list(In())
    d={}
    if v==0:
        print(-1)
        return
    mn=float('inf')
    for i in range(9):
        d[i+1]=l[i]
        mn=min(mn,l[i])
    chance=[]
    for i in range(1,10):
        if d[i]==mn:
            chance.append(i)
    mx_len=0
    ans=[0]*(10)
    for x in chance:
        if v//d[x]>=mx_len:
            mx_len=v//d[x]
            rem=v%d[x]
            temp=[0]*(10)
            temp[x]=mx_len
            ok=True
            while ok and rem :
                ok=False
                for i in range(9,0,-1):
                    if i==x:
                        continue
                    if rem+d[x]>=d[i]:
                        temp[i]+=1
                        rem-=(d[i]-d[x])
                        temp[x]-=1
                        ok=True
                        break
            ch=False
            for i in range(9,0,-1):
                if temp[i]>ans[i]:
                    ch=True
                    break
            ans=temp.copy()
    if sum(ans)==0:
        print(-1)
        return
    for i in range(9,0,-1):
        for j in range(ans[i]):
            print(i,end='')
    print()
    pass



def main():
    T=1
    for i in range(T):
        solve()
        
M = 998244353
P = 1000000007
 




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

# endregion

if __name__ == "__main__":
    main()