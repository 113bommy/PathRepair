t,*g=open(0);h,w=map(int,t.split());v=[[0]*w for _ in range(h)];v[0][0]=1;q=[(0,0)]
while q:
	a,b=q.pop(0)
	for c,d in((-1,0),(0,-1),(1,0),(0,1)):
		x=a+c;y=b+d
		if w>x>=0<=y<h and v[y][x]<1 and g[y][x]==".":q+=[(x,y)];v[y][x]=v[b][a]+1
t=v[-1][-1];print((-1,t-sum(c.count(".")for c in g))[t>0])