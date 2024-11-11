# Problem: A. Valeriy and Deque
# Contest: Codeforces - Codeforces Round #569 (Div. 1)
# URL: https://codeforces.com/problemset/problem/1179/A
# Memory Limit: 256 MB
# Time Limit: 6000 ms
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

	
if __name__=="__main__":
	n,q=INL()
	X=INL()
	m=max(X)
	i=X.index(m)
	D=[0]
	for _ in range(i+1):
		D.append([X[0],X[1]])
		if X[1]<X[0]:
			X.append(X[1])
			X.pop(1)
		else:
			X.append(X[0])
			X.pop(0)
	
	u=X[0]
	X.pop(0)
	for _ in range(q):
		x=INI()
		if x<=i+1:
			OPL(D[x])
		else:
			OPL([u,X[(x-i+2)%(n-1)]])