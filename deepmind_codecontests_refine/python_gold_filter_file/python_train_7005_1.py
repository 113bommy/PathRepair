import sys

zz=1
 
sys.setrecursionlimit(10**5)
if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('all.txt','w')
di=[[-1,0],[1,0],[0,1],[0,-1]]

def fori(n):
	return [fi() for i in range(n)]	
def inc(d,c,x=1):
	d[c]=d[c]+x if c in d else x
def ii():
	return input().rstrip()	
def li():
	return [int(xx) for xx in input().split()]
def fli():
	return [float(x) for x in input().split()]	
def comp(a,b):
	if(a>b):
		return 2
	return 2 if a==b else 0		
def gi():	
	return [xx for xx in input().split()]
def gtc(tc,ans):
	print("Case #"+str(tc)+":",ans)	
def cil(n,m):
	return n//m+int(n%m>0)	
def fi():
	return int(input())
def pro(a): 
	return reduce(lambda a,b:a*b,a)		
def swap(a,i,j): 
	a[i],a[j]=a[j],a[i]	
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())			
def gh():
	sys.stdout.flush()
def isvalid(i,j,n,m):
	return 0<=i<n and 0<=j<m 
def bo(i):
	return ord(i)-ord('a')	
def graph(n,m):
	for i in range(m):
		x,y=mi()
		a[x].append(y)
		a[y].append(x)


t=fi()
uu=t

while t>0:
	t-=1
	n,m,a,b=mi()
	p=li()
	p.sort()
	if a>b:
		r=n-a+abs(a-b)
	else:
		r=a+abs(a-b)-1
	def can(mid,r):
		for i in range(mid,-1,-1):
			#print(mid,p[i],r)
			if p[i]>=r:
				
				return False
			r-=1	
		return True
	l=ans=0
	rr=min(abs(a-b)-2,m-1)
	#print(r,rr)
	while l<=rr:

		mid=(l+rr)//2
		if can(mid,r):
			ans=mid+1
			l=mid+1
		else:
			rr=mid-1
	print(ans)						
