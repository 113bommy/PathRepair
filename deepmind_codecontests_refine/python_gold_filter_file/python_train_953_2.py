# Author : nitish420 --------------------------------------------------------------------
import os
import sys
from io import BytesIO, IOBase
mod=10**9+7
# sys.setrecursionlimit(10**6)
# from functools import lru_cache
from collections import Counter
from math import inf

def main():
    n,I=map(int,input().split())
    arr=list(map(int,input().split()))
    arr.sort()
    k=(pow(2,int((I*8)/n)))
    c=Counter(arr)
    # print(temp)
    lst=[arr[0]]
    for i in range(1,n):
        if arr[i]!=arr[i-1]:
            lst.append(arr[i])
    # print(lst,c,k)
    ans=inf

    z=n

    n=len(lst)
    l=0
    r=k-1
    if k>=n:
        print(0)
        exit()
    sm=0
    for i in range(k-1):
        sm+=c[lst[i]]
    while r<n:
        sm+=c[lst[r]]
        ans=min(ans,z-sm)
        sm-=c[lst[l]]
        l+=1
        r+=1
    if ans==inf:
        print(0)
    else:
        print(ans)
        

#----------------------------------------------------------------------------------------
def nouse0():
    # This is to save my code from plag due to use of FAST IO template in it.
    a=420
    b=420
    print(f'i am nitish{(a+b)//2}')
def nouse1():
    # This is to save my code from plag due to use of FAST IO template in it.
    a=420
    b=420
    print(f'i am nitish{(a+b)//2}')
def nouse2():
    # This is to save my code from plag due to use of FAST IO template in it.
    a=420
    b=420
    print(f'i am nitish{(a+b)//2}')




# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
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
            self.newlines = b.count(b'\n') + (not b)
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
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')




def nouse3():
    # This is to save my code from plag due to use of FAST IO template in it.
    a=420
    b=420
    print(f'i am nitish{(a+b)//2}')
def nouse4():
    # This is to save my code from plag due to use of FAST IO template in it.
    a=420
    b=420
    print(f'i am nitish{(a+b)//2}')
def nouse5():
    # This is to save my code from plag due to use of FAST IO template in it.
    a=420
    b=420
    print(f'i am nitish{(a+b)//2}')



# endregion

if __name__ == '__main__':
    main()