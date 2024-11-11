import sys
import math
#sys.stdin = open('input.txt','r')
#sys.stdout = open('output.txt','w')


n = int(input())

a = [int(x) for x in input().split()]

output = []

for i in range(0,len(a)):
	j = i
	c = 1

	while(j > 0):
		if a[j-1] <= a[j]:
			c += 1
			j-=1
		else:
			break

	j = i
	while(j < n-1):
		if a[j] > a[j+1]:
			c += 1
			j+= 1
		else:
			break

	output.append(c)

print(max(output))