import sys
n = int(input())
a = list(map(int, input().split(' ')))

parity = 0
even, odd = 0, 0
for x in a:
	even += x // 2
	odd += x // 2
	if (x % 2) == 1:
		if (parity == 0):
			even += 1
		else:	
			odd += 1
	parity = 1 - parity
	print(even, odd)

#print(even, odd)
print(min(even, odd))
