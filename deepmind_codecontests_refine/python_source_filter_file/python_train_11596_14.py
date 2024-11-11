# Problem: A. k-Multiple Free Set
# Contest: Codeforces - Codeforces Round #168 (Div. 1)
# URL: https://codeforces.com/problemset/problem/274/A
# Memory Limit: 256 MB
# Time Limit: 2000 ms
# 
# KAPOOR'S

from sys import stdin, stdout 

def INI():
	return int(stdin.readline())
	
def INL():
	return [int(_) for _ in stdin.readline().split()]
	
def INS():
	return stdin.readline()

def MOD():
    return pow(10,9)+7
	
def OPS(ans):
	stdout.write(str(ans)+"\n")
	
def OPL(ans):
	[stdout.write(str(_)+" ") for _ in ans]
	stdout.write("\n")


from bisect import bisect_left

if __name__=="__main__":
	n,k=INL()
	X=sorted(INL())
	BOOL=[True for _ in range(n)]
	
	for _ in range(n):
		if BOOL[_]==True and k*X[_]<=X[-1]:
			i=bisect_left(X,k*X[_])
			if X[i]==k*X[_]:
				BOOL[i]=False
	OPS(BOOL.count(True))