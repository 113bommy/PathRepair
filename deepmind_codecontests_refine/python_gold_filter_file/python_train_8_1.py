from math import *

n = int(input())

s = [int(i) for i in input()][:n]

# print(s)

ctr = 0

for i in s:
	ctr += 1 if i == 8 else 0
print(min(ctr,len(s)//11))