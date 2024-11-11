n,k=map(int, input().split())
a=[int(x) for x in input().split()]
a.sort()
for i in a[::-1]:
	if k%i==0:
		print(k//i)
		exit(0)