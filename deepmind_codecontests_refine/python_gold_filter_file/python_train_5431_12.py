'''input
4
4.58413
1.22491
-2.10517
-3.70387
'''
from sys import stdin
import collections
import math
import queue


# main starts
n = int(stdin.readline().strip())
original = []
after = []
for _ in range(n):
	num = float(stdin.readline().strip())
	original.append(num)
	after.append(math.floor(num))

if sum(after) == 0:
	for i in after:
		print(i)
	exit()

cur = sum(after)
i = 0
# print(cur)
while cur < 0 and i < n:
	if math.ceil(original[i]) > math.floor(original[i]):
		after[i] = math.ceil(original[i])
		cur += 1
	i += 1

for i in after:
	print(i)

