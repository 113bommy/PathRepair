#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
import threading 
from math import factorial as fac
from collections import deque,defaultdict

def set_bits(num):
    bits = set()
    for i in range(9):
        if num&(1<<i):
            bits.add(i)
    
    return bits



def main():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))

    N = 2**9
    for ans in range(N):
        ans_set = set_bits(ans)
        #print(f'ANs set = {ans_set}')
        c = list(bytearray(n))   
        tem_ans = set()
        for i in range(n):
            countj = 0
            for j in range(m):
                operation = a[i]&b[j]
                #print(f'operation = {operation} ai = {a[i]} bj = {b[j]}')
                bits = set_bits(operation)
                if bits.issubset(ans_set):
                    print(f'selected operation = {operation} ai = {a[i]} bj = {b[j]}')
                    countj+=1
                    c[i] = 1
                    tem_ans.update(bits)
            
            if countj == 0:
                break

        if sum(c)==n and tem_ans == ans_set:
            #print(f'c = {c}')
            #print(f' ans_bits ={ans_set} and tem_ans = {tem_ans}')
            print(ans)
            exit(0)



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

