#pyrival orz
import os
import sys
import math
from io import BytesIO, IOBase


input = sys.stdin.readline
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def lcm(a, b):
    return (a*b)//gcd(a, b)

def ncr(n, r):
    return math.factorial(n)//(math.factorial(n-r)*math.factorial(r))

def npr(n, r):
    return math.factorial(n)//math.factorial(n-r)

def seive(n):
    primes = [True]*(n+1)
    ans = []

    for i in range(2, n):
        if not primes[i]:
            continue

        j = 2*i
        while j <= n:
            primes[j] = False
            j += i

    for p in range(2, n+1):
        if primes[p]:
            ans += [p]

    return ans

def factors(n):
    factors = []

    x = 1
    while x*x <= n:

        if n % x == 0:
            if n // x == x:
                factors.append(x)
            else:
                factors.append(x)
                factors.append(n//x)

        x += 1

    return factors

# Functions: list of factors, seive of primes, gcd of two numbers,
# lcm of two numbers, npr, ncr

def main():
    try:
        for _ in range(inp()):
            n, u, r, d, l = invr()

            mnv = mnh = 0
            if u >= n-1:
                mnh += u - n + 2
            if r >= n-1:
                mnv += r - n + 2
            if l >= n-1:
                mnv += l - n + 2
            if d >= n-1:
                mnh += d - n + 2

            if u + d < mnv:
                print("NO")
                continue
            if r + l < mnh:
                print("NO")
                continue

            if (u == n or d == n) and (r == 0 or l == 0):
                print("NO")
                continue
            if (l == n or r == n) and (u == 0 or d == 0):
                print("NO")
                continue
            if (u == n and d == n) and (r == 1 or l == 1):
                print("NO")
                continue
            if (l == n and r == n) and (u == 1 or d == 1):
                print("NO")
                continue

            print("YES")
            continue

    except Exception as e:
        print(e)

        

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

# endregion

if __name__ == "__main__":
    main()