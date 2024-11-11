import sys
LI=lambda:list(map(int, sys.stdin.readline().split()))
MI=lambda:map(int, sys.stdin.readline().split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline())
# sys.stdin=open('input.txt')
# sys.stdout=open('output.txt', 'w')
def find(v):
	global p
	tmp=v
	while p[tmp]!=tmp:
		tmp=p[tmp]
	p[v]=tmp
	return tmp
def merge(a, b):
	global p, r
	roota, rootb=find(a), find(b)
	if roota!=rootb:
		if r[roota]>r[rootb]:
			p[rootb]=roota
			r[roota]+=1
		else:
			p[roota]=rootb
			r[rootb]+=1
for _ in range(II()):
	n, m, k=MI()
	g=[]
	d=1e10
	for __ in range(m):
		u, v, w=MI()
		g.append((w, u, v))
		if abs(w-k)<d:
			d=abs(w-k)
	g.sort()
	p, r=[i for i in range(n+1)], [1 for i in range(n+1)]
	ans=0
	for w, u, v in g:
		if find(u)!=find(v):
			merge(u, v)
			ans=max(0, w-k)
	print(ans if ans else d)