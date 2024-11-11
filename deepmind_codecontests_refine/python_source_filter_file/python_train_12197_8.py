from math import*

k=int(input())
z=0
for i in range(5,int(sqrt(k))+1):
	if k%i==0:
		z=i
		break
	else:
		continue
if z==0 or (k//z)<5:
	print("-1")
else:
	print(z,k//z)
	x=["a","e","i","o","u"]
	for i in range(z):
		for j in range(k//z):
			print(x[(j+i)%5],end='')
						#unknown_2433