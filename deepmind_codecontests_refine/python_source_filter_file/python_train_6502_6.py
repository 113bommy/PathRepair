# #------------------------------what is this I don't know....just makes my mess faster--------------------------------------
# import os
# import sys
# from io import BytesIO, IOBase
# import math

# BUFSIZE = 8192
 
# class FastIO(IOBase):
#     newlines = 0
 
#     def __init__(self, file):
#         self._fd = file.fileno()
#         self.buffer = BytesIO()
#         self.writable = "x" in file.mode or "r" not in file.mode
#         self.write = self.buffer.write if self.writable else None
 
#     def read(self):
#         while True:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             if not b:
#                 break
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines = 0
#         return self.buffer.read()
 
#     def readline(self):
#         while self.newlines == 0:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             self.newlines = b.count(b"\n") + (not b)
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines -= 1
#         return self.buffer.readline()
 
#     def flush(self):
#         if self.writable:
#             os.write(self._fd, self.buffer.getvalue())
#             self.buffer.truncate(0), self.buffer.seek(0)
 
 
# class IOWrapper(IOBase):
#     def __init__(self, file):
#         self.buffer = FastIO(file)
#         self.flush = self.buffer.flush
#         self.writable = self.buffer.writable
#         self.write = lambda s: self.buffer.write(s.encode("ascii"))
#         self.read = lambda: self.buffer.read().decode("ascii")
#         self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
# sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
# input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# #----------------------------------Real game starts here--------------------------------------
n,m = list(map(int, input().split()))
# def binom(n,k): # better version - we don't need two products!
#     if not 0<=k<=n: return 0
#     b=1
#     for t in range(min(k,n-k)):
#         b*=n; b/=t+1; n-=1
#     return int(b)
# mini = (m-(n % m))*math.factorial(n//m)/math.factorial(n//m-2)/2 + (n % m)*math.factorial(n//m+1)/math.factorial(n//m-1)/2
# maxi = math.factorial(n-m+1)/math.factorial(n-m-1)/2
# mini = (m-(n % m))*binom(n//m,2) + (n % m)*binom(n//m+1,2)
# maxi = binom(n-m+1,2)
mini = int((m-(n % m))*((n//m) * (n//m-1))*.5 + (n % m)*((n//m+1)*(n//m)*.5))
maxi = int((n-m+1)*(n-m)*.5)
print(mini)
print(maxi)