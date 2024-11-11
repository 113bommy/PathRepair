d,g=[int(_) for _ in input().split()]
l=[0]+[list(map(int,input().split())) for _ in  range(d)]
print(l)
def f(i,g):
	if i==0:return 10**9
	c=min(g//(100*i),l[i][0])
	s=100*i*c
	if c==l[i][0]:s+=l[i][1]
	if s<g:
		c+=f(i-1,g-s)
	return min(c,f(i-1,g))
print(f(d,g))