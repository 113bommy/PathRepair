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
def dadd(d,p,val):
	if p in d:
		d[p].append(val)
	else:
		d[p]=[val]		
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
def prec(a,pre):
	for i in a:
		pre.append(pre[-1]+i)
	pre.pop(0)	
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

#10:50

while t>0:
	t-=1
	n=fi()
	a=li()
	mix=n
	vis={}
	ans=[]
	for i in range(n-1,-1,-1):
		if a[i]==mix:
			ans.append(a[i])
			print(*ans[::-1],end=" ")
			ans=[]
			vis[mix]=1
			while mix in vis:
				mix-=1
		else:
			ans.append(a[i])
			vis[a[i]]=1
	print(*ans[::-1])				

