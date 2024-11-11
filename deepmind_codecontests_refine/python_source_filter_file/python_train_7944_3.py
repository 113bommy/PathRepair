import sys

pl=1
sys.setrecursionlimit(10**5)
if pl:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('outpt.txt','w')

def li():
	return [int(xxx) for xxx in input().split()]
def fi():
	return int(input())
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())	
def ff():
	sys.stdout.flush()
		
t=fi()
	
def f(a):
	ans=a
	c=""
	for i in range(11):
		c+="9"
		if int(c)>=a:
			break
		l=0
		r=10**10
		res=0
		while l<=r:
			mid=(l+r)//2
			if mid*10**(len(c))+int(c)<=a:
				res=mid+1
				l=mid+1
			else:
				r=mid-1	
		ans+=res
	return ans			

while t>0:
	t-=1
	a,b=mi()
	print(f(b)-f(a))