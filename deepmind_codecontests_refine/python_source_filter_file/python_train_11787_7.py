import sys
LI=lambda:list(map(int, sys.stdin.readline().strip('\n').split()))
MI=lambda:map(int, sys.stdin.readline().strip('\n').split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline().strip('\n'))

n=II()
a=sorted(LI())
mn=1
p=set([a[0]-1, a[0], a[0]+1])
for v in a[1:]:
	c=set([v-1, v, v+1])
	p=p.intersection(c)
	if not p:
		mn+=1
		p=c.copy()
ln=[0]*(n+2)
ln[0]=1
for v in a[1:]:
	if not ln[v-1]:
		ln[v-1]=1
	elif not ln[v]:
		ln[v]=1
	elif not ln[v+1]:
		ln[v+1]=1
print(mn, sum(ln))