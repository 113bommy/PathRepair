from collections import deque
from collections import OrderedDict
import math
 
import sys
import os
import threading
import bisect
 
import operator
 
import heapq
 
 
from atexit import register
from io import BytesIO
 
#sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
#sys.stdout = BytesIO()
#register(lambda: os.write(1, sys.stdout.getvalue()))
 
 
import io
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


from sys import stdin, stdout
#input = sys.stdin.readline
#input = stdin.buffer.readline
#print = stdout.write
#a = [int(x) for x in input().split()]


#import os,io
#input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

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
 
 
#sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)


#sys.stdin = open("F:\PY\\test.txt", "r")
input = lambda: sys.stdin.readline().rstrip("\r\n")


def printEr(ar1):
    for i in range(len(ar1)):
        print(ar1[i], end=" ")


    
for _ in range(int(input())):
    n, k = map(int, input().split())  
    tK = k
    s = input()
    if n==1:
        if s[0]=='L' and k==0:
            print(0)
        else:
            print(1)
        continue
    if k==1 and s.count('L')==n:
        print(1)
        continue
    
    if s.count('L')<=k:
        print(2*n-1)
        continue
    if s.count('W')==0 and k!=0:
        print(k*2-1)
        continue
    
    dp = [0]*(n+1)
    dp[0]=(1 if s[0]=='L' else 0)
    
    
    
    #need to improve
    conLost = []
    afWin = False
    if s[0]=='W':
        afWin = True
    for i in range(1, len(s)):
        if s[i]=='L':
            dp[i]=dp[i-1]+1
        else:
            if dp[i-1]!=0:
                if afWin==True:
                    conLost.append(dp[i-1])
                else:
                    afWin=True
    conLost.sort()
    #print(conLost) 
    
    s = s+'L'
    conWin =0
    for i in range(1, n+1):
        if s[i]=='L' and s[i-1]=='W':
            conWin+=1
            
            
            
            
   # print(conWin) 
    for i in range(len(conLost)):
        if conLost[i]<=k:
            conWin-=1
            k-=conLost[i]
        else:
            break
    
   # print(conWin)
    answer = 2*(tK+s.count('W'))-conWin
    print(answer)
    
    

    
    
    
    
'''
     
    
            
            


sys.exit(0)
n  = int(input())
lis = list(map(int, input().split()))
answer = 0
for i in range(n):
    answer+=lis[i]-1
if n==1:
    print(n-1)
elif n>32:
    print(answer)
    sys.exit(0)
lis.sort()
for i in range(2, 50000):
    localMin = 0
    for j in range(n):
        needVal = i**j
        localMin+=abs(lis[j]-needVal)
        if localMin>answer:
            break
    else:
        answer = min(localMin, answer)
print(answer)
     
                
    
        
    


n = int(input())
lis = list(map(int, input().split()))
sumAr = 0
for i in range(n):
    sumAr+=lis[i]
k = (sumAr-(n*(n-1)//2))//n
dif = sumAr - (k*n+(n*(n-1)//2))

answer=[]
for i in range(n):
    if i<dif:
        print(k+i+1)
        #print(k+i+1, end=" ")
    else:
        print(k+i)
        #print(k+i, end=" ")

#print(*answer, sep=" ")
        






sys.exit(0)

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

p1 = Person("heelo", 27)

print(help(Person))


age = 26
name = 'Swaroop'
print('Возрас {} -- {} лет'.format(name, age))
print(help(object))



for _ in range(int(input())):
    
    n = int(input())
    ar = list(map(int, input().split()))
    dp = [0]*100005
    for i in range(n):
        dp[ar[i]]+=1
    ar.clear()
    for i in range(len(dp)):
        if dp[i]!=0:
            ar.append(dp[i])       
    ar.sort()
    maxC = ar[len(ar)-1]
    sumA = sum(ar)
    answer=0
    for i in range(len(ar)):
        if ar[i]==maxC:
            answer+=1
            sumA-=maxC
    answer-=1
    answer+= min(sumA//(maxC-1), len(ar)-1)
    print(answer)
    #sys.exit(0)   
         
    




def maxDisjointIntervals(list_):
    list_.sort(key=lambda x: x[1])
    print(list_[0][0], list_[0][1])
    r1 = list_[0][1]
    for i in range(1, len(list_)):
        l1 = list_[i][0]
        r2 = list_[i][1]
        if l1>r1:
            print(l1, r2)
            r1 = r2

if __name__ =="__main__1":
    N=4
    intervals = [[1, 4], [2, 3], [4,6], [8,9]]
    maxDisjointIntervals(intervals)
    
    '''
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    