import os
import sys
from io import BytesIO, IOBase


def main():
    pass


# region fastio

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

#https://github.com/cheran-senthil/PyRival/blob/master/templates/template_py3.py





t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    dp_left=[0 for i in range(n+1)]
    dp_right=[0 for i in range(n+1)]
    for j in range(2):
        for i in range(j+1,n+1):
            if((i+j)%2==1 and s[i-1]=='R'):
                dp_right[j]+=1
            elif((i+j)%2==0 and s[i-1]=='L'):
                dp_right[j]+=1
            else:
                break
    if(s[0]=='L'):
        dp_left[1]=1
    for i in range(2,n+1):
        if(s[i-1]=='L' and s[i-2]=='R'):
            dp_left[i]=dp_left[i-2]+2
        elif(s[i-1]=='L' and s[i-2]=='L'):
            dp_left[i]=1
        elif(dp_right[i-2]>=2):
            dp_right[i]=dp_right[i-2]-2
        else:
            for j in range(i+1,n+1):
                if((i+j)%2==1 and s[j-1]=='R'):
                    dp_right[i]+=1
                elif((i+j)%2==0 and s[j-1]=='L'):
                    dp_right[i]+=1
                else:
                    break
    print(1+dp_right[0],end=" ")
    for i in range(1,n+1):
        print(1+dp_left[i]+dp_right[i],end=" ")
    print("")
            
