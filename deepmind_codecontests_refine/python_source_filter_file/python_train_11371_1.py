# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def main():
    n,m,k = map(int,input().split())
    if k > 4*n*m-2*m-2*n:
        print('NO')
        exit()
    print('YES')
    if n == 1:
        step = [(m-1,'L'),(m-1,'R')]
    elif m == 1:
        step = [(n-1,'D'),(n-1,'U')]
    else:
        v,v1 = [(n-1,'RLD'),(n-1,'RLU')],(1,'R')
        step = [(n-1,'RLD')]
        for i in range(m-1):
            step.append(v1)
            if i != m-2:
                step.append(v[not i%2])
            else:
                z = list(v[not i%2])
                z[1] = z[1][2:]
                step.append(tuple(z))
        if m&1:
            step.append((n-1,'U'))
        else:
            step.append((n-1,'D'))
        v,v1 = [(n-1,'D'),(n-1,'U')],(1,'L')
        for i in range(m-1):
            step.append(v1)
            step.append(v[(m-i-1)%2])
    fin = []
    ans = 0
    for i in step:
        ans += len(i[1])*i[0]
        if ans > k:
            ans -= len(i[1])*i[0]
            if k-ans >= len(i[1]):
                fin.append(((k-ans)//len(i[1]),i[1]))
            z = (k-ans)%len(i[1])
            if z:
                fin.append((1,i[1][:z]))
            break
        fin.append(i)
    print(len(fin))
    for i in fin:
        print(*i)

# Fast IO Region
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
if __name__ == "__main__":
    main()