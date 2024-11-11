#pyrival orz
import os
import sys
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

def seive(n):
    primes = [True]*(n+1)

    for i in range(2, n):
        if not primes[i]:
            continue
        
        j = 2*i
        while j <= n:
            primes[j] = False
            j += i

    return primes

def factors(n):
    factors = []

    x = 2
    while x*x <= n:

        while n % x == 0:
            factors.append(x)
            n //= x

        if n > 1:
            factors.append(x)

    return factors

# Functions: list of factors, seive of primes, gcd of two numbers

def main():
    try:
        n, k, d = invr()
        mod = int(1e9 + 7)
        dp = [[0, 0] for _ in range(100)]
        dp[0][0] = 1
        dp[0][1] = 0

        for i in range(1, n+1):
            dp[i][0] = dp[i][1] = 0

            for j in range(1, k+1):
                if i - j < 0:
                    break

                if j < d:
                    dp[i][0] += dp[i-j][0]
                    dp[i][0] %= mod

                    dp[i][1] += dp[i-j][1]
                    dp[i][1] %= mod
                
                else:
                    dp[i][1] += dp[i-j][0]
                    dp[i][1] %= mod

                    dp[i][1] += dp[i-j][1]
                    dp[i][1] %= mod

        print(dp[n][1])


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