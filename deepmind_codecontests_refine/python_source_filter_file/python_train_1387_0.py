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


  
while t>0:
	t-=1
	n,m=mi()
	a=li()
	b=list(input().split())
	c=[]
	d=[]
	for i in range(n):
		if a[i]%2:
			c.append([a[i],b[i],i])
		else:	
			d.append([a[i],b[i],i])
	c.sort()
	d.sort()
	st=[]
	ans=[-1]*n
	for i in range(len(c)):
			if len(st)==0:
				st.append(c[i])
			else:
				if st[-1][1]=='R' and c[i][1]=='L'	:
					ans[st[-1][2]]=ans[c[i][2]]=abs(c[i][0]-st[-1][0])//2
					st.pop()
				else:
					st.append(c[i])

	i=0	
	p=[]
	q=[]
	r=[]
	for i in range(len(st)):
		if st[i][1]=='L':
			p.append(st[i])
		else:
			q.append(st[i])
	if len(p)%2:
		r.append(p[-1])
		p.pop()
	if len(q)%2:
		r.append(q[0])
		q.pop(0)			
	for i in range(0,len(p),2):
		ans[p[i][2]]=ans[p[i+1][2]]=p[i][0]+abs(p[i][0]-p[i+1][0])//2
	for i in range(len(q)-2,-1,-1):
		ans[q[i][2]]=ans[q[i+1][2]]=m-q[i+1][0]+abs(q[i][0]-q[i+1][0])//2
	if len(r)>1:
		ans[r[-1][2]]=ans[r[-2][2]]=m-(abs(r[0][0]-r[1][0]))//2
	st=[]
	for i in range(len(d)):
		if len(st)==0:
			st.append(d[i])
		else:
			if st[-1][1]=='R' and d[i][1]=='L'	:
				ans[st[-1][2]]=ans[d[i][2]]=abs(d[i][0]-st[-1][0])//2
				st.pop()
			else:
				st.append(d[i])		
	p=[]
	q=[]
	r=[]
	for i in range(len(st)):
		if st[i][1]=='L':
			p.append(st[i])
		else:
			q.append(st[i])
	if len(p)%2:
		r.append(p[-1])
		p.pop()
	if len(q)%2:
		r.append(q[0])
		q.pop(0)			
	for i in range(0,len(p),2):
		ans[p[i][2]]=ans[p[i+1][2]]=p[i][0]+abs(p[i][0]-p[i+1][0])//2
	for i in range(len(q)-2,-1,-1):
		ans[q[i][2]]=ans[q[i+1][2]]=m-q[i+1][0]+abs(q[i][0]-q[i+1][0])//2
	if len(r)>1:
		ans[r[-1][2]]=ans[r[-2][2]]=m-(abs(r[0][0]-r[1][0]))//2				
	print(*ans)			
				