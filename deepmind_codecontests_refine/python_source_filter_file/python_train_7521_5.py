import os
import heapq
import sys
import math
import bisect
import operator
from collections import defaultdict
from io import BytesIO, IOBase
def gcd(a,b):
    if b==0:

        return a
    else:
        return gcd(b,a%b)
def power(x, p,m):
    res = 1
    while p:
        if p & 1:
            res = (res * x) % m
        x = (x * x) % m
        p >>= 1
    return res
def inar():
    return [int(k) for k in input().split()]


# def bubbleSort(arr,b):
#     n = len(arr)
#     for i in range(n):
#         for j in range(0, n - i - 1):
#             if arr[j] > arr[j + 1] and b[j]!=b[j+1]:
#                 arr[j], arr[j + 1] = arr[j + 1], arr[j]
#                 b[j],b[j+1]=b[j+1],b[j]
def lcm(num1,num2):
    return (num1*num2)//gcd(num1,num2)

def main():
    for _ in range(int(input())):
        n=int(input())
        #n,k=map(int,input().split())
        arr=inar()
        res="abcdefghijklmnopqrstuvwx"
        c=0
        st=["a"*arr[0],"a"*arr[0]]
        for i in range(1,n):
            if arr[i]>arr[i-1]:
                rem=arr[i]-len(st[i])
                c=(c+1)%24
                st[i]+=res[c]*rem
                st.append(st[i])
            else:
                temp=st[i][0:arr[i]]
                st.append(temp)
        take="yz"
        c=0
        for i in range(len(st)):
            if len(st[i])==0:
                c=(c+1)%2
                print(res[c]*1)
                continue
            print(st[i])









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

if __name__ == "__main__":
    main()
