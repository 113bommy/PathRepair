import os
import sys
from io import BytesIO, IOBase
 
BUFSIZE = 8192
#AGAR PLAIGIARISM NIKAALA TOH MAA CHODENGE 
#AGAR PLAIGIARISM NIKAALA TOH MAA CHODENGE
#AGAR PLAIGIARISM NIKAALA TOH MAA CHODENGE
#AGAR PLAIGIARISM NIKAALA TOH MAA CHODENGE
#AGAR PLAIGIARISM NIKAALA TOH MAA CHODENGE

#AGAR PLAIGIARISM NIKAALA TOH MAA CHODENGE
#AGAR PLAIGIARISM NIKAALA TOH MAA CHODENGE 
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
#######################################
for _ in range(int(input())):
    '''n = int(input())'''
    n,a,b = map(int,input().split())
    '''l = list(map(int,input().split()))'''
    if a == 1 or b == 1:
        if a == 1:
            if (n-1)%b == 0:
                print("Yes")
            else:
                print("No")
        else:
            print("Yes")
    else:
        c = n
        k = 0
        while c>1:
            c = c//n
            k+=1
        t = 0
        for i in range(k+5):
            rr = n
            if i == 0:
                if (n-1)%b == 0:
                    t = 1
                    break
            else:
                rr-=(a**i)
                if rr<0:
                    break
                if rr%b == 0:
                    t = 1
                    break
        if t:
            print("Yes")
        else:
            print("No")
    
    
        
        
    
