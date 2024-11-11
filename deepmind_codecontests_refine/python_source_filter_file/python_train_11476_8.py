n,modulo=[int(x) for x in input().split()]
array=sorted([int(x) for x in input().split()])
if n<modulo:
	total=1
	for i in range(n-1):
		for j in range(i+1,n):
			total*=(array[j]%modulo-array[i]%modulo)%modulo
			total=total%modulo
	print(total%modulo)
else:
	print(0)