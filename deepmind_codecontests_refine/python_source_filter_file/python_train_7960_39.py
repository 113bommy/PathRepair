# import bisect
import os
import sys
from io import BytesIO, IOBase
from collections import Counter, defaultdict
from collections import deque
from functools import cmp_to_key
import math
# import heapq

def sin():
    return input()
def ain():
    return list(map(int, sin().split()))
def sain():
    return input().split()
def iin():
    return int(sin())
MAX = float('inf')
MIN = float('-inf')
MOD = 1000000007
def sieve(n): 
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    s = set()
    for p in range(2, n+1): 
        if prime[p]: 
            s.add(p)
    return s
def readTree(n, m):
    adj = [deque([]) for _ in range(n+1)]
    for _ in range(m):
        u,v = ain()
        adj[u].append(v)
        adj[v].append(u)
    return adj

def main():
    n = iin()
    a = iin()
    l = []
    ans = {"1":[], "2":["2"], "3":["3"], "4":["2","2","3"], "5":["5"], "6":["3", "5"], "7":["7"], "8":["2","2","2","8"],"9":["7","3","3","2"]}
    for i in str(a):
        l += ans[i]
    l.sort(reverse=True)
    print("".join(l))
    # fact = list(range(1,10))
    # # print(fact)
    # for i in range(1,9):
    #     fact[i]*=fact[i-1]
    # fact = [1] + fact
    # ans = 1
    # for i in str(a):
    #     ans*=(fact[int(i)])
    # l = [2,3,4,5]
    # d = {2:0, 3:0, 4:0, 5:0}
    # cc = {2:[2], 3:[3], 4:[2,2], 5:[]}
    # while ans != 1:
    #     for i in l:
    #         if ans%i == 0:
    #             d.append(str(i))
    #             ans//=fact[i]
    #             break


        


    




 
        
    






























            
          




        

        


# Fast IO Template starts

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

if os.getcwd() == 'D:\\code':
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
    input = lambda: sys.stdin.readline().rstrip("\r\n")
# Fast IO Template ends
if __name__ == "__main__":
    main()