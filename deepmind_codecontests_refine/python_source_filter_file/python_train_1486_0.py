# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def main():
    n,m = map(int,input().split())
    arr = [list(input().strip()) for _ in range(n)]
    if n >= 4 and m >= 4:
        print(-1)
    elif n == 1 or m == 1:
        print(0)
    else:
        ans = 10**10
        if m==3 or n==3:
            pos = ['000','100','010','001','110','101','011','111']
            if m == 3:
                for i in pos:
                    fin = (arr[0][0]==i[0])+(arr[0][1]==i[1])+(arr[0][2]==i[2])
                    fis,sec = (int(i[0])+int(i[1])+1)%2,(int(i[1])+int(i[0])+1)%2
                    for j in range(1,n):
                        s = 0
                        if (int(arr[j][0])+int(arr[j][1]))%2 != fis:
                            s += 1
                        if (int(arr[j][1])+int(arr[j][2]))%2 != sec:
                            s += 1
                        if s == 2:
                            s -= 1
                        fin += s
                        fis ^= 1
                        sec ^= 1
                    ans = min(ans,fin)
            if n == 3:
                for i in pos:
                    fin = (arr[0][0]==i[0])+(arr[1][0]==i[1])+(arr[2][0]==i[2])
                    fis,sec = (int(i[0])+int(i[1])+1)%2,(int(i[1])+int(i[0])+1)%2
                    for j in range(1,m):
                        s = 0
                        if (int(arr[0][j])+int(arr[1][j]))%2 != fis:
                            s += 1
                        if (int(arr[1][j])+int(arr[2][j]))%2 != sec:
                            s += 1
                        if s == 2:
                            s -= 1
                        fin += s
                        fis ^= 1
                        sec ^= 1
                    ans = min(ans,fin)
        elif m==2 or n==2:
            pos = ['00', '10', '01', '11']
            if m == 2:
                for i in pos:
                    fin = (arr[0][0]==i[0])+(arr[0][1]==i[1])
                    fis = (int(i[0])+int(i[1])+1)%2
                    for j in range(1,n):
                        s = 0
                        if (int(arr[j][0])+int(arr[j][1]))%2!=fis:
                            s += 1
                        fin += s
                        fis ^= 1
                    ans = min(ans, fin)
            if n == 3:
                for i in pos:
                    fin = (arr[0][0] == i[0]) + (arr[1][0] == i[1])
                    fis = (int(i[0])+int(i[1])+1)%2
                    for j in range(1, m):
                        s = 0
                        if (int(arr[0][j])+int(arr[1][j])) % 2 != fis:
                            s += 1
                        fin += s
                        fis ^= 1
                    ans = min(ans, fin)
        print(ans)


#Fast IO Region
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

if __name__ == '__main__':
    main()