powersoftwo=[2**i for i in range(1,34)]
N=int(input())
array=[int(x) for x in input().split()]
checker=set(array)
total=-1
for i in array:
	for j in powersoftwo:
		z=1
		a=1
		b=1
		if i-j in checker:
			z+=1
			a+=1
		if j+i in checker:
			z+=1
			b+=1
		total=max(z,total)
		if total==z:
			if a==2:
				something=[i, i-j]
			if b==2:
				something=[i,i+j]
			if a==2 and b==2:
				something=[i,i+j,i-j]
print(total)
if total>1:
	print(*something)
else:
	print(array[0])