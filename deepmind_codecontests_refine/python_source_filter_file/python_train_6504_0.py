import sys, os
import fileinput
n = int(input()) + 1
a = [int(x) for x in input().split()]

all_count = 2 ** n - 1
b = [0] * all_count

counter = 0

for i in range(n, 1, -1):
	lcnt =  2 ** (i - 1)
	first = 2 ** (i - 1) - 2 
	#print(lcnt, first)
	level = a[first:first + lcnt]
	# print(level)

	for j in range(0, lcnt, 2):
		index = first + 2 + j

		if i == n:
			# print(i)
			# print("-" * 10)
			diff = abs(level[j] - level[j + 1])
			# print(j, level[j], level[j+1], diff)
			counter += diff
			# print(index//2 - 1, level[j] + level[j + 1] + diff)

			b[index//2 - 1] += level[j] + level[j + 1] + diff
			# print("=" * 10)
		else:
			# print(i)
			# print("*" * 10)
			# print(index)
			# print(b)
			# print(level)
			diff = abs(abs(b[index - 1]//2 + level[j]) - abs(b[index]//2 + level[j + 1]))
			counter += diff
			b[index//2 - 1] += b[index-1] + b[index] + level[j] + level[j + 1] + diff
			# print("+" * 10)

print(counter)
# print(b)