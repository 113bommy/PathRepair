import math
def isprime(x):
	if x<2:
		return 0
	for i in range(1,int(math.sqrt(x)+1)):
		if x%i==0:
			return 0
	return 1
a=int(input())
if isprime(a)==1:
	print(1)
elif a%2==0:
	print(2)
elif isprime(a-2):
	print(2)
else:
	print(3)