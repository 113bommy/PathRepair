# Problem: A. Mashmokh and Numbers
# Contest: Codeforces - Codeforces Round #240 (Div. 1)
# URL: https://codeforces.com/contest/414/problem/A
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

from math import ceil	
if __name__=="__main__":
	ANS=[]
	n,k=INL()
	if n//2>k or (n==1 and k==1):
		OPS(-1)
	else:
	 	s=n//2-1
	 	ANS.extend([k-s,2*(k-s)])
	 	x=ANS[-1]+1
	 	for _ in range(2*s):
	 		ANS.append(x)
	 		x+=1
	 	ANS+=[x+1]
	 	OPL(ANS[:n])