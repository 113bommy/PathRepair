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

############ ---- Dijkstra with path ---- ############
def dijkstra(start, distance, path, n):
    # requires n == number of vertices in graph,
    # adj == adjacency list with weight of graph

    visited = [False for _ in range(n)]  # To keep track of vertices that are visited
    distance[start] = 0  # distance of start node from itself is 0

    for i in range(n):
        v = -1  # Initialize v == vertex from which its neighboring vertices' distance will be calculated
        for j in range(n):
            # If it has not been visited and has the lowest distance from start
            if not visited[v] and (v == -1 or distance[j] < distance[v]):
                v = j

        if distance[v] == math.inf:
            break

        visited[v] = True  # Mark as visited

        for edge in adj[v]:
            destination = edge[0]  # Neighbor of the vertex
            weight = edge[1]  # Its corresponding weight

            if distance[v] + weight < distance[destination]:  # If its distance is less than the stored distance
                distance[destination] = distance[v] + weight  # Update the distance
                path[destination] = v  # Update the path
        

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
            a, b, c, d = invr()

            if b >= a:
                print(b)
                continue
            elif a > b and d >= c:
                print(-1)
                continue
            
            rem = a - b

            print(math.ceil(rem/(c-d))*c + b)

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