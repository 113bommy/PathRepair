import os
import sys
from bisect import bisect, bisect_left, insort, insort_left
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from io import BytesIO, IOBase
from types import GeneratorType

# Fast IO for Python

BUFSIZE: int = 8192


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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
def input(): return sys.stdin.readline().rstrip("\r\n")


# Bootstrap used for recursion, use yield instead of return

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc


# Never use += for string concatenation
# Always use .join for string concatenation
# Use PyPy3 for Codeforces
# Use Python3 for Codechef

# Function to compute inverse of a under modulo m

def modInverse(a, m):

    g = gcd(a, m)

    if (g != 1):
        return -1

    else:
        # If a and m are relatively prime,
        # then modulo inverse is a^(m-2) mode m
        return power(a, m - 2, m)


# Function to compute x^y under modulo m

def power(x, y, m):

    if (y == 0):
        return 1

    p = power(x, y // 2, m) % m
    p = (p * p) % m

    if(y % 2 == 0):
        return p
    else:
        return ((x * p) % m)


# Function to return gcd of a and b

def gcd(a, b):
    if (a == 0):
        return b

    return gcd(b % a, a)


# Sieve of Eratosthenes to get prime upto n

def SieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):

        # If prime[p] is not
        # changed, then it is a prime
        if (prime[p] == True):

            # Update all multiples of p
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1

    ans = set()
    for p in range(2, n+1):
        if prime[p]:
            ans.add(p)

    return ans


MOD = 1000000007


# Main function

def main():
    t = int(input())
    for i in range(t):
        temp = list(map(int, input().split()))
        n, h = temp[0], temp[1]
        a = list(map(int, input().split()))
        if n == 1:
            print(h)
            continue

        diff = []
        for j in range(1, n):
            diff.append(a[j]-a[j-1])

        ans = 100000000000
        diff.sort()
        ssum = diff[0]
        found = False
        if n*ssum >= h:
            if (h % n) == 0:
                ans = min(ans, int(h/n))
            else:
                ans = min(ans, 1+int(h/n))
            found = True

        if found == False:
            for j in range(1, len(diff)):
                h2 = h-ssum
                if (n-j)*diff[j] >= h2:
                    if h2 % (n-j) == 0:
                        ans = min(ans, int(h2/(n-j)))
                    else:
                        ans = min(ans, int(h2/(n-j))+1)
                    found = True
                    break
                else:
                    ssum += diff[j]

        if found == False:
            h2 = h-ssum
            ans = min(ans, h2)

        print(ans)


main()
