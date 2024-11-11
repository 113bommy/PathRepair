Modoneprime = []
import math

for i in range (1, 11110):
	count = 0
	k = 5*i + 1
	for j in range (2, math.floor(math.sqrt(k))):
		if k%j ==0:
			count+=1
	if count > 0:
		continue
	else:
		Modoneprime.append(k)

N = int(input())

print(*Modoneprime[0:N])