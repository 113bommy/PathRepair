n=int(input())
a=[int(x) for x in input().split()]
b=[int(x) for x in input()]
z=[0]*4
o=[1]*4

k=100000000
l=-k
r=k

for i in range(5,n):
	a1=a[i-5:i]
	b1=b[i-4:i]
	if b1==o and b[i]==0:
		t=min(a1)
		r=min(r,t-1)

	elif b1==z and b[i]==1:
		t=max(a1)
		l=max(l,t+1)
print(l,r)

