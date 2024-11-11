import math

n=int(input())

for i in range(n):
	k=int(input())
	s=k
	if(k<10):
		print(k)
	if (k%9==0):
	 print(k+math.floor(k/9)-1)
	else:
		print(k + math.floor(k / 9) )


