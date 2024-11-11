# Problem: C1. Party
# Contest: Codeforces - ABBYY Cup 2.0 - Easy
# URL: https://codeforces.com/contest/177/problem/C1
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

rank=[0 for _ in range(2000+1)]
par=[_ for _ in range(2000+1)]	
Size=[1 for _ in range(2000+1)]


def findpar(x):
	if x==par[x]:
		return x
	return findpar(par[x])
	
def union(pu,pv):
	if rank[pu]<rank[pv]:
		par[pu]=pv
		Size[pv]+=Size[pu]
	elif rank[pv]<rank[pu]:
		par[pv]=pu
		Size[pu]+=Size[pv]
	else:
		par[pv]=pu
		rank[pu]+=1
		Size[pu]+=Size[pv]
	
if __name__=="__main__":
	# for _ in range(INI()):
	INI()
	n=INI()
	for _ in range(n):
		u,v=INL()
		pu=findpar(u)
		pv=findpar(v)
		
		if pu!=pv:
			union(pu,pv)
	
	q=int(input())
	for _ in range(q):
		u,v=INL()
		pu=findpar(u)
		pv=findpar(v)
		if pu==pv:
			par[pu]=0
	
	ans=0
	for _ in range(1,n+1):
		ans=max(ans,Size[findpar(_)])
	print(ans)