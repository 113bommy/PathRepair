# Problem: D. Queue
# Contest: Codeforces - Codeforces Round #303 (Div. 2)
# URL: https://codeforces.com/problemset/problem/545/D
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

def MOD():
        return pow(10,9)+7
	
def OPS(ans):
	stdout.write(str(ans)+"\n")
	
def OPL(ans):
	[stdout.write(str(_)+" ") for _ in ans]
	stdout.write("\n")

	
if __name__=="__main__":
	n=INI()
	A=sorted(INL())
	
	ans=1
	s=A[0]
	
	for _ in range(1,n):
		if A[_]>=s:
			ans+=1
			s+=A[_]
		
	OPS(ans)