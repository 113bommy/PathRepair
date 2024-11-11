n,k=[int(x) for x in input().split()]
counter=n
while n>0:
	counter+=n//k
	n=n//k
print(counter)