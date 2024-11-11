x=int(input())
a=[0]*x
k=0
t=0
for i in range(11,55555,10):
	t=0
	for j in range (2,round(i**0.5)):
		if i%j==0:
			t=1
	if t==0 and k<x:
		a[k]=i
		k=k+1
print(*a)