import sys
from math import ceil
input = sys.stdin.buffer.readline
def I(): return(list(map(int,input().split())))
def sieve(n):
	a=[1]*n
	for i in range(2,n):
	    if a[i]:
	        for j in range(i*i,n,i):
	            a[j]=0
	return a
def calc(t):
	for i in range(1,k+1):
		if ceil(g[i]/t)>c[i]:return False
	return True

n,k=I()
g=[0]*(k+1)


ms=I()

for i in range(n):
	g[ms[i]]+=1
cs=g[:]
for i in reversed(range(1,k)):
	g[i]+=g[i+1]
c=I()
c=[0]+c
l=1
r=n
# print(g)
# print(cs)
ans=n
while(l<=r):
	mid=l+(r-l)//2
	if calc(mid):
		r=mid-1
		# print(mid)
		ans=min(ans,mid)
	else:
		l=mid+1

ms.sort()
print(ans)
test=[[] for i in range(ans)]
for i in range(len(ms)):
	test[i%ans].append(ms[i])
for i in test:
	print(len(i),*i)

# print(g)
# print(c)


tests=[]
# for j in nums:
# 	tests.extend([j]*(ceil(cs[j]/ans)))
# print(len(tests),*tests)


	



