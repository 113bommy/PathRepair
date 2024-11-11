import sys
LI=lambda:list(map(int,sys.stdin.readline().split()))
MI=lambda:map(int,sys.stdin.readline().split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline())

for _ in range(II()):
	n=II()
	a=LI()
	s=sorted(a)
	t1={}
	t2={}
	for i, v in enumerate(a):
		try:t1[v].append(i)
		except:t1[v]=[i]
	for i, v in enumerate(s):
		try:t2[v].append(i)
		except:t2[v]=[i]
	ok=1
	for v in t1:
		if abs(sum(c%2 for c in t1[v])-sum(c%2 for c in t2[v]))%2:ok=0
	print(['NO','YES'][ok])