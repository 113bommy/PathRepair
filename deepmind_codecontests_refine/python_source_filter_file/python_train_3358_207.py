import heapq as hq
from heapq import heappop,heappush
from collections import deque,defaultdict


def inp():
	return (int(input()))


def inlt():
	return (list(map(int,input().split())))


def insr():
	s=input()
	return (list(s[:len(s)]))


def invr():
	return (map(int,input().split()))


def subset_sum_count(arr,n,sum):
	dp=[[0 for _ in range(sum+1)] for _ in range(n+1)]
	for i in range(n+1):
		for j in range(sum+1):
			if j==0:
				dp[i][j]=1
			elif arr[i-1]<=j:
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j]
			else:
				dp[i][j]=dp[i-1][j]
	return dp[n][sum]


def prefix(a):
	pre=[]
	pre.append(a[0])
	for i in range(1,len(a)):
		pre.append(pre[i-1]+a[i])
	return pre


def binary_search(func,lo,hi,abs_prec=1e-7):
	""" Locate the first value x s.t. func(x) = True within [lo, hi] """
	while abs(hi-lo)>abs_prec:
		mi=lo+(hi-lo)/2
		if func(mi):
			hi=mi
		else:
			lo=mi
	
	return (lo+hi)/2


def ternary_search(func,lo,hi,abs_prec=1e-7):
	""" Find maximum of unimodal function func() within [lo, hi] """
	while abs(hi-lo)>abs_prec:
		lo_third=lo+(hi-lo)/3
		hi_third=hi-(hi-lo)/3
		
		if func(lo_third)<func(hi_third):
			lo=lo_third
		else:
			hi=hi_third
	
	return (lo+hi)/2


def discrete_binary_search(func,lo,hi):
	""" Locate the first value x s.t. func(x) = True within [lo, hi] """
	while lo<hi:
		mi=lo+(hi-lo)//2
		if func(mi):
			hi=mi
		else:
			lo=mi+1
	
	return lo


def discrete_ternary_search(func,lo,hi):
	""" Find the first maximum of unimodal function func() within [lo, hi] """
	while lo<=hi:
		lo_third=lo+(hi-lo)//3
		hi_third=lo+(hi-lo)//3+(1 if 0<hi-lo<3 else (hi-lo)//3)
		
		if func(lo_third)<func(hi_third):
			lo=lo_third+1
		else:
			hi=hi_third-1
	
	return lo
	
	return -1


def right_rotate(a,s):
	return a[s:]+a[:s]


def dec_to_bin(x):
	return int(bin(x)[2:])


def str_to_integer_list(n):
	a=[]
	for i in range(len(n)):
		a.append(int(n[i]))
	return a


def list_to_str(l):
	s=""
	for i in l:
		s+=str(i)
	return s


def dijkstra(s,N,E):
	visited=set()
	dist={}
	for i in range(1,N+1):
		dist[i]=1<<29
	queue=[(dist[i],i) for i in range(1,N+1)]
	hq.heappush(queue,(0,s))
	dist[s]=0
	while queue:
		d,u=hq.heappop(queue)
		if u in visited:
			continue
		#Relax all the neighbours of u
		for t in E[u]:
			v,r=t
			if dist[v]>d+r:
				dist[v]=d+r
				hq.heappush(queue,(dist[v],v))
		#Node u has been processed
		visited.add(u)
	return dist


def prime_sieve(n):
	"""returns a sieve of primes >= 5 and < n"""
	flag=n%6==2
	sieve=bytearray((n//3+flag>>3)+1)
	for i in range(1,int(n**0.5)//3+1):
		if not (sieve[i>>3]>>(i&7))&1:
			k=(3*i+1)|1
			for j in range(k*k//3,n//3+flag,2*k):
				sieve[j>>3]|=1<<(j&7)
			for j in range(k*(k-2*(i&1)+4)//3,n//3+flag,2*k):
				sieve[j>>3]|=1<<(j&7)
	return sieve


def prime_list(n):
	"""returns a list of primes <= n"""
	res=[]
	if n>1:
		res.append(2)
	if n>2:
		res.append(3)
	if n>4:
		sieve=prime_sieve(n+1)
		res.extend(3*i+1|1 for i in range(1,(n+1)//3+(n%6==1)) if not (sieve[i>>3]>>(i&7))&1)
	return res


def dijkstra(n,graph,start):
	""" Uses Dijkstra's algortihm to find the shortest path between in a graph. """
	dist,parents=[float("inf")]*n,[-1]*n
	dist[start]=0
	queue=[(0,start)]
	while queue:
		path_len,v=heappop(queue)
		if path_len==dist[v]:
			for w,edge_len in graph[v]:
				if edge_len+path_len<dist[w]:
					dist[w],parents[w]=edge_len+path_len,v
					heappush(queue,(edge_len+path_len,w))
	
	return dist,parents


def path(start,end,parent):
	path=[end]
	while path[-1]!=start:
		path.append(parent[path[-1]])
	path.reverse()
	return path


def bfs(graph,start,goal):
	"""
	finds a shortest path in undirected `graph` between `start` and `goal`.
	If no path is found, returns `None`
	"""
	if start==goal:
		return [start]
	visited={start}
	queue=deque([(start,[])])
	
	while queue:
		current,path=queue.popleft()
		visited.add(current)
		for neighbor in graph[current]:
			if neighbor==goal:
				return path+[current,neighbor]
			if neighbor in visited:
				continue
			queue.append((neighbor,path+[current]))
			visited.add(neighbor)
	return None  # no path found. not strictly needed


'''for _ in range(int(input())):
	n,m=list(map(int,input().split()))
	graph=defaultdict(list)
	distance=[-1]*(n+1)
	visited=[False]*(n+1)
	for _ in range(m):
		x,y=list(map(int,input().split()))
		graph[x].append(y)
		graph[y].append(x)'''
'''for _ in range(int(input())):
	n,m=list(map(int,input().split()))
	graph=[[]for _ in range(n+1)]
	distance=[-1]*(n+1)
	visited=[False]*(n+1)
	for _ in range(m):
		x,y,w=list(map(int,input().split()))
		graph[x].append([y,w])
		graph[y].append([x,w])'''

import os
import sys
from io import BytesIO,IOBase


def p(board):
	for i in range(8):
		s=""
		for j in range(8):
			s+=board[i][j]
		print(s)


def main():
	for x in range(inp()):
		n=inp()
		a=[1]*n
		print(a)
		
		
		
		
		


# region fastio

BUFSIZE=8192


class FastIO(IOBase):
	newlines=0
	
	def __init__(self,file):
		self._fd=file.fileno()
		self.buffer=BytesIO()
		self.writable="x" in file.mode or "r" not in file.mode
		self.write=self.buffer.write if self.writable else None
	
	def read(self):
		while True:
			b=os.read(self._fd,max(os.fstat(self._fd).st_size,BUFSIZE))
			if not b:
				break
			ptr=self.buffer.tell()
			self.buffer.seek(0,2),self.buffer.write(b),self.buffer.seek(ptr)
		self.newlines=0
		return self.buffer.read()
	
	def readline(self):
		while self.newlines==0:
			b=os.read(self._fd,max(os.fstat(self._fd).st_size,BUFSIZE))
			self.newlines=b.count(b"\n")+(not b)
			ptr=self.buffer.tell()
			self.buffer.seek(0,2),self.buffer.write(b),self.buffer.seek(ptr)
		self.newlines-=1
		return self.buffer.readline()
	
	def flush(self):
		if self.writable:
			os.write(self._fd,self.buffer.getvalue())
			self.buffer.truncate(0),self.buffer.seek(0)


class IOWrapper(IOBase):
	def __init__(self,file):
		self.buffer=FastIO(file)
		self.flush=self.buffer.flush
		self.writable=self.buffer.writable
		self.write=lambda s:self.buffer.write(s.encode("ascii"))
		self.read=lambda:self.buffer.read().decode("ascii")
		self.readline=lambda:self.buffer.readline().decode("ascii")


sys.stdin,sys.stdout=IOWrapper(sys.stdin),IOWrapper(sys.stdout)
input=lambda:sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__=="__main__":
	main()