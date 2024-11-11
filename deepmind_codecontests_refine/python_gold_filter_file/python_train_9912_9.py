# Problem: B. Verse For Santa
# Contest: Codeforces - Educational Codeforces Round 79 (Rated for Div. 2)
# URL: https://codeforces.com/problemset/problem/1279/B
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)

from sys import stdin, stdout 

def INI():
	return int(stdin.readline())
	
def INL():
	return [int(_) for _ in stdin.readline().split()]
	
def INS():
	return stdin.readline()
	
def OPS(ans):
	stdout.write(str(ans)+"\n")
	
def OPL(ans):
	[stdout.write(str(_)+" ") for _ in ans]
	stdout.write("\n")

from itertools import accumulate 
from bisect import bisect_right
	
if __name__=="__main__":
	for _ in range(INI()):
		n,s=INL()
		A=INL()
		Q=list(accumulate(A))
		i=bisect_right(Q,s)
		if i==n:
			OPS(0)
		else:
			ans=0
			m=float("-inf")
			for _ in range(i+1):
				if A[_]>m:
					ans=_+1
					m=A[_]
			OPS(ans)