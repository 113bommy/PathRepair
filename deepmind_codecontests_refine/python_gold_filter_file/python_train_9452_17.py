(N,M,P),*E=[list(map(int,s.split()))for s in open(0)]
D=[0]*2+[-9e9]*N
def f():
	for _ in D:
		for a,b,c in E:D[b]=max(D[b],D[a]+c-P)
f()
s=D[N]
f()
print([max(s,0),-1][s<D[N]])