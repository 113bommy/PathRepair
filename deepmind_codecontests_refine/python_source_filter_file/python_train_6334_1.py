import itertools
n,m=map(int,input().split())
a=list(map(int,input().split()))
s=[0]*(2*m+2)
tot=0
for l,r in zip(a,a[1:]):
	tot+=(r-l)%m
	if l>r:
		r+=m
	dif=r-l
	if dif>1:
		s[l+2]+=1
		s[r+1]-=dif
		s[r+2]+=dif-1
s=list(itertools.accumulate(list(itertools.accumulate(s))))
print(tot-max(s[i]+s[m+i] for i in range(1,m)))