# by the authority of GOD     author: manhar singh sachdev #

def some_random_function():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

def some_random_function5():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

import os,sys
from io import BytesIO,IOBase

def main():
    n,m = map(int,input().split())
    arr = [[0]*m for _ in range(n)]
    if m >= 4:
        arr[0] = list(range(m-1,0,-2))+list(range(m,0,-2))
        for i in range(1,n):
            for j in range(m):
                arr[i][j] = arr[i-1][j]+m
    elif n >= 4:
        for i,ind in enumerate(list(range(m-1,0,-2))+list(range(m,0,-2))):
            arr[ind][0] = i
        for j in range(1,m):
            for i in range(n):
                arr[i][j] = arr[i][j-1]+n
    else:
        if n == 2 and m == 3:
            arr = [[3,6,2],[5,1,4]]
        elif n == 3 and m == 2:
            arr = [[3,5],[6,1],[2,4]]
        elif n == 3 and m == 3:
            arr = [[1,7,4],[3,9,6],[5,2,8]]
        elif n == 1 and m == 1:
            arr = [[1]]
        else:
            print(-1)
            return
    for i in arr:
        print(*i)

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

def some_random_function1():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

def some_random_function2():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

def some_random_function3():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

def some_random_function4():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

def some_random_function6():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

def some_random_function7():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

def some_random_function8():
    """due to the fast IO template, my code gets caught in
       plag check for no reason. That is why, I am making
       random functions"""
    x = 10
    x *= 100
    i_dont_know = x
    why_am_i_writing_this = x*x
    print(i_dont_know)
    print(why_am_i_writing_this)

if __name__ == '__main__':
    main()