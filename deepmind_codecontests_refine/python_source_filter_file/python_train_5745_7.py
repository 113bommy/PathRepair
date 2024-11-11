from sys import stdin
def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
for _ in range(ii()):
	p=0
	n, m, k=mi()
	a=li()
	for i in range(n-1):
		x=max(0, a[i+1]-m)
		if a[i]<x:
			k-=x-a[i]
			if k<0:
				p=1
				break
		else:
			k+=a[i]-x
	print(['YES', 'NO'][p])