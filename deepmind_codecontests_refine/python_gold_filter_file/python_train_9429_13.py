'''input
5
1 5 3 2 4
'''
import itertools

n = int(input())

arr = sorted([int(i) for i in input().split()])

for i in range(n - 2):
	if arr[i + 2] < arr[i + 1] + arr[i]:
		print('YES')
		exit(0)

print('NO')
