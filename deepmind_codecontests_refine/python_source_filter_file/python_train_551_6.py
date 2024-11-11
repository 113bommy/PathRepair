import os
import sys
from io import BytesIO, IOBase
 
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
from heapq import heappush,heappop
from collections import defaultdict
n=int(input())
arr=[]
for i in range(n):
    a,b=map(int,input().split())
    arr.append([a,b])
arr.sort(key=lambda x:x[1])
i,j=0,n-1
ans,curr=0,0
while(i<=j):
    if arr[i][1]<=curr:
        curr+=arr[i][0]
        i+=1
    elif arr[j][0]+curr<=arr[i][1]:
        curr+=arr[j][0]
        ans+=arr[j][0]
        j-=1
    else:
        arr[j][0]-=arr[i][1]-curr
        ans+=arr[i][1]-curr
        curr+=arr[i][1]
print(ans+curr)
        



# heap=[]
# for i in d:
#     val=d[i]
#     for _ in range(50):
#         d[i]//=2
#         if val-d[i]!=0:
#             heappush(heap,(i,val-d[i]))
#         val=d[i]
#         if val==0:
#             break
#     if val!=0:
#         heappush(heap,(i,val))
#     # heappush(heap,(i,d[i]))
# arr=[]
# while(heap):
#     a,b=heappop(heap)
#     arr.append([a,b])
# # arr=sorted(d.items(),key=lambda x:x[1])
# # print(arr)
# # a=[]
# # for a_,b in arr:
#     # a.append([a_,b])
# tot=0
# ans=0
# i=0
# # print(arr)
# while (arr):
#     # print(arr[0][0])
#     if tot>=arr[0][0]:
        
#         val=arr.pop(0)
#         # print(val)
#         tot+=val[1]
#         ans+=(val[1])
        
#         # print(a.pop(0))
#     else:
#         tot_=tot
#         val=arr.pop()
#         # print(val)
#         tot+=val[1]
#         ans+=(val[1])*2
#         ans-=max(tot-val[0],0)
#     # print(ans,tot)
#         # print(a.pop())
# print(ans)