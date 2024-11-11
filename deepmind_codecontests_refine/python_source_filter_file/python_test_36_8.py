import bisect
import math
from collections import deque, defaultdict
from heapq import heappush,heappop,heapify
import functools
from queue import Queue
from collections import defaultdict
from pprint import pprint
from math import gcd, floor, sqrt, log2, ceil
from random import randint 
from bisect import bisect_left, bisect_right


# mod =  998244353 
mod = int(1e9)+7

N = 200005

getnum = lambda : int(input())
getstr = lambda : input()
getnums = lambda :map(int, input().split())
newline = lambda: print()

def mul(a, b):
	return (a*b)%mod

def add(a, b):
	return (a+b) if (a+b<mod) else (a+b)-mod

def sub(a, b):
	return (a-b) if (a-b>=0) else (a-b)+mod

def powr(a, b):
	ans = 1
	while b>0:
		if b & 1:
			ans=mul(ans,a)
		a = mul(a,a) 
		b//=2
	return ans

def inv(n):
	return powr(n, mod-2)

def factlist():
	fact = [1]
	for i in range(1, N):
		fact.append(mul(fact[i-1],i))
	return fact

def invfactlist(fact):
	invfact=[0]*N
	invfact[0]=1
	invfact[N-1]= inv(fact[N-1])
	for i in range(N-2, 0, -1):
		invfact[i]= mul(invfact[i+1],(i+1))
	
	return invfact

def rot(S):
	return list(zip(*S[::-1]))

def gcd(a, b):
	if b==0:
		return a
	return gcd(b, a%b)

def generate():
	ans = [0]
	while ans[-1]<1000000000:
		ans.append(1+ans[-1]*2)
	return ans

def addEdge(a,b, graph):
    graph[a].append(b)
    graph[b].append(a)

def bfs(src, graph, visited):
    
    q = deque([])
    q.append(src)
    visited[src] = True
    ele = []
    while(q):
        node = q.popleft()
        ele.append(node)
        for neighbour in graph[node]:
            if(not visited[neighbour]):
                q.append(neighbour)
                visited[neighbour]= True
    return ele


# def dfs(src, graph, visited):
# 	q = deque([])
#     q.append(src)
#     visited[src] = True
#     ele = []
#     while(q):
#         node = q.pop()
#         ele.append(node)
#         for neighbour in graph[node]:
#             if(not visited[neighbour]):
#                 q.append(neighbour)
#                 visited[neighbour]= True
#     return ele

class DSU:
    def __init__(self,n):
        self.arr = []
        self.size = []
        for i in range(n):
            self.arr.append(i)
            self.size.append(1)

    def root(self,i):
        while self.arr[i] != i:
            self.arr[i] = self.arr[self.arr[i]]
            i = self.arr[i]
        return i
 
    def union(self,A,B):
        root_A = self.root(A)
        root_B = self.root(B)
        if self.size[root_A] < self.size[root_B]:
            self.arr[root_A] = self.arr[root_B]
            self.size[root_B] += self.size[root_A]
        else:
            self.arr[root_B] = self.arr[root_A]
            self.size[root_A] += self.size[root_B]
 
    def find(self,A,B):
        if self.root(A) == self.root(B):
            return True
        else:
            return False

def subsum(arr, n, Sum):
	prevSum = defaultdict(lambda : 0)
	print(arr, Sum)
	ans = float('inf')
	currsum = 0
	for i in range(0, n): 

		currsum += arr[i]
		if currsum == Sum: 
			ans = min(ans, i+1)     

		if (currsum - Sum) in prevSum:
			ans = min(ans,  i-preSum[(currsum - Sum)] )
	if ans > n:
		return -1
	return ans

def isprime(num):
	for i in range(2, int(sqrt(num))):
		if num%i==0:
			return False
	return True

def main():
	# code for per test case
	t = int(input())
	while t:
		t-=1
		n =int(input())
		lst = list(getnums())
		sm = sum(lst)
		if isprime(sm):	
			ele = -1
			for i in range(n):
				if not isprime(sm-lst[i]):
					ele = i+1
					break

			print(n-1)
			for i in range(1,n+1):
				if i==ele:
					continue
				print(i, end=" ")

		else:
			print(n)
			for i in range(1,n+1):
				print(i, end=" ")
			
		print()










if __name__ == "__main__":
	main()
    
	