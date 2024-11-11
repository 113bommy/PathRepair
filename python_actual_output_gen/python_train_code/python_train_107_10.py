import math

def prime(a):
	if a==1:
		return 0
	n=2
	while n<math.sqrt(a):
		if a%n==0:
			return 0
		n+=1
	return 1

N=int(input())

count=0
for i in range(N):
	a=int(input())
	count+=prime(a)
print(count)