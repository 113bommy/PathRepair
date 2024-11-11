N,*P=map(int,open(0))
ids=[0]*N
for i in range(N):
	ids[P[i]-1]=i
tmp=1
inc=1
for i in range(N-1):
	if ids[i]<ids[i+1]:
		tmp+=1
		inc=max(tmp,inc)
	else:
		tmp=1
print(N-tmp)