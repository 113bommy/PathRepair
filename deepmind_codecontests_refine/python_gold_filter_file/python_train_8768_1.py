# Problem: A. Linova and Kingdom
# Contest: Codeforces - Codeforces Round #635 (Div. 1)
# URL: https://codeforces.com/problemset/problem/1336/A
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
	
from types import GeneratorType

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc
    

@bootstrap
def dfsLevel(u,c):
	V[u]=True
	Level[u]=c
	for _ in X[u]:
		if not V[_]:
			yield dfsLevel(_,c+1)
	yield

@bootstrap
def dfsSubTree(u):
	V[u]=True
	x=0
	for _ in X[u]:
		if not V[_]:
			yield dfsSubTree(_)
			x+=SubTree[_]
	SubTree[u]+=1+x
	yield 
	
	
if __name__=="__main__":

	n,k=INL()
	X=[[] for _ in range(n+1)]
	for _ in range(n-1):
		u,v=INL()
		X[u].append(v)
		X[v].append(u)
	
	V=[False for _ in range(n+1)]
	Level=[0 for _ in range(n+1)]
	dfsLevel(1,0)
	
	V=[False for _ in range(n+1)]
	SubTree=[0 for _ in range(n+1)]
	dfsSubTree(1) 
	
	# print(Level)
	# print(SubTree)
	
	ANS=[]
	for _ in range(1,n+1):
		ANS.append(Level[_]-(SubTree[_]-1))
	# print(ANS)
	
	ANS.sort(reverse=True)
	ans=0
	# print(ANS)
	for _ in range(k):
		ans+=ANS[_]
	OPS(ans)