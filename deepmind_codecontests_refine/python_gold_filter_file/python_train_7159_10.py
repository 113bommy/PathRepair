I=lambda:map(int,input().split())
N=0xfffff
n,q=I()
c=list(I())
Q=[]
R=range
for i in R(q):l,r=I();Q.append(l<<40|r<<20|i)
Q.sort()
A=[[]for i in R(N)]
for i in R(n):A[c[i]].append(i)
B=[0]*N
def P(i,x):
	i+=1
	while i<=n:B[i]+=x;i+=i&-i
for i in A:
	if i:P(i[0],1);i.reverse()
t=0
o=[0]*q
for x in Q:
	l=(x>>40)-1
	r=x>>20&N
	i=x&N
	while t<l:
		b=A[c[t]]
		P(b[-1],-1)
		b.pop()
		if b:P(b[-1],1)
		t+=1
	while r:o[i]+=B[r];r-=r&-r
	while l:o[i]-=B[l];l-=l&-l
for i in o:print(i)